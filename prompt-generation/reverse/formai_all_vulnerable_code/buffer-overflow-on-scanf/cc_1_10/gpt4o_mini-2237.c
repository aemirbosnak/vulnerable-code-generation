//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: detailed
#include <stdio.h>

// Function to print binary representation of a number
void printBinary(unsigned int n) {
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        if (n & (1 << i))
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}

// Function to perform bitwise AND operation
unsigned int bitwiseAND(unsigned int a, unsigned int b) {
    return a & b;
}

// Function to perform bitwise OR operation
unsigned int bitwiseOR(unsigned int a, unsigned int b) {
    return a | b;
}

// Function to perform bitwise XOR operation
unsigned int bitwiseXOR(unsigned int a, unsigned int b) {
    return a ^ b;
}

// Function to perform bitwise NOT operation
unsigned int bitwiseNOT(unsigned int a) {
    return ~a;
}

// Function to perform left shift operation
unsigned int leftShift(unsigned int a, int shift) {
    return a << shift;
}

// Function to perform right shift operation
unsigned int rightShift(unsigned int a, int shift) {
    return a >> shift;
}

// Function to demonstrate all bitwise operations
void demonstrateBitwiseOperations(unsigned int a, unsigned int b) {
    printf("Number A: %d (Binary: ", a);
    printBinary(a);
    printf("Number B: %d (Binary: ", b);
    printBinary(b);

    // Bitwise AND
    unsigned int andResult = bitwiseAND(a, b);
    printf("A & B = %d (Binary: ", andResult);
    printBinary(andResult);

    // Bitwise OR
    unsigned int orResult = bitwiseOR(a, b);
    printf("A | B = %d (Binary: ", orResult);
    printBinary(orResult);

    // Bitwise XOR
    unsigned int xorResult = bitwiseXOR(a, b);
    printf("A ^ B = %d (Binary: ", xorResult);
    printBinary(xorResult);

    // Bitwise NOT
    unsigned int notAResult = bitwiseNOT(a);
    printf("~A = %d (Binary: ", notAResult);
    printBinary(notAResult);

    unsigned int notBResult = bitwiseNOT(b);
    printf("~B = %d (Binary: ", notBResult);
    printBinary(notBResult);

    // Left Shift
    int shiftLeft = 2;
    unsigned int leftShiftResult = leftShift(a, shiftLeft);
    printf("A << %d = %d (Binary: ", shiftLeft, leftShiftResult);
    printBinary(leftShiftResult);

    // Right Shift
    int shiftRight = 2;
    unsigned int rightShiftResult = rightShift(a, shiftRight);
    printf("A >> %d = %d (Binary: ", shiftRight, rightShiftResult);
    printBinary(rightShiftResult);
}

int main() {
    unsigned int num1, num2;

    // Input numbers
    printf("Enter first number: ");
    scanf("%u", &num1);
    printf("Enter second number: ");
    scanf("%u", &num2);

    // Demonstrating bitwise operations
    demonstrateBitwiseOperations(num1, num2);

    return 0;
}