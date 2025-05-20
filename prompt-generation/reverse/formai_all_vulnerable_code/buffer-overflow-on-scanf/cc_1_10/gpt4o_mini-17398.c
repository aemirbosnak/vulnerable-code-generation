//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a decimal number to binary representation
void decimalToBinary(int n, char *binaryStr) {
    for (int i = 31; i >= 0; i--) {
        binaryStr[i] = (n & 1) ? '1' : '0';
        n >>= 1;
    }
    binaryStr[32] = '\0'; // Null-terminate the string
}

// Function to perform bitwise AND operation
void bitwiseAND(int a, int b) {
    int result = a & b;
    char binaryA[33], binaryB[33], binaryResult[33];
    decimalToBinary(a, binaryA);
    decimalToBinary(b, binaryB);
    decimalToBinary(result, binaryResult);

    printf("Bitwise AND:\n");
    printf("%d (binary: %s)\n", a, binaryA);
    printf("%d (binary: %s)\n", b, binaryB);
    printf("Result of AND: %d (binary: %s)\n", result, binaryResult);
}

// Function to perform bitwise OR operation
void bitwiseOR(int a, int b) {
    int result = a | b;
    char binaryA[33], binaryB[33], binaryResult[33];
    decimalToBinary(a, binaryA);
    decimalToBinary(b, binaryB);
    decimalToBinary(result, binaryResult);

    printf("Bitwise OR:\n");
    printf("%d (binary: %s)\n", a, binaryA);
    printf("%d (binary: %s)\n", b, binaryB);
    printf("Result of OR: %d (binary: %s)\n", result, binaryResult);
}

// Function to perform bitwise XOR operation
void bitwiseXOR(int a, int b) {
    int result = a ^ b;
    char binaryA[33], binaryB[33], binaryResult[33];
    decimalToBinary(a, binaryA);
    decimalToBinary(b, binaryB);
    decimalToBinary(result, binaryResult);

    printf("Bitwise XOR:\n");
    printf("%d (binary: %s)\n", a, binaryA);
    printf("%d (binary: %s)\n", b, binaryB);
    printf("Result of XOR: %d (binary: %s)\n", result, binaryResult);
}

// Function to perform bitwise NOT operation
void bitwiseNOT(int a) {
    int result = ~a;
    char binaryA[33], binaryResult[33];
    decimalToBinary(a, binaryA);
    decimalToBinary(result, binaryResult);

    printf("Bitwise NOT:\n");
    printf("Original: %d (binary: %s)\n", a, binaryA);
    printf("Result of NOT: %d (binary: %s)\n", result, binaryResult);
}

// Function to perform left shift operation
void leftShift(int a, int shift) {
    int result = a << shift;
    char binaryA[33], binaryResult[33];
    decimalToBinary(a, binaryA);
    decimalToBinary(result, binaryResult);

    printf("Left Shift:\n");
    printf("%d (binary: %s) << %d = %d (binary: %s)\n", a, binaryA, shift, result, binaryResult);
}

// Function to perform right shift operation
void rightShift(int a, int shift) {
    int result = a >> shift;
    char binaryA[33], binaryResult[33];
    decimalToBinary(a, binaryA);
    decimalToBinary(result, binaryResult);

    printf("Right Shift:\n");
    printf("%d (binary: %s) >> %d = %d (binary: %s)\n", a, binaryA, shift, result, binaryResult);
}

// Main function to demonstrate futuristic bitwise operations
int main() {
    int num1, num2, shiftValue;

    printf("Welcome to the Futuristic Bitwise Operation Simulator!\n");
    printf("Enter two integers for bitwise operations:\n");
    printf("Integer 1: ");
    scanf("%d", &num1);
    printf("Integer 2: ");
    scanf("%d", &num2);

    printf("Enter a shift value (1-31): ");
    scanf("%d", &shiftValue);

    // Perform and display various bitwise operations
    bitwiseAND(num1, num2);
    bitwiseOR(num1, num2);
    bitwiseXOR(num1, num2);
    bitwiseNOT(num1);
    leftShift(num1, shiftValue);
    rightShift(num1, shiftValue);

    return 0;
}