//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function to display the binary representation of an integer
void printBinary(int num) {
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) {
            printf(" "); // Add space for better readability
        }
    }
    printf("\n");
}

// Function to perform bitwise AND
int bitwiseAnd(int a, int b) {
    return a & b;
}

// Function to perform bitwise OR
int bitwiseOr(int a, int b) {
    return a | b;
}

// Function to perform bitwise XOR
int bitwiseXor(int a, int b) {
    return a ^ b;
}

// Function to perform bitwise NOT
int bitwiseNot(int a) {
    return ~a;
}

// Function to shift bits left
int shiftLeft(int a, int positions) {
    return a << positions;
}

// Function to shift bits right
int shiftRight(int a, int positions) {
    return a >> positions;
}

// Function to demonstrate bitwise operations
void demoBitwiseOperations() {
    int a, b;

    printf("Enter two integers:\n");
    scanf("%d %d", &a, &b);

    printf("\nBitwise Operations:\n");

    printf("a: %d\n", a);
    printf("b: %d\n", b);

    printf("Binary representation of a: ");
    printBinary(a);

    printf("Binary representation of b: ");
    printBinary(b);

    printf("a AND b: %d\n", bitwiseAnd(a, b));
    printf("Binary: ");
    printBinary(bitwiseAnd(a, b));

    printf("a OR b: %d\n", bitwiseOr(a, b));
    printf("Binary: ");
    printBinary(bitwiseOr(a, b));

    printf("a XOR b: %d\n", bitwiseXor(a, b));
    printf("Binary: ");
    printBinary(bitwiseXor(a, b));
    
    printf("NOT a: %d\n", bitwiseNot(a));
    printf("Binary: ");
    printBinary(bitwiseNot(a));

    printf("NOT b: %d\n", bitwiseNot(b));
    printf("Binary: ");
    printBinary(bitwiseNot(b));

    int leftShiftAmount, rightShiftAmount;
    
    printf("Enter number of positions to shift left: ");
    scanf("%d", &leftShiftAmount);
    printf("a shifted left by %d: %d\n", leftShiftAmount, shiftLeft(a, leftShiftAmount));
    printf("Binary: ");
    printBinary(shiftLeft(a, leftShiftAmount));

    printf("Enter number of positions to shift right: ");
    scanf("%d", &rightShiftAmount);
    printf("a shifted right by %d: %d\n", rightShiftAmount, shiftRight(a, rightShiftAmount));
    printf("Binary: ");
    printBinary(shiftRight(a, rightShiftAmount));
}

// Main function
int main() {
    printf("Bitwise Operations Demonstration\n");
    demoBitwiseOperations();
    return 0;
}