//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 100

int main() {
    int num1, num2, sum, diff, mult, div;
    char op;

    printf("Welcome to Arithmetic Land!\n");

    // Initialize variables
    num1 = 5;
    num2 = 10;
    sum = 0;
    diff = 0;
    mult = 1;
    div = 1;

    // Ask user for operation
    printf("Enter an operation (a, b, +, -, *, /): ");
    scanf("%c", &op);

    // Perform operation
    if (op == '+') {
        sum = num1 + num2;
    } else if (op == '-') {
        diff = num1 - num2;
    } else if (op == '*') {
        mult = num1 * num2;
    } else if (op == '/') {
        div = num1 / num2;
    }

    // Display result
    printf("Result: %d\n", sum);
    printf("Diff: %d\n", diff);
    printf("Mult: %d\n", mult);
    printf("Div: %d\n", div);

    // Ask user for next operation
    printf("Do you want to perform another operation? (y/n): ");
    scanf("%c", &op);

    // Loop until user says no
    while (op == 'y' || op == 'Y') {
        // Ask user for new numbers
        printf("Enter two numbers (a and b): ");
        scanf("%d%d", &num1, &num2);

        // Perform operation
        if (op == '+') {
            sum = num1 + num2;
        } else if (op == '-') {
            diff = num1 - num2;
        } else if (op == '*') {
            mult = num1 * num2;
        } else if (op == '/') {
            div = num1 / num2;
        }

        // Display result
        printf("Result: %d\n", sum);
        printf("Diff: %d\n", diff);
        printf("Mult: %d\n", mult);
        printf("Div: %d\n", div);

        // Ask user for next operation
        printf("Do you want to perform another operation? (y/n): ");
        scanf("%c", &op);
    }

    return 0;
}