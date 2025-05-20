//FormAI DATASET v1.0 Category: Bitwise operations ; Style: mathematical
#include <stdio.h>

int main() {
    int a = 143;          // Binary value: 10001111
    int b = 76;           // Binary value: 01001100
    int c;                // Variable to hold the result
    int i;                // Loop counter variable

    printf("a = %d (binary: %d)\n", a, toBinary(a));
    printf("b = %d (binary: %d)\n", b, toBinary(b));

    // Use bitwise AND operator
    c = a & b;

    printf("a & b = %d (binary: %d)\n", c, toBinary(c));

    // Use bitwise OR operator
    c = a | b;

    printf("a | b = %d (binary: %d)\n", c, toBinary(c));

    // Use bitwise NOT operator
    c = ~a;

    printf("~a = %d (binary: %d)\n", c, toBinary(c));

    // Use bitwise XOR operator
    c = a ^ b;

    printf("a ^ b = %d (binary: %d)\n", c, toBinary(c));

    // Use left shift operator
    c = a << 3;

    printf("a << 3 = %d (binary: %d)\n", c, toBinary(c));

    // Use right shift operator
    c = a >> 2;

    printf("a >> 2 = %d (binary: %d)\n", c, toBinary(c));

    // Use bit manipulation in a loop
    for(i = 0; i < 8; i++) {
        printf("Bit %d in a is %d\n", i, (a >> i) & 1);
    }

    return 0;
}

// Function to convert integer to binary
int toBinary(int decimal) {
    int binary = 0, base = 1;

    while(decimal > 0) {
        binary += (decimal % 2) * base;
        decimal /= 2;
        base *= 10;
    }

    return binary;
}