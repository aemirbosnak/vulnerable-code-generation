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
        printf("Enter an operator (+, -, *, /): ");
        scanf("%c", &op);

        if (op == '+' || op == '-' || op == '*' || op == '/') {
            printf("Enter first number: ");
            scanf("%lf", &num1);

            printf("Enter second number: ");
            scanf("%lf", &num2);

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
                    if (num2 == 0) {
                        printf("Error: Division by zero is not allowed.\n");
                        continue;
                    }
                    result = num1 / num2;
                    break;
            }

            printf("Result: %.2lf\n", result);
        } else {
            printf("Error: Invalid operator. Please enter a valid operator (+, -, *, /).\n");
        }
    }

    return 0;
}
