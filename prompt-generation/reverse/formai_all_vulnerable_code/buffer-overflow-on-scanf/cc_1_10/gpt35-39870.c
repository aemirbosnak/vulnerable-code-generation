//FormAI DATASET v1.0 Category: Bitwise operations ; Style: retro
#include <stdio.h>

// Retro-style Bitwise Operations Program
int main() {

    // Introduction message
    printf("Welcome to Retro-Style Bitwise Operations Program!\n\n");

    // Get user inputs
    int num1, num2;
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    // Perform bitwise operations
    int andOp = num1 & num2;
    int orOp = num1 | num2;
    int xorOp = num1 ^ num2;
    int notOp = ~num1;

    // Display results
    printf("\nBitwise AND Operation: %d & %d = %d\n", num1, num2, andOp);
    printf("Bitwise OR Operation: %d | %d = %d\n", num1, num2, orOp);
    printf("Bitwise XOR Operation: %d ^ %d = %d\n", num1, num2, xorOp);
    printf("Bitwise NOT Operation: ~%d = %d\n", num1, notOp);

    // Calculation example
    printf("\nLet's calculate the 8-bit binary sum of %d and %d.\n\n", num1, num2);

    // Convert input numbers to binary strings
    char binaryNum1[9], binaryNum2[9];
    int temp1 = num1, temp2 = num2;
    for (int i = 7; i >= 0; i--) {
        binaryNum1[i] = temp1 % 2 + '0';
        binaryNum2[i] = temp2 % 2 + '0';
        temp1 /= 2;
        temp2 /= 2;
    }
    binaryNum1[8] = '\0';
    binaryNum2[8] = '\0';

    // Display binary inputs
    printf("Binary %d: %s\n", num1, binaryNum1);
    printf("Binary %d: %s\n", num2, binaryNum2);

    // Perform binary addition
    int carry = 0;
    char binarySum[9];
    for (int i = 7; i >= 0; i--) {
        int sum = (binaryNum1[i] - '0') + (binaryNum2[i] - '0') + carry;
        if (sum >= 2) {
            carry = 1;
            sum %= 2;
        }
        else {
            carry = 0;
        }
        binarySum[i] = sum + '0';
    }
    binarySum[8] = '\0';

    // Display binary sum
    printf("\n8-bit Binary Sum: %s\n", binarySum);

    // Thank you message
    printf("\nThank you for using Retro-Style Bitwise Operations Program!\n");

    return 0;
}