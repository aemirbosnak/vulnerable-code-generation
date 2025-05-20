//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double num1, num2, result;
    char operation;

    // Prompt user for input
    printf("Enter a number: ");
    scanf("%lf", &num1);
    printf("Enter an operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // Check if operation is valid
    if (operation!= '+' && operation!= '-' && operation!= '*' && operation!= '/') {
        printf("Invalid operation.\n");
        return 1;
    }

    // Prompt user for second number
    printf("Enter another number: ");
    scanf("%lf", &num2);

    // Perform operation and print result
    switch (operation) {
        case '+':
            result = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '/':
            if (num2 == 0) {
                printf("Division by zero is not allowed.\n");
                return 1;
            }
            result = num1 / num2;
            printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
            break;
    }

    return 0;
}