//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_VALUE 1000000000
#define MAX_VALUE 1000000000

int main() {
    int num1, num2, sum, difference, product, quotient, remainder;
    char op;

    // Initialize variables
    num1 = MIN_VALUE;
    num2 = MAX_VALUE;
    sum = 0;
    difference = 0;
    product = 0;
    quotient = 0;
    remainder = 0;

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
        difference = num1 - num2;
    } else if (op == '*') {
        product = num1 * num2;
    } else if (op == '/') {
        quotient = num1 / num2;
        remainder = num1 % num2;
    }

    // Print the result
    printf("Result: %d\n", sum);

    return 0;
}