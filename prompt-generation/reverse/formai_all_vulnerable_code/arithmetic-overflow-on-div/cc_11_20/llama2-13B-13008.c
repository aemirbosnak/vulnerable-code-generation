//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum, diff, mult, div;
    char op;
    printf("Welcome to the dynamic arithmetic program!\n");

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operation from the user
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &op);

    // Perform the operation
    if (op == '+') {
        sum = num1 + num2;
    } else if (op == '-') {
        diff = num1 - num2;
    } else if (op == '*') {
        mult = num1 * num2;
    } else if (op == '/') {
        div = num1 / num2;
    }

    // Print the result
    printf("Result: %d\n", sum);

    // Get the user's input again to repeat the operation
    printf("Do you want to repeat the operation? (y/n): ");
    scanf(" %c", &op);

    while (op == 'y' || op == 'Y') {
        // Repeat the operation
        printf("Enter the first number: ");
        scanf("%d", &num1);

        printf("Enter the second number: ");
        scanf("%d", &num2);

        printf("Enter the operation (+, -, *, /): ");
        scanf(" %c", &op);

        // Perform the operation
        if (op == '+') {
            sum = num1 + num2;
        } else if (op == '-') {
            diff = num1 - num2;
        } else if (op == '*') {
            mult = num1 * num2;
        } else if (op == '/') {
            div = num1 / num2;
        }

        // Print the result
        printf("Result: %d\n", sum);
    }

    return 0;
}