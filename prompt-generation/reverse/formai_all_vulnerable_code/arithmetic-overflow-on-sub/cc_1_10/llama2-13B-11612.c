//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum, product, square;
    char operation;

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operation from the user (either '+', '-', '*', or '/')
    printf("Enter the operation (+, -, *, or /): ");
    scanf(" %c", &operation);

    // Perform the operation
    if (operation == '+') {
        sum = num1 + num2;
    } else if (operation == '-') {
        sum = num1 - num2;
    } else if (operation == '*') {
        product = num1 * num2;
    } else if (operation == '/') {
        if (num2 == 0) {
            printf("Error: division by zero!\n");
            return 1;
        }
        square = num1 * num1;
        sum = num1 / num2;
    } else {
        printf("Error: invalid operation!\n");
        return 1;
    }

    // Print the result
    printf("The result of %d %c %d is %d\n", num1, operation, num2, sum);

    // Print some more information
    printf("The square of %d is %d\n", num1, square);

    // Print the product of the two numbers
    printf("The product of %d and %d is %d\n", num1, num2, product);

    // Print the magic number
    printf("The magic number is %d\n", MAGIC_NUMBER);

    return 0;
}