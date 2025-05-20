//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: beginner-friendly
#include <stdio.h>

void displayBinary(int num) {
    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        printf("%d", bit);
    }
}

int main() {
    int num1, num2;
    
    printf("Welcome to the Bitwise Operations Program!\n");
    printf("Please enter two integers:\n");

    // Input numbers
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    // Perform AND operation
    int andResult = num1 & num2;

    // Perform OR operation
    int orResult = num1 | num2;

    // Perform XOR operation
    int xorResult = num1 ^ num2;

    // Perform NOT operation on both numbers
    int notNum1 = ~num1;
    int notNum2 = ~num2;

    // Display results
    printf("\nBitwise Operations Results:\n");
    
    printf("First Number (Decimal): %d\n", num1);
    printf("First Number (Binary):  ");
    displayBinary(num1);
    printf("\n");

    printf("Second Number (Decimal): %d\n", num2);
    printf("Second Number (Binary):  ");
    displayBinary(num2);
    printf("\n");

    printf("\nBitwise AND (num1 & num2): %d\n", andResult);
    printf("Bitwise AND (Binary):  ");
    displayBinary(andResult);
    printf("\n");

    printf("Bitwise OR (num1 | num2): %d\n", orResult);
    printf("Bitwise OR (Binary):  ");
    displayBinary(orResult);
    printf("\n");

    printf("Bitwise XOR (num1 ^ num2): %d\n", xorResult);
    printf("Bitwise XOR (Binary):  ");
    displayBinary(xorResult);
    printf("\n");

    printf("Bitwise NOT of first number (~num1): %d\n", notNum1);
    printf("Bitwise NOT of first number (Binary):  ");
    displayBinary(notNum1);
    printf("\n");

    printf("Bitwise NOT of second number (~num2): %d\n", notNum2);
    printf("Bitwise NOT of second number (Binary):  ");
    displayBinary(notNum2);
    printf("\n");

    // Additional examples of left and right shift
    int leftShiftNum1 = num1 << 1;
    int rightShiftNum1 = num1 >> 1;

    printf("Left Shift first number (num1 << 1): %d\n", leftShiftNum1);
    printf("Right Shift first number (num1 >> 1): %d\n", rightShiftNum1);

    return 0;
}