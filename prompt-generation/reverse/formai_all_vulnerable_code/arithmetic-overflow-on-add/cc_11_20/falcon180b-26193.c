//Falcon-180B DATASET v1.0 Category: Error handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int num1, num2, result;
    char operator;

    // Prompt user to enter two numbers and an operator
    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("Enter the operator (+, -, *, /): ");
    scanf(" %c", &operator);

    // Perform calculation based on user input
    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
                exit(1);
            }
            result = num1 / num2;
            break;
        default:
            printf("Error: Invalid operator.\n");
            exit(1);
    }

    // Handle any errors that may occur during calculation
    if (result == 0 && operator!= '/') {
        printf("Error: Division by zero is not allowed.\n");
        exit(1);
    } else if (result == 0) {
        printf("Error: Division by zero is not allowed.\n");
        exit(1);
    } else if (result == (int) pow(2, 31) - 1) {
        printf("Error: Integer overflow.\n");
        exit(1);
    } else if (result == (int) pow(2, 31) - 2) {
        printf("Error: Integer underflow.\n");
        exit(1);
    } else {
        printf("The result is: %d\n", result);
    }

    return 0;
}