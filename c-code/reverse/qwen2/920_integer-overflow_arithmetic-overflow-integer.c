#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int num1 = 2147483647; // Maximum positive int value
    int num2 = 1;
    char operation;

    while (1) {
        printf("Enter operation (+, -, *, /) or 'q' to quit: ");
        scanf(" %c", &operation);

        if (operation == 'q') break;

        switch (operation) {
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
                num1 /= num2;
                break;
            default:
                printf("Invalid operation\n");
                continue;
        }

        printf("Result: %d\n", num1);
    }

    return 0;
}
