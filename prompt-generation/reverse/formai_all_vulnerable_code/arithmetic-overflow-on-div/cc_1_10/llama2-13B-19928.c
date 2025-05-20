//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum, product, difference, quotient, remainder;
    char op;

    printf("Welcome to the Arithmetic Genius Program!\n");

    // Ask the user for the first number
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Ask the user for the second number
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Ask the user for the operation
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &op);

    // Perform the operation
    if (op == '+') {
        sum = num1 + num2;
    } else if (op == '-') {
        difference = num1 - num2;
    } else if (op == '*') {
        product = num1 * num2;
    } else if (op == '/') {
        quotient = num1 / num2;
        remainder = num1 % num2;
    }

    // Print the results
    printf("The result of %d %c %d is: %d\n", num1, op, num2, sum);
    printf("The result of %d %c %d is: %d\n", num1, op, num2, product);
    printf("The result of %d %c %d is: %d\n", num1, op, num2, quotient);
    printf("The result of %d %c %d is: %d\n", num1, op, num2, remainder);

    // Add some magic to the program
    if (num1 + num2 == MAGIC_NUMBER) {
        printf("Congratulations, you have found the secret number %d!", MAGIC_NUMBER);
    }

    return 0;
}