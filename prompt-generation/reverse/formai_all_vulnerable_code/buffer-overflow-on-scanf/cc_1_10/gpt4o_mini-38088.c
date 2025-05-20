//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: automated
#include <stdio.h>

#define MAX_BITS 32

// Function to print the binary representation of a number
void printBinary(unsigned int n) {
    for (int i = MAX_BITS - 1; i >= 0; i--) {
        if (n & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

// Function to perform a bitwise AND operation
unsigned int bitwiseAnd(unsigned int a, unsigned int b) {
    return a & b;
}

// Function to perform a bitwise OR operation
unsigned int bitwiseOr(unsigned int a, unsigned int b) {
    return a | b;
}

// Function to perform a bitwise XOR operation
unsigned int bitwiseXor(unsigned int a, unsigned int b) {
    return a ^ b;
}

// Function to perform bitwise NOT operation
unsigned int bitwiseNot(unsigned int a) {
    return ~a;
}

// Function to left shift a number
unsigned int leftShift(unsigned int a, unsigned int num) {
    return a << num;
}

// Function to right shift a number
unsigned int rightShift(unsigned int a, unsigned int num) {
    return a >> num;
}

// Function to demonstrate various bitwise operations
void demonstrateBitwiseOperations(unsigned int a, unsigned int b) {
    printf("a = %u, b = %u\n", a, b);
    
    printf("Binary representations:\n");
    printf("a: ");
    printBinary(a);
    printf("b: ");
    printBinary(b);
    
    printf("Bitwise AND (a & b): ");
    unsigned int andResult = bitwiseAnd(a, b);
    printBinary(andResult);
    
    printf("Bitwise OR (a | b): ");
    unsigned int orResult = bitwiseOr(a, b);
    printBinary(orResult);
    
    printf("Bitwise XOR (a ^ b): ");
    unsigned int xorResult = bitwiseXor(a, b);
    printBinary(xorResult);
    
    printf("Bitwise NOT (~a): ");
    unsigned int notResultA = bitwiseNot(a);
    printBinary(notResultA);
    
    printf("Bitwise NOT (~b): ");
    unsigned int notResultB = bitwiseNot(b);
    printBinary(notResultB);
    
    printf("Left Shift a << 1: ");
    unsigned int leftShiftResult = leftShift(a, 1);
    printBinary(leftShiftResult);
    
    printf("Right Shift a >> 1: ");
    unsigned int rightShiftResult = rightShift(a, 1);
    printBinary(rightShiftResult);
}

// Function to get user input and perform bitwise operations
void getUserInputAndDemonstrate() {
    unsigned int a, b;

    printf("Enter two positive integers:\n");
    
    printf("Enter first integer (a): ");
    scanf("%u", &a);
    
    printf("Enter second integer (b): ");
    scanf("%u", &b);

    demonstrateBitwiseOperations(a, b);
}

int main() {
    printf("Bitwise Operations Demonstration\n");
    printf("===============================\n");

    // Demonstrate bitwise operations on user input
    getUserInputAndDemonstrate();

    return 0;
}