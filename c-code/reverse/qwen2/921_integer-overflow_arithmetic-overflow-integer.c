#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    char op;
    double num1, num2, result;

    while (1) {
        printf("Enter operator (+, -, *, /) or press Enter to exit: ");
        scanf("%c", &op);
        if (op == '\n') break;

        printf("Enter first number: ");
        if (scanf("%lf", &num1) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear buffer
            continue;
        }

        printf("Enter second number: ");
        if (scanf("%lf", &num2) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear buffer
            continue;
        }

        switch (op) {
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
                if (num2 != 0)
                    result = num1 / num2;
                else {
                    printf("Error! Division by zero.\n");
                    continue;
                }
                break;
            default:
                printf("Invalid operator. Please use +, -, *, or /.\n");
                continue;
        }

        printf("Result: %.2f\n", result);
    }

    return 0;
}
