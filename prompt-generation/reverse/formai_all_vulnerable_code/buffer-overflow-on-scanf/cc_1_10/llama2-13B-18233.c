//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: genius
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum, product, square, cube;
    char op;

    // Initialize variables
    num1 = 13;
    num2 = 27;
    sum = 0;
    product = 1;
    square = 0;
    cube = 0;

    // Read operation from user
    printf("Enter an operation (+, -, x, /): ");
    scanf(" %c", &op);

    // Perform operation
    if (op == '+') {
        sum = num1 + num2;
    } else if (op == '-') {
        sum = num1 - num2;
    } else if (op == '*') {
        product = num1 * num2;
    } else if (op == '/') {
        if (num2 == 0) {
            printf("Error: division by zero!\n");
            return 1;
        }
        sum = num1 / num2;
    } else {
        printf("Error: invalid operation\n");
        return 2;
    }

    // Print results
    printf("Result: %d\n", sum);
    printf("Product: %d\n", product);
    printf("Square: %d\n", square);
    printf("Cube: %d\n", cube);

    // Calculate square and cube
    square = num1 * num1;
    cube = num1 * num1 * num1;

    // Check for magic number
    if (sum == MAGIC_NUMBER && product == MAGIC_NUMBER && square == MAGIC_NUMBER && cube == MAGIC_NUMBER) {
        printf("Congratulations! You have found the magic number %d!\n", MAGIC_NUMBER);
    }

    return 0;
}