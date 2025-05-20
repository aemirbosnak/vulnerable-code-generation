//FormAI DATASET v1.0 Category: Data validation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char operator;
    float num1, num2, result;

    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);

    // Validate operator
    if (operator != '+' && operator != '-' && operator != '*' && operator != '/') {
        printf("Invalid operator! Please enter a valid operator.\n");
        return 1;
    }

    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);

    // Validate numbers
    if (isnan(num1) || isnan(num2)) {
        printf("Invalid numbers! Please enter valid numbers.\n");
        return 1;
    }

    // Perform calculation based on operator
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
                printf("Division by zero is undefined! Please enter a non-zero number.\n");
                return 1;
            }
            result = num1 / num2;
            break;
    }

    printf("%.2f %c %.2f = %.2f\n", num1, operator, num2, result);

    return 0;
}