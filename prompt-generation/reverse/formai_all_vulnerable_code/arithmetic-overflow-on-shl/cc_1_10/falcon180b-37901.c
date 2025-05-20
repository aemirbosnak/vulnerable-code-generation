//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: configurable
#include <stdio.h>

#define NUM_BITS 32
#define NUM_WORDS 4

void print_bits(unsigned int num) {
    char *bits = "00000000000000000000000000000000";
    int i;
    for (i = NUM_BITS - 1; i >= 0; i--) {
        if (num & (1 << i)) {
            bits[i] = '1';
        } else {
            bits[i] = '0';
        }
    }
    printf("%s\n", bits);
}

int main() {
    unsigned int num1 = 0x12345678;
    unsigned int num2 = 0x87654321;
    unsigned int result;

    // Bitwise AND
    result = num1 & num2;
    printf("Bitwise AND: ");
    print_bits(result);

    // Bitwise OR
    result = num1 | num2;
    printf("Bitwise OR: ");
    print_bits(result);

    // Bitwise XOR
    result = num1 ^ num2;
    printf("Bitwise XOR: ");
    print_bits(result);

    // Bitwise NOT
    result = ~num1;
    printf("Bitwise NOT: ");
    print_bits(result);

    // Left Shift
    result = num1 << 4;
    printf("Left Shift by 4: ");
    print_bits(result);

    // Right Shift
    result = num1 >> 4;
    printf("Right Shift by 4: ");
    print_bits(result);

    // Bitwise AND with a mask
    result = num1 & 0x0F;
    printf("Bitwise AND with a mask: ");
    print_bits(result);

    // Bitwise OR with a mask
    result = num1 | 0x0F;
    printf("Bitwise OR with a mask: ");
    print_bits(result);

    // Bitwise XOR with a mask
    result = num1 ^ 0x0F;
    printf("Bitwise XOR with a mask: ");
    print_bits(result);

    // Bitwise NOT with a mask
    result = ~num1 & 0x0F;
    printf("Bitwise NOT with a mask: ");
    print_bits(result);

    return 0;
}