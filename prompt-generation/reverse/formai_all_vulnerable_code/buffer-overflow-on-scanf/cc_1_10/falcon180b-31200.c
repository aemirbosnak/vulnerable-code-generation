//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: irregular
// This program performs arithmetic operations on two numbers entered by the user.
// It also allows the user to choose the operation they want to perform.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char op;
    double num1, num2;

    // Get first number from user
    printf("Enter first number: ");
    if (!scanf("%lf", &num1)) {
        printf("Invalid input.\n");
        return 1;
    }

    // Get second number from user
    printf("Enter second number: ");
    if (!scanf("%lf", &num2)) {
        printf("Invalid input.\n");
        return 1;
    }

    // Get operation from user
    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &op);

    // Perform arithmetic operation
    switch (op) {
        case '+':
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
            break;
        case '/':
            if (num2 == 0) {
                printf("Cannot divide by zero.\n");
            } else {
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
            }
            break;
        default:
            printf("Invalid operation.\n");
    }

    return 0;
}