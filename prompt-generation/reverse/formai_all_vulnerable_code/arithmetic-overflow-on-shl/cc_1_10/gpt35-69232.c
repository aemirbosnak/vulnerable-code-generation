//FormAI DATASET v1.0 Category: Bitwise operations ; Style: complete
#include <stdio.h>

#define BITS_PER_BYTE 8

// Function to convert decimal to binary
void decimalToBinary(unsigned int num)
{
    if(num)
    {
        decimalToBinary(num/2);
        printf("%d", num % 2);
    }
}

int main()
{
    unsigned int a = 60;   // Binary value: 0011 1100
    unsigned int b = 13;   // Binary value: 0000 1101

    // Bitwise AND
    printf("a & b = %u\n", a & b);   // Output: 12 (Binary value: 0000 1100)

    // Bitwise OR
    printf("a | b = %u\n", a | b);   // Output: 61 (Binary value: 0011 1101)

    // Bitwise XOR
    printf("a ^ b = %u\n", a ^ b);   // Output: 49 (Binary value: 0011 0001)

    // Bitwise NOT (Unary)
    printf("~a = %u\n", ~a);         // Output: 4294967235 (Binary value: 1111 1111 1111 1111 1111 1111 1100 0011)

    // Bitwise LEFT SHIFT
    printf("a << 2 = %u\n", a << 2); // Output: 240 (Binary value: 1111 0000)

    // Bitwise RIGHT SHIFT
    printf("a >> 2 = %u\n", a >> 2); // Output: 15 (Binary value: 0000 1111)

    // Bitwise rotation to left
    unsigned int numBits = sizeof(a) * BITS_PER_BYTE;
    unsigned int shift = 1;
    unsigned int mask = ((1 << shift) - 1) << (numBits - shift);
    unsigned int newBit = (a >> (numBits - shift)) & 1;
    a = (a << shift) & ~mask | newBit << (numBits - shift);
    printf("a rotated left by %u bits = %u\n", shift, a); // Output: 120 (Binary value: 0111 1000)

    // Bitwise rotation to right
    mask = ((1 << shift) - 1);
    newBit = a & 1;
    a = (a >> shift) & ~mask | newBit << (numBits - shift);
    printf("a rotated right by %u bits = %u\n", shift, a); // Output: 60 (Binary value: 0011 1100)

    // Decimal to binary conversion
    printf("Decimal %u in binary: ", a);
    decimalToBinary(a);             // Output: 0011 1100

    return 0;
}