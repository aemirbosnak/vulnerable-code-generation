//FormAI DATASET v1.0 Category: Bitwise operations ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// This is a program to demonstrate bitwise operations in C, and it's going to be awesome!

int main() {
    // First, let's declare the variables we're going to use
    int x = 10;  // Binary: 1010
    int y = 5;   // Binary: 0101
    int z;

    // Now, let's perform some bitwise operations and print the results
    printf("x = %d (%d in binary)\n", x, x);
    printf("y = %d (%d in binary)\n", y, y);

    // Bitwise AND
    z = x & y;  // Result: Binary 0000 (decimal 0)
    printf("x & y = %d (%d in binary)\n", z, z);

    // Bitwise OR
    z = x | y;  // Result: Binary 1111 (decimal 15)
    printf("x | y = %d (%d in binary)\n", z, z);

    // Bitwise XOR
    z = x ^ y;  // Result: Binary 1111 (decimal 15)
    printf("x ^ y = %d (%d in binary)\n", z, z);

    // Bitwise NOT
    z = ~x;     // Result: Binary 0101 (decimal 5, two's complement)
    printf("~x = %d (%d in binary)\n", z, z);

    // Left shift
    z = x << 1; // Result: Binary 10100 (decimal 20)
    printf("x << 1 = %d (%d in binary)\n", z, z);

    // Right shift
    z = y >> 1; // Result: Binary 0010 (decimal 2)
    printf("y >> 1 = %d (%d in binary)\n", z, z);

    // Let's make it more interesting, we'll prompt the user for input
    printf("\nNow it's your turn! Enter a number: ");
    scanf("%d", &x);
    printf("You entered %d (%d in binary)\n", x, x);

    // Bitwise AND with a constant
    z = x & 0x0F;  // Keep only the lower 4 bits
    printf("%d & 0x0F = %d (%d in binary)\n", x, z, z);

    // Bitwise OR with a constant
    z = x | 0x80;  // Set the most significant bit to 1
    printf("%d | 0x80 = %d (%d in binary)\n", x, z, z);

    // Bitwise XOR with a constant
    z = x ^ 0xFF;  // Invert all bits
    printf("%d ^ 0xFF = %d (%d in binary)\n", x, z, z);

    // Left shift by a variable amount
    int shift;
    printf("Enter a number of positions to shift left: ");
    scanf("%d", &shift);
    z = x << shift;
    printf("%d << %d = %d (%d in binary)\n", x, shift, z, z);

    // Right shift by a variable amount
    printf("Enter a number of positions to shift right: ");
    scanf("%d", &shift);
    z = x >> shift;
    printf("%d >> %d = %d (%d in binary)\n", x, shift, z, z);

    // And that's it! Wasn't that fun? Bitwise operations are a powerful tool in C programming.
    return 0;
}