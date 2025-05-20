//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: energetic
#include <stdio.h>

// Function to print the binary representation of a number
void printBinary(unsigned int n) {
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

// Perform bitwise AND operation
unsigned int bitwiseAND(unsigned int a, unsigned int b) {
    return a & b;
}

// Perform bitwise OR operation
unsigned int bitwiseOR(unsigned int a, unsigned int b) {
    return a | b;
}

// Perform bitwise XOR operation
unsigned int bitwiseXOR(unsigned int a, unsigned int b) {
    return a ^ b;
}

// Perform bitwise NOT operation
unsigned int bitwiseNOT(unsigned int a) {
    return ~a;
}

// Perform left shift operation
unsigned int leftShift(unsigned int a, int shift) {
    return a << shift;
}

// Perform right shift operation
unsigned int rightShift(unsigned int a, int shift) {
    return a >> shift;
}

// Main function
int main() {
    unsigned int num1, num2;

    printf("Welcome to the Bitwise Operation Funhouse!\n");
    printf("Let's dive deep into the world of bit manipulation!\n");

    // Input numbers from the user
    printf("Enter first positive number: ");
    scanf("%u", &num1);
    printf("Enter second positive number: ");
    scanf("%u", &num2);

    // Display original numbers
    printf("\nYour numbers in binary are:\n");
    printf("Number 1: ");
    printBinary(num1);
    printf("Number 2: ");
    printBinary(num2);

    // Performing bitwise AND
    unsigned int andResult = bitwiseAND(num1, num2);
    printf("\nBitwise AND:\n");
    printf("Result: %u\nBinary: ", andResult);
    printBinary(andResult);

    // Performing bitwise OR
    unsigned int orResult = bitwiseOR(num1, num2);
    printf("\nBitwise OR:\n");
    printf("Result: %u\nBinary: ", orResult);
    printBinary(orResult);

    // Performing bitwise XOR
    unsigned int xorResult = bitwiseXOR(num1, num2);
    printf("\nBitwise XOR:\n");
    printf("Result: %u\nBinary: ", xorResult);
    printBinary(xorResult);

    // Performing bitwise NOT on num1
    unsigned int notResultNum1 = bitwiseNOT(num1);
    printf("\nBitwise NOT of Number 1:\n");
    printf("Result: %u\nBinary: ", notResultNum1);
    printBinary(notResultNum1);

    // Performing bitwise NOT on num2
    unsigned int notResultNum2 = bitwiseNOT(num2);
    printf("\nBitwise NOT of Number 2:\n");
    printf("Result: %u\nBinary: ", notResultNum2);
    printBinary(notResultNum2);

    // Left shift Operation
    printf("\nLeft Shift Operation on Number 1 (by 1):\n");
    unsigned int leftShiftResult = leftShift(num1, 1);
    printf("Result: %u\nBinary: ", leftShiftResult);
    printBinary(leftShiftResult);

    // Right shift Operation
    printf("\nRight Shift Operation on Number 1 (by 1):\n");
    unsigned int rightShiftResult = rightShift(num1, 1);
    printf("Result: %u\nBinary: ", rightShiftResult);
    printBinary(rightShiftResult);

    // Wrap up the funhouse
    printf("\nThank you for visiting the Bitwise Operation Funhouse!\n");
    printf("Make sure to explore more about bit manipulations!\n");
    return 0;
}