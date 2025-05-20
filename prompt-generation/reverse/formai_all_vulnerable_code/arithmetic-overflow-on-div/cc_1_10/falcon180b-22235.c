//Falcon-180B DATASET v1.0 Category: Error handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_valid_input(int input) {
    if (input < 0) {
        printf("Error: Invalid input. Input must be non-negative.\n");
        return false;
    }
    return true;
}

int main() {
    int num1, num2, result;
    char operation;

    printf("Enter an arithmetic operation (+, -, *, /): ");
    scanf("%c", &operation);

    printf("Enter two numbers: ");
    if (!is_valid_input(scanf("%d", &num1))) {
        return 1;
    }
    if (!is_valid_input(scanf("%d", &num2))) {
        return 1;
    }

    switch (operation) {
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
                return 1;
            }
            result = num1 / num2;
            break;
        default:
            printf("Error: Invalid operation.\n");
            return 1;
    }

    printf("Result: %d\n", result);
    return 0;
}