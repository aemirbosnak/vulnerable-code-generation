//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int num1, num2, result;
    char operation;

    // Prompt user to enter two numbers
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Prompt user to enter the operation to be performed
    printf("Enter the operation (+, -, *, /, &, |, ^): ");
    scanf(" %c", &operation);

    // Perform the bitwise operation
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
            result = num1 / num2;
            break;
        case '&':
            result = num1 & num2;
            break;
        case '|':
            result = num1 | num2;
            break;
        case '^':
            result = num1 ^ num2;
            break;
        default:
            printf("Invalid operation!");
            return 0;
    }

    // Print the result
    printf("Result: %d\n", result);

    return 0;
}