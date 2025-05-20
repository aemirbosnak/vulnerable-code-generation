//FormAI DATASET v1.0 Category: Calculator ; Style: satisfied
#include <stdio.h>

int main() {
    int operand1, operand2; // Declare variables for taking inputs
    char operation; // Declare variable for taking operation
    float result; // Declare variable for storing the result

    printf("Welcome to the Amazing Calculator! Let's do some math!\n\n");

    // Take input for first operand
    printf("Please enter the first operand: ");
    scanf("%d", &operand1);

    // Take input for second operand
    printf("Please enter the second operand: ");
    scanf("%d", &operand2);

    // Take input for operation
    printf("Please enter the operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // Perform calculation based on operation
    switch (operation) {
        case '+': // Addition
            result = operand1 + operand2;
            printf("\nThe addition of %d and %d is %.2f\n", operand1, operand2, result);
            break;
        case '-': // Subtraction
            result = operand1 - operand2;
            printf("\nThe subtraction of %d and %d is %.2f\n", operand1, operand2, result);
            break;
        case '*': // Multiplication
            result = operand1 * operand2;
            printf("\nThe multiplication of %d and %d is %.2f\n", operand1, operand2, result);
            break;
        case '/': // Division
            if (operand2 == 0) {
                printf("\nError: division by zero is undefined\n");
            } else {
                result = (float)operand1 / (float)operand2;
                printf("\nThe division of %d and %d is %.2f\n", operand1, operand2, result);
            }
            break;
        default: // Invalid input for operation
            printf("\nInvalid operation! Please enter a valid operation (+, -, *, /)\n");
            break;
    }

    printf("\nThanks for using the Amazing Calculator!\n");

    return 0;
}