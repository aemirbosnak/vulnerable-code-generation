//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2, choice, result;
    char operation;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    while (getchar() != '\n') {
        if (feof(stdin)) {
            printf("Invalid input! Please enter a valid number.\n");
            return 1;
        }
    }

    printf("Enter the second number: ");
    scanf("%d", &num2);

    while (getchar() != '\n') {
        if (feof(stdin)) {
            printf("Invalid input! Please enter a valid number.\n");
            return 1;
        }
    }

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operation);

    switch(operation) {
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
                return 1;
            }
            result = num1 / num2;
            break;
        default:
            printf("Invalid operator! Please use one of the following: +, -, *, /\n");
            return 1;
    }

    printf("The result of %d %c %d is: %d\n", num1, operation, num2, result);

    return 0;
}