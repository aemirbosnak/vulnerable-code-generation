#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    char op;
    int num1, num2, result;

    while (1) {
        printf("Enter operation (e.g. +, -, *, /): ");
        scanf("%c", &op);

        printf("Enter first number: ");
        scanf("%d", &num1);

        printf("Enter second number: ");
        scanf("%d", &num2);

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
                    printf("Error: Division by zero.\n");
                    continue;
                }
                result = num1 / num2;
                break;
            default:
                printf("Error: Invalid operation.\n");
                continue;
        }

        printf("Result: %d\n", result);

        printf("Enter another operation? (y/n): ");
        char cont;
        scanf("%c", &cont);

        if (cont != 'y') {
            break;
        }
    }

    return 0;
}
