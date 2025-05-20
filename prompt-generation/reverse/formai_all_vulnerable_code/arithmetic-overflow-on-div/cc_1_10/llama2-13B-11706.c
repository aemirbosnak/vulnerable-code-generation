//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum, diff, mult, div;
    char op;

    printf("Welcome to the Magic Math Machine!\n");

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
    switch (op) {
        case '+':
            sum = num1 + num2;
            break;
        case '-':
            diff = num1 - num2;
            break;
        case '*':
            mult = num1 * num2;
            break;
        case '/':
            div = num1 / num2;
            break;
        default:
            printf("Invalid operation! Please try again.");
            return 1;
    }

    // Print the result
    printf("Result: %d\n", sum);

    // Check if the result is magical
    if (sum == MAGIC_NUMBER) {
        printf("Congratulations! You have found the magical result!\n");
    } else {
        printf("Too bad! The result is not magical.\n");
    }

    return 0;
}