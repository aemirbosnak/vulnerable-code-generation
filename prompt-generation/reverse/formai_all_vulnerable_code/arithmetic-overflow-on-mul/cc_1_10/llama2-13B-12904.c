//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 100
#define MAX_NUMBER 1000000

int main() {
    int num1, num2, sum;
    char op;

    printf("Welcome to the Arithmetic Puzzle!\n");

    // Initialize variables
    num1 = 0;
    num2 = 0;
    sum = 0;

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
        sum = num1 - num2;
    } else if (op == '*') {
        sum = num1 * num2;
    } else if (op == '/') {
        sum = num1 / num2;
    } else {
        printf("Invalid operation! Please try again.\n");
        return 0;
    }

    // Print the result
    printf("The result of %d %c %d is %d\n", num1, op, num2, sum);

    // Ask the user if they want to play again
    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &op);

    if (op == 'y') {
        main();
    } else {
        printf("Goodbye! Thanks for playing.\n");
    }

    return 0;
}