//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum;
    char op;

    printf("Welcome to the Mathemagical Adventure! \n");

    // Generate a random number
    srand(time(NULL));
    num1 = rand() % 100;
    printf("Your first number is: %d\n", num1);

    // Get the user's input
    printf("Enter your second number: ");
    scanf("%d", &num2);
    printf("Enter your operation (+, -, *, /): ");
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
        return 1;
    }

    // Print the result
    printf("The result of %d %c %d is %d\n", num1, op, num2, sum);

    // Check if the result is magical
    if (sum == MAGIC_NUMBER) {
        printf("Congratulations! You have found the magical number %d! \n", MAGIC_NUMBER);
    } else {
        printf("Too bad! The result is not magical. Better luck next time.\n");
    }

    return 0;
}