//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum;
    char op;

    // Ask the user for the first number
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Ask the user for the second number
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Ask the user for the operation (add, sub, mul, div)
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
        sum = MAGIC_NUMBER; // handle invalid input
    }

    // Print the result
    printf("Result: %d\n", sum);

    // Generate a random number between 1 and 10
    int random = (rand() % 10) + 1;

    // If the result of the operation is equal to the random number, print "Genius!"
    if (sum == random) {
        printf("Genius! You got it right!\n");
    } else {
        printf("Close, but not quite. Try again...\n");
    }

    return 0;
}