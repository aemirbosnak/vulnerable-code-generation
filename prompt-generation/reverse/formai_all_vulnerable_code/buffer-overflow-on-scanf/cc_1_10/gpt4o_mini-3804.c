//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Function to display binary representation of a number
void displayBinary(unsigned int num) {
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        if (num & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

// Function to perform bitwise AND and display result in binary
void bitwiseAnd(unsigned int a, unsigned int b) {
    unsigned int result = a & b;
    printf("Bitwise AND of ");
    displayBinary(a);
    printf("and ");
    displayBinary(b);
    printf("is ");
    displayBinary(result);
}

// Function to perform bitwise OR and display result in binary
void bitwiseOr(unsigned int a, unsigned int b) {
    unsigned int result = a | b;
    printf("Bitwise OR of ");
    displayBinary(a);
    printf("and ");
    displayBinary(b);
    printf("is ");
    displayBinary(result);
}

// Function to perform bitwise XOR and display result in binary
void bitwiseXor(unsigned int a, unsigned int b) {
    unsigned int result = a ^ b;
    printf("Bitwise XOR of ");
    displayBinary(a);
    printf("and ");
    displayBinary(b);
    printf("is ");
    displayBinary(result);
}

// Function to perform bitwise NOT and display result in binary
void bitwiseNot(unsigned int a) {
    unsigned int result = ~a;
    printf("Bitwise NOT of ");
    displayBinary(a);
    printf("is ");
    displayBinary(result);
}

// Function to perform left shift and display result in binary
void leftShift(unsigned int a, int shift) {
    unsigned int result = a << shift;
    printf("Left shift %d of ", shift);
    displayBinary(a);
    printf("is ");
    displayBinary(result);
}

// Function to perform right shift and display result in binary
void rightShift(unsigned int a, int shift) {
    unsigned int result = a >> shift;
    printf("Right shift %d of ", shift);
    displayBinary(a);
    printf("is ");
    displayBinary(result);
}

// Function to demonstrate all bitwise operations
void demonstrateBitwiseOperations(unsigned int a, unsigned int b) {
    printf("Original numbers:\n");
    printf("A: ");
    displayBinary(a);
    printf("B: ");
    displayBinary(b);
    printf("\n");

    bitwiseAnd(a, b);
    printf("\n");
    
    bitwiseOr(a, b);
    printf("\n");

    bitwiseXor(a, b);
    printf("\n");

    bitwiseNot(a);
    printf("\n");

    bitwiseNot(b);
    printf("\n");

    leftShift(a, 2);
    printf("\n");

    rightShift(a, 2);
    printf("\n");
}

// Main function to encapsulate user input and function calls
int main() {
    unsigned int a, b;

    printf("Enter two positive integers:\n");
    printf("A: ");
    scanf("%u", &a);
    printf("B: ");
    scanf("%u", &b);

    demonstrateBitwiseOperations(a, b);
    
    return 0;
}