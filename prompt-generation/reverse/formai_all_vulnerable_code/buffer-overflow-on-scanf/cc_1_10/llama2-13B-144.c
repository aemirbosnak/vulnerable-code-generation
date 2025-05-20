//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum, product, square;
    char op;

    printf("Welcome to the Arithmetic Empire!\n");

    // Initialize variables
    num1 = 13;
    num2 = 27;
    sum = 0;
    product = 1;
    square = 1;

    // Get operation from user
    printf("Enter an operation (+, -, x, /): ");
    scanf("%c", &op);

    // Perform operation
    if (op == '+') {
        sum = num1 + num2;
    } else if (op == '-') {
        sum = num1 - num2;
    } else if (op == 'x') {
        product = num1 * num2;
    } else if (op == '/') {
        if (num2 == 0) {
            printf("Error: cannot divide by zero!\n");
            return 1;
        }
        square = num1 / num2;
    }

    // Print results
    printf("Result of %d %s %d is %d\n", num1, op, num2, sum);
    printf("Result of %d x %d is %d\n", num1, num2, product);
    printf("Result of %d / %d is %d\n", num1, num2, square);

    // Check if the result of the last operation is the magic number
    if (sum == MAGIC_NUMBER || product == MAGIC_NUMBER || square == MAGIC_NUMBER) {
        printf("Congratulations! You found the magic number %d!\n", MAGIC_NUMBER);
    }

    return 0;
}