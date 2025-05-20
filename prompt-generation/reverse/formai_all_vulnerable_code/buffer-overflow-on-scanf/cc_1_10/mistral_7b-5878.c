//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// Function to display the bitwise operations of two numbers
void displayBitwiseOperations(unsigned int num1, unsigned int num2) {
    unsigned int andResult, orResult, xorResult, notNum1, notNum2, leftShiftResult, rightShiftResult;

    // Perform AND operation
    andResult = num1 & num2;
    printf("AND: %d & %d = %d\n", num1, num2, andResult);

    // Perform OR operation
    orResult = num1 | num2;
    printf("OR : %d | %d = %d\n", num1, num2, orResult);

    // Perform XOR operation
    xorResult = num1 ^ num2;
    printf("XOR: %d ^ %d = %d\n", num1, num2, xorResult);

    // Perform NOT operation on num1
    notNum1 = ~num1;
    printf("NOT: ~%d = %d\n", num1, notNum1);

    // Perform NOT operation on num2
    notNum2 = ~num2;
    printf("NOT: ~%d = %d\n", num2, notNum2);

    // Perform left shift operation
    leftShiftResult = num1 << 2;
    printf("LEFT SHIFT: %d << 2 = %d\n", num1, leftShiftResult);

    // Perform right shift operation
    rightShiftResult = num1 >> 2;
    printf("RIGHT SHIFT: %d >> 2 = %d\n", num1, rightShiftResult);
}

int main() {
    unsigned int num1, num2;

    // Read two numbers from user
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    // Call displayBitwiseOperations function to perform bitwise operations
    displayBitwiseOperations(num1, num2);

    return 0;
}