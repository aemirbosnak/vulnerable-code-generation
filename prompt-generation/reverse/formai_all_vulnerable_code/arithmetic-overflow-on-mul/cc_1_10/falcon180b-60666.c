//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Declare variables
    int num1, num2, operator;
    char operand;

    // Print menu
    printf("Arithmetic Calculator\n");
    printf("Enter 1 for addition\n");
    printf("Enter 2 for subtraction\n");
    printf("Enter 3 for multiplication\n");
    printf("Enter 4 for division\n");
    printf("Enter 5 for square root\n");

    // Get user input
    scanf("%d", &num1);
    scanf(" %c", &operand);
    scanf("%d", &num2);

    // Perform arithmetic operation
    switch (operand) {
        case '+':
            printf("Result: %d\n", num1 + num2);
            break;
        case '-':
            printf("Result: %d\n", num1 - num2);
            break;
        case '*':
            printf("Result: %d\n", num1 * num2);
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero\n");
            } else {
                printf("Result: %.2f\n", (float)num1 / num2);
            }
            break;
        case's':
            if (num2 < 0) {
                printf("Error: Square root of negative number\n");
            } else {
                printf("Result: %.2f\n", sqrt(num1));
            }
            break;
        default:
            printf("Error: Invalid operator\n");
    }

    return 0;
}