//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_INT 2147483647
#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum;
    char op;

    printf("Welcome to the Curious Arithmetic Machine!\n");

    // Initialize the magic number
    srand(time(NULL) + MAGIC_NUMBER);

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
        sum = -1;
    }

    // Check for overflow
    if (sum > MAX_INT || sum < -MAX_INT) {
        sum = -1;
    }

    // Print the result
    printf("The result is: %d\n", sum);

    return 0;
}