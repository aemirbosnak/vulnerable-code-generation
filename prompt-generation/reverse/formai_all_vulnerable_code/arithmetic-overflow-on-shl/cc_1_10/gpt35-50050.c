//FormAI DATASET v1.0 Category: Bitwise operations ; Style: safe
#include <stdio.h>

// Function to display binary representation of a number
void printBinary(unsigned int num) {
    // size of an integer is assumed to be 32 bits
    for (int i = 31; i >= 0; i--) {
        if (num & (1 << i))
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}

int main() {
    unsigned int a = 10, b = 7;

    printf("Binary representation of %u: ", a);
    printBinary(a);
    printf("Binary representation of %u: ", b);
    printBinary(b);

    // Bitwise AND operator: sets each bit to 1 if both bits are 1
    unsigned int c = a & b;
    printf("a & b = %u\n", c);
    printf("Binary representation of %u: ", c);
    printBinary(c);

    // Bitwise OR operator: sets each bit to 1 if at least one bit is 1
    unsigned int d = a | b;
    printf("a | b = %u\n", d);
    printf("Binary representation of %u: ", d);
    printBinary(d);

    // Bitwise XOR operator: sets each bit to 1 if only one bit is 1
    unsigned int e = a ^ b;
    printf("a ^ b = %u\n", e);
    printf("Binary representation of %u: ", e);
    printBinary(e);

    // Bitwise NOT operator: inverts all the bits
    unsigned int f = ~a;
    printf("~a = %u\n", f);
    printf("Binary representation of %u: ", f);
    printBinary(f);

    // Bitwise left shift operator: shifts all the bits to the left by n positions
    unsigned int g = a << 2;
    printf("a << 2 = %u\n", g);
    printf("Binary representation of %u: ", g);
    printBinary(g);

    // Bitwise right shift operator: shifts all the bits to the right by n positions
    unsigned int h = a >> 2;
    printf("a >> 2 = %u\n", h);
    printf("Binary representation of %u: ", h);
    printBinary(h);

    return 0;
}