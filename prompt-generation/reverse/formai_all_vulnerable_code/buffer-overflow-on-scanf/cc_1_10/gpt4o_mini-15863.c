//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: beginner-friendly
#include <stdio.h>

// Function to print binary representation of a number
void printBinary(int num) {
    for (int i = 7; i >= 0; i--) { // Assuming we are only dealing with 8-bit numbers
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

// Function to perform bitwise AND
void bitwiseAnd(int a, int b) {
    int result = a & b;
    printf("Bitwise AND of ");
    printBinary(a);
    printf("and ");
    printBinary(b);
    printf("is ");
    printBinary(result);
}

// Function to perform bitwise OR
void bitwiseOr(int a, int b) {
    int result = a | b;
    printf("Bitwise OR of ");
    printBinary(a);
    printf("and ");
    printBinary(b);
    printf("is ");
    printBinary(result);
}

// Function to perform bitwise XOR
void bitwiseXor(int a, int b) {
    int result = a ^ b;
    printf("Bitwise XOR of ");
    printBinary(a);
    printf("and ");
    printBinary(b);
    printf("is ");
    printBinary(result);
}

// Function to perform bitwise NOT
void bitwiseNot(int a) {
    int result = ~a;
    printf("Bitwise NOT of ");
    printBinary(a);
    printf("is ");
    printBinary(result);
}

// Function to left shift a number
void leftShift(int a, int positions) {
    int result = a << positions;
    printf("Left shift of ");
    printBinary(a);
    printf("by %d positions is ", positions);
    printBinary(result);
}

// Function to right shift a number
void rightShift(int a, int positions) {
    int result = a >> positions;
    printf("Right shift of ");
    printBinary(a);
    printf("by %d positions is ", positions);
    printBinary(result);
}

// Main function to demonstrate bitwise operations
int main() {
    int num1, num2;

    // Input two integers from the user
    printf("Enter first integer (0-255): ");
    scanf("%d", &num1);
    printf("Enter second integer (0-255): ");
    scanf("%d", &num2);

    // Validate input
    if ((num1 < 0 || num1 > 255) || (num2 < 0 || num2 > 255)) {
        printf("Please enter valid integers between 0 and 255.\n");
        return 1;
    }

    // Performing and displaying results of bitwise operations
    bitwiseAnd(num1, num2);
    bitwiseOr(num1, num2);
    bitwiseXor(num1, num2);
    bitwiseNot(num1);
    bitwiseNot(num2);

    // Shift operations
    int shiftPositions;
    printf("Enter number of positions to shift left/right (0-7): ");
    scanf("%d", &shiftPositions);

    // Validate shift positions
    if (shiftPositions < 0 || shiftPositions > 7) {
        printf("Please enter valid shift positions between 0 and 7.\n");
        return 1;
    }

    leftShift(num1, shiftPositions);
    rightShift(num2, shiftPositions);

    return 0;
}