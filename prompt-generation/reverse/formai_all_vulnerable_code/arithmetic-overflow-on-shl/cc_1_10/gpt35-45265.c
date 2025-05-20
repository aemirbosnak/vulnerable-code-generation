//FormAI DATASET v1.0 Category: Bitwise operations ; Style: minimalist
#include <stdio.h>

// Bitwise function to print the binary representation of an integer number
void printBinary(int n) {
    for(int i = 31; i >= 0; i--) {
        if(n & (1 << i))
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}

int main() {
    unsigned int a = 60;  // 60 = 0011 1100
    unsigned int b = 13;  // 13 = 0000 1101

    // Bitwise AND operation
    printf("AND operation:\n");
    printBinary(a);        // 0011 1100
    printBinary(b);        // 0000 1101
    printf("---------------\n");
    printBinary(a & b);    // 0000 1100

    // Bitwise OR operation
    printf("OR operation:\n");
    printBinary(a);        // 0011 1100
    printBinary(b);        // 0000 1101
    printf("---------------\n");
    printBinary(a | b);    // 0011 1101

    // Bitwise XOR operation
    printf("XOR operation:\n");
    printBinary(a);        // 0011 1100
    printBinary(b);        // 0000 1101
    printf("---------------\n");
    printBinary(a ^ b);    // 0011 0001

    // Bitwise NOT operation
    printf("NOT operation:\n");
    printBinary(a);        // 0011 1100
    printf("---------------\n");
    printBinary(~a);       // 1100 0011

    // Bitwise left shift operation
    printf("Left shift operation:\n");
    printBinary(a);        // 0011 1100
    printf("---------------\n");
    printBinary(a << 2);   // 1111 0000

    // Bitwise right shift operation
    printf("Right shift operation:\n");
    printBinary(a);        // 0011 1100
    printf("---------------\n");
    printBinary(a >> 2);   // 0000 1111

    return 0;
}