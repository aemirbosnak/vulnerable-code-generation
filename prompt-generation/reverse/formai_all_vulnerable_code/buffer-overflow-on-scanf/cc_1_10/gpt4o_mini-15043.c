//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Function to print binary representation of a number
void printBinary(unsigned int num) {
    for(int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

// Function to demonstrate bitwise operations
void bitwiseOperationsExample(unsigned int a, unsigned int b) {
    unsigned int andResult = a & b;
    unsigned int orResult = a | b;
    unsigned int xorResult = a ^ b;
    unsigned int notA = ~a;
    unsigned int notB = ~b;
    unsigned int leftShiftA = a << 1;
    unsigned int leftShiftB = b << 1;
    unsigned int rightShiftA = a >> 1;
    unsigned int rightShiftB = b >> 1;

    printf("\nBitwise Operations:\n");
    printf("A: ");
    printBinary(a);
    printf("\nB: ");
    printBinary(b);
    printf("\nA & B: ");
    printBinary(andResult);
    printf("\nA | B: ");
    printBinary(orResult);
    printf("\nA ^ B: ");
    printBinary(xorResult);
    printf("\n~A: ");
    printBinary(notA);
    printf("\n~B: ");
    printBinary(notB);
    printf("\nA << 1: ");
    printBinary(leftShiftA);
    printf("\nB << 1: ");
    printBinary(leftShiftB);
    printf("\nA >> 1: ");
    printBinary(rightShiftA);
    printf("\nB >> 1: ");
    printBinary(rightShiftB);
    printf("\n");
}

int main() {
    unsigned int x, y;

    // Prompt user for input
    printf("Enter two positive integers:\n");
    printf("Integer X: ");
    scanf("%u", &x);
    printf("Integer Y: ");
    scanf("%u", &y);

    // Display the bitwise operations
    bitwiseOperationsExample(x, y);

    // Additional examples with fixed values
    printf("Demonstrating Fixed Values (17 and 22):\n");
    bitwiseOperationsExample(17, 22);

    // Creating a pattern with bitwise manipulation
    unsigned int pattern = 0xAA; // 10101010 in binary
    printf("\nBit pattern manipulations (0xAA):\n");
    printf("Original pattern: ");
    printBinary(pattern);
    printf("\nReversed pattern: ");
    pattern = ~pattern;
    printBinary(pattern);

    // Resetting the pattern and shifting
    pattern = 0x1F; // 00011111
    printf("\n\nBit pattern shifting (0x1F):\n");
    printf("Original pattern: ");
    printBinary(pattern);
    pattern = pattern << 2;
    printf("\nShift Left by 2: ");
    printBinary(pattern);
    pattern = pattern >> 3;
    printf("\nShift Right by 3: ");
    printBinary(pattern);

    // Creating a mask and applying it
    unsigned int mask = 0x0F; // 00001111
    printf("\n\nApplying a Mask (0x0F):\n");
    unsigned int result = x & mask;
    printf("Original X: ");
    printBinary(x);
    printf("\nMask: ");
    printBinary(mask);
    printf("\nResult of X & Mask: ");
    printBinary(result);
    
    // Ending message
    printf("\nThank you for exploring bitwise operations!\n");
    return 0;
}