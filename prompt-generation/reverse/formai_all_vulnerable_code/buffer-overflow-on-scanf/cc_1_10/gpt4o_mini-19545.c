//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: beginner-friendly
#include <stdio.h>

// Function to display bits of an integer
void displayBits(unsigned int num) {
    printf("Bits: ");
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

// Function to perform bitwise AND
void bitwiseAnd(unsigned int a, unsigned int b) {
    unsigned int result = a & b;
    printf("Bitwise AND of ");
    displayBits(a);
    printf("and ");
    displayBits(b);
    printf("is: ");
    displayBits(result);
}

// Function to perform bitwise OR
void bitwiseOr(unsigned int a, unsigned int b) {
    unsigned int result = a | b;
    printf("Bitwise OR of ");
    displayBits(a);
    printf("and ");
    displayBits(b);
    printf("is: ");
    displayBits(result);
}

// Function to perform bitwise XOR
void bitwiseXor(unsigned int a, unsigned int b) {
    unsigned int result = a ^ b;
    printf("Bitwise XOR of ");
    displayBits(a);
    printf("and ");
    displayBits(b);
    printf("is: ");
    displayBits(result);
}

// Function to perform bitwise NOT
void bitwiseNot(unsigned int a) {
    unsigned int result = ~a;
    printf("Bitwise NOT of ");
    displayBits(a);
    printf("is: ");
    displayBits(result);
}

// Function to perform bitwise left shift
void leftShift(unsigned int a, int shift) {
    unsigned int result = a << shift;
    printf("Left shift of ");
    displayBits(a);
    printf("by %d bits is: ", shift);
    displayBits(result);
}

// Function to perform bitwise right shift
void rightShift(unsigned int a, int shift) {
    unsigned int result = a >> shift;
    printf("Right shift of ");
    displayBits(a);
    printf("by %d bits is: ", shift);
    displayBits(result);
}

// Main program
int main() {
    unsigned int num1, num2;

    // Input values
    printf("Enter first unsigned integer: ");
    scanf("%u", &num1);
    printf("Enter second unsigned integer: ");
    scanf("%u", &num2);

    printf("\nBitwise operations on %u and %u:\n", num1, num2);
    
    // AND Operation
    bitwiseAnd(num1, num2);

    // OR Operation
    bitwiseOr(num1, num2);

    // XOR Operation
    bitwiseXor(num1, num2);

    // NOT Operation
    bitwiseNot(num1);
    bitwiseNot(num2);

    // Left Shift Operation
    int leftShiftAmount;
    printf("Enter number of bits to left shift %u: ", num1);
    scanf("%d", &leftShiftAmount);
    leftShift(num1, leftShiftAmount);

    // Right Shift Operation
    int rightShiftAmount;
    printf("Enter number of bits to right shift %u: ", num1);
    scanf("%d", &rightShiftAmount);
    rightShift(num1, rightShiftAmount);

    return 0;
}