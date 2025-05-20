//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: synchronous
#include <stdio.h>

// Function to display binary representation of a number
void printBinary(int n) {
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        putchar((n & (1 << i)) ? '1' : '0');
    }
    putchar('\n');
}

// Function to perform bitwise AND operation
int bitwiseAND(int a, int b) {
    return a & b;
}

// Function to perform bitwise OR operation
int bitwiseOR(int a, int b) {
    return a | b;
}

// Function to perform bitwise XOR operation
int bitwiseXOR(int a, int b) {
    return a ^ b;
}

// Function to perform bitwise NOT operation
int bitwiseNOT(int a) {
    return ~a;
}

// Function to perform left shift operation
int leftShift(int a, int positions) {
    return a << positions;
}

// Function to perform right shift operation
int rightShift(int a, int positions) {
    return a >> positions;
}

// Function to swap two numbers using bitwise XOR
void swapUsingXOR(int *a, int *b) {
    if (a != b) {
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }
}

// Main function to demonstrate bitwise operations
int main() {
    int a, b;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    
    printf("You entered: a = %d, b = %d\n", a, b);

    // Print binary representation of input numbers
    printf("Binary representation:\n");
    printf("a: ");
    printBinary(a);
    printf("b: ");
    printBinary(b);

    // Demonstrate bitwise operations
    printf("Bitwise AND (a & b): ");
    int andResult = bitwiseAND(a, b);
    printBinary(andResult);
    printf("Decimal result: %d\n", andResult);

    printf("Bitwise OR (a | b): ");
    int orResult = bitwiseOR(a, b);
    printBinary(orResult);
    printf("Decimal result: %d\n", orResult);

    printf("Bitwise XOR (a ^ b): ");
    int xorResult = bitwiseXOR(a, b);
    printBinary(xorResult);
    printf("Decimal result: %d\n", xorResult);

    printf("Bitwise NOT (~a): ");
    int notResultA = bitwiseNOT(a);
    printBinary(notResultA);
    printf("Decimal result: %d\n", notResultA);
    
    printf("Bitwise NOT (~b): ");
    int notResultB = bitwiseNOT(b);
    printBinary(notResultB);
    printf("Decimal result: %d\n", notResultB);

    int shiftPositions;
    printf("Enter number of positions to left shift: ");
    scanf("%d", &shiftPositions);
    printf("Left shifting a by %d positions: ", shiftPositions);
    int leftShiftResult = leftShift(a, shiftPositions);
    printBinary(leftShiftResult);
    printf("Decimal result: %d\n", leftShiftResult);

    printf("Enter number of positions to right shift: ");
    scanf("%d", &shiftPositions);
    printf("Right shifting a by %d positions: ");
    int rightShiftResult = rightShift(a, shiftPositions);
    printBinary(rightShiftResult);
    printf("Decimal result: %d\n", rightShiftResult);

    printf("Swapping a and b using XOR...\n");
    printf("Before swapping: a = %d, b = %d\n", a, b);
    swapUsingXOR(&a, &b);
    printf("After swapping: a = %d, b = %d\n", a, b);

    return 0;
}