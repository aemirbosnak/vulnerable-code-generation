#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2, operation, result;
    char cont;

    for (;;) {
        printf("Enter first integer: ");
        scanf("%d", &num1);
        printf("Enter second integer: ");
        scanf("%d", &num2);
        printf("Choose operation (1 - add, 2 - subtract, 3 - multiply, 4 - divide): ");
        scanf("%d", &operation);

        switch (operation) {
            case 1:
                result = num1 + num2;
                break;
            case 2:
                result = num1 - num2;
                break;
            case 3:
                result = num1 * num2;
                break;
            case 4:
                if (num2 == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                    continue;
                }
                result = num1 / num2;
                break;
            default:
                printf("Error: Invalid operation.\n");
                continue;
        }

        printf("Result: %d\n", result);
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &cont);

        if (cont != 'y') {
            break;
        }
    }

    return 0;
}
