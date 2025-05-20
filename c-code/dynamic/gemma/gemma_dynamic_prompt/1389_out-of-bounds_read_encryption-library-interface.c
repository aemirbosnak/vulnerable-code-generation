#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int key[] = {0x12, 0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde, 0xf0};
    int offset = 0x10;
    int data = 0xdeadbeef;

    // Accessing memory beyond the key array bounds
    key[offset] = data;

    printf("Key after out-of-bounds access: %x\n", key[offset]);

    return 0;
}
