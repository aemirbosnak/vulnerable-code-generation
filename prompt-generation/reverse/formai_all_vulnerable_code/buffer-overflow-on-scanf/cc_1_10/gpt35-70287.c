//FormAI DATASET v1.0 Category: Bitwise operations ; Style: recursive
#include <stdio.h>

// Recursive function to convert a decimal number to a binary number
int decimalToBinary(int decimalNumber) {
    // Base case
    if (decimalNumber == 0) {
        return 0;
    } else {
        // Recursive case
        return (decimalNumber % 2) + 10 * decimalToBinary(decimalNumber / 2);
    }
}

// Recursive function to perform bitwise AND operation
int bitwiseAnd(int num1, int num2) {
    // Base case
    if (num1 == 0 || num2 == 0) {
        return 0;
    } else {
        // Recursive case
        return (num1 % 2 & num2 % 2) + 2 * bitwiseAnd(num1 / 2, num2 / 2);
    }
}

// Recursive function to perform bitwise OR operation
int bitwiseOr(int num1, int num2) {
    // Base case
    if (num1 == 0 && num2 == 0) {
        return 0;
    } else {
        // Recursive case
        return (num1 % 2 | num2 % 2) + 2 * bitwiseOr(num1 / 2, num2 / 2);
    }
}

// Recursive function to perform bitwise XOR operation
int bitwiseXor(int num1, int num2) {
    // Base case
    if (num1 == 0 && num2 == 0) {
        return 0;
    } else {
        // Recursive case
        return (num1 % 2 ^ num2 % 2) + 2 * bitwiseXor(num1 / 2, num2 / 2);
    }
}

int main() {
    int num1, num2;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("Decimal to binary conversion of %d: %d\n", num1, decimalToBinary(num1));
    printf("Decimal to binary conversion of %d: %d\n", num2, decimalToBinary(num2));
    printf("Bitwise AND of %d and %d: %d\n", num1, num2, bitwiseAnd(num1, num2));
    printf("Bitwise OR of %d and %d: %d\n", num1, num2, bitwiseOr(num1, num2));
    printf("Bitwise XOR of %d and %d: %d\n", num1, num2, bitwiseXor(num1, num2));

    return 0;
}