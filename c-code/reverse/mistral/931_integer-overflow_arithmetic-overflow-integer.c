#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_EXPRESSION_LENGTH 1024

int main() {
    char expression[MAX_EXPRESSION_LENGTH];
    double num1, num2, result;
    char operator;

    printf("Enter a mathematical expression (e.g. 3.14 * 2): ");
    fgets(expression, MAX_EXPRESSION_LENGTH, stdin);

    // Find the first operator in the expression
    for (int i = 0; expression[i] != '\0'; ++i) {
        if (isalpha(expression[i])) continue;
        operator = expression[i];
        break;
    }

    // Parse numbers and perform calculation
    sscanf(expression, "%lf %c %lf", &num1, &operator, &num2);

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
                return 1;
            }
            result = num1 / num2;
            break;
        default:
            printf("Error: Invalid operator.\n");
            return 1;
    }

    printf("Result: %.8f\n", result);
    return 0;
}
