//FormAI DATASET v1.0 Category: Calculator ; Style: relaxed
#include <stdio.h>

/* This is a basic calculator that performs addition, subtraction,
   multiplication, division, and modulo operations on two numbers. */

int main() {
    int num1, num2;
    char operator;

    printf("Welcome to the Calculator Program!\n");

    // Ask user for first number
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Ask user for second number
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Ask user for operator to use
    printf("Enter the operator (+, -, *, /, %): ");
    scanf(" %c", &operator);

    // Perform operation based on operator chosen
    switch(operator) {
        case '+':
            printf("%d + %d = %d", num1, num2, num1 + num2);
            break;
        case '-':
            printf("%d - %d = %d", num1, num2, num1 - num2);
            break;
        case '*':
            printf("%d * %d = %d", num1, num2, num1 * num2);
            break;
        case '/':
            if (num2 == 0) { // Check for division by zero
                printf("Error: Cannot divide by zero!");
                break;
            }
            printf("%d / %d = %d", num1, num2, num1 / num2);
            break;
        case '%':
            if (num2 == 0) { // Check for division by zero
                printf("Error: Cannot divide by zero!");
                break;
            }
            printf("%d %% %d = %d", num1, num2, num1 % num2);
            break;
        default:
            printf("Invalid operator!");
            break;
    }

    return 0;
}