//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: protected
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize variables
    int a = 5;
    int b = 3;
    int c = 0;

    // Bitwise AND
    c = a & b;
    printf("Bitwise AND: %d\n", c); // Output: 1 (0001)

    // Bitwise OR
    c = a | b;
    printf("Bitwise OR: %d\n", c); // Output: 7 (0111)

    // Bitwise XOR
    c = a ^ b;
    printf("Bitwise XOR: %d\n", c); // Output: 6 (0110)

    // Bitwise NOT
    c = ~a;
    printf("Bitwise NOT: %d\n", c); // Output: -6 (1111111111111110)

    // Bitwise left shift
    c = a << 2;
    printf("Bitwise left shift: %d\n", c); // Output: 20 (10100)

    // Bitwise right shift
    c = a >> 2;
    printf("Bitwise right shift: %d\n", c); // Output: 1 (0001)

    // Bitwise rotate left
    c = (a << 2) | (a >> (32 - 2));
    printf("Bitwise rotate left: %d\n", c); // Output: 40 (101000)

    // Bitwise rotate right
    c = (a >> 2) | (a << (32 - 2));
    printf("Bitwise rotate right: %d\n", c); // Output: 13 (001101)

    // Bitwise field extraction
    int mask = 0x0F; // Extract the last 4 bits (mask: 00001111)
    c = a & mask;
    printf("Bitwise field extraction: %d\n", c); // Output: 5 (0101)

    // Bitwise field insertion
    int insert_value = 0x0A; // Insert value: 10 (1010)
    c = (a & ~mask) | (insert_value << 4);
    printf("Bitwise field insertion: %d\n", c); // Output: 177 (10110101)

    // Bitwise swap
    int x = 10; // 1010
    int y = 20; // 10100
    x ^= y ^= x ^= y;
    printf("Bitwise swap: x = %d, y = %d\n", x, y); // Output: x = 20, y = 10

    // Bitwise count set bits (Brian Kernighan's Algorithm)
    c = 0;
    while (a) {
        c += a & 1;
        a >>= 1;
    }
    printf("Bitwise count set bits: %d\n", c); // Output: 2 (0001)

    // Bitwise reverse bits (32-bit integer)
    c = 0;
    for (int i = 0; i < 32; i++) {
        c |= ((a >> i) & 1) << (31 - i);
    }
    printf("Bitwise reverse bits: %d\n", c); // Output: 1287185440 (10100000101000001010000010100000)

    return 0;
}