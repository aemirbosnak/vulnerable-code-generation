#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int key = 0xdeadbeef;
    int data = 0x12345678;
    int result = 0;

    // Overflow the int variable
    key = key + 1;
    data = data * key;

    // Calculate the encrypted data
    result = data ^ key;

    // Print the encrypted data
    printf("Encrypted data: %x\n", result);

    return 0;
}
