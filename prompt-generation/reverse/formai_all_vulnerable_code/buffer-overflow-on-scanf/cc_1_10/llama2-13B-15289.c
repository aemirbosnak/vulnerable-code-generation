//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum;
    char op;

    printf("Welcome to the Arithmetic Adventure! \n");

    // Initialize the variables
    num1 = rand() % 100;
    num2 = rand() % 100;
    op = '+';

    // Display the numbers
    printf("Your first number is: %d\n", num1);
    printf("Your second number is: %d\n", num2);

    // Ask the user to choose an operation
    printf("Choose an operation (+, -, *, /): ");
    scanf("%c", &op);

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

    // Display the result
    printf("The result of %d %c %d is %d\n", num1, op, num2, sum);

    // Check if the result is equal to MAGIC_NUMBER
    if (sum == MAGIC_NUMBER) {
        printf("Congratulations! You found the Magic Number!\n");
    } else {
        printf("Bummer! The result is not the Magic Number.\n");
    }

    return 0;
}