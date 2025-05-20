//FormAI DATASET v1.0 Category: Bitwise operations ; Style: interoperable
#include <stdio.h>

// Function to print binary representation of a number
void printBinary(int num) {
    // Start from the leftmost bit and print the bits in reverse order
    for(int i = 31; i >= 0; i--) {
        int mask = 1 << i;
        // Print 1 or 0 depending on the bit value
        putchar(num & mask ? '1' : '0');
    }
    putchar('\n');
}

int main() {
    unsigned int a = 8; // 1000 in binary
    unsigned int b = 6; // 0110 in binary

    printf("a       = ");
    printBinary(a);
    printf("b       = ");
    printBinary(b);

    unsigned int c = a & b; // AND operation
    printf("a & b   = ");
    printBinary(c);

    unsigned int d = a | b; // OR operation
    printf("a | b   = ");
    printBinary(d);

    unsigned int e = a ^ b; // XOR operation
    printf("a ^ b   = ");
    printBinary(e);

    unsigned int f = ~a; // NOT operation
    printf("~a      = ");
    printBinary(f);

    unsigned int g = a << 1; // Left shift operation
    printf("a << 1  = ");
    printBinary(g);

    unsigned int h = b >> 1; // Right shift operation
    printf("b >> 1  = ");
    printBinary(h);

    unsigned int i = a >> 2; // Right shift with sign extension
    printf("a >> 2  = ");
    printBinary(i);

    unsigned int j = b << 2; // Left shift with overflow
    printf("b << 2 (overflow) = ");
    printBinary(j);

    return 0;
}