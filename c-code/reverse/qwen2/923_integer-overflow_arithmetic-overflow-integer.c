#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int num1, num2;
    char op;

    printf("Enter first number: ");
    scanf("%d", &num1);

    while (1) {
        printf("Enter operator (+, -, *, /) or 'q' to quit: ");
        scanf(" %c", &op);
        if (op == 'q') break;

        printf("Enter second number: ");
        scanf("%d", &num2);

        switch (op) {
            case '+':
                num1 += num2;
                break;
            case '-':
                num1 -= num2;
                break;
            case '*':
                num1 *= num2;
                break;
            case '/':
                if (num2 != 0)
                    num1 /= num2;
                else {
                    printf("Error! Division by zero.\n");
                    continue;
                }
                break;
            default:
                printf("Invalid operator!\n");
                continue;
        }

        printf("Result: %d\n", num1);
    }

    return 0;
}
