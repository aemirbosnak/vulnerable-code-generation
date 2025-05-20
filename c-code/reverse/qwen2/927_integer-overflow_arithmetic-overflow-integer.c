#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int num1, num2, result;
    char op;
    int i = 0;

    while (i < 10) {
        printf("Enter two integers: ");
        scanf("%d %d", &num1, &num2);
        printf("Enter an operator (+, -, *, /): ");
        scanf(" %c", &op);

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
                printf("Invalid operator!\n");
                continue;
        }

        printf("Result: %d\n", result);
        i++;
    }

    return 0;
}
