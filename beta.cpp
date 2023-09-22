#include <stdint.h>
#include <stdio.h>

static inline uintptr_t align_up(uintptr_t sz, size_t alignment)
{
    uintptr_t mask = alignment - 1;
    // save all bits of ( sz + mask ) besides bit 0 and bit 1
    // because mask is 0x3 if alignment is 0x4

    // linux kernel source code 
    // https://github.com/torvalds/linux/blob/master/tools/firmware/ihex2fw.c
    // line 24 and line 25
    if ((alignment & mask) == 0) {  /* power of two? */
        return ( sz + mask ) & ( ~mask ); 
    }
    return (((sz + mask) / alignment) * alignment);
}

int main(void) {
    printf( "%u\n", (unsigned int)align_up( 120, 4 ) );
    printf( "%u\n", (unsigned int)align_up( 121, 4 ) );
    printf( "%u\n", (unsigned int)align_up( 122, 4 ) );
    printf( "%u\n", (unsigned int)align_up( 123, 4 ) );
} // int