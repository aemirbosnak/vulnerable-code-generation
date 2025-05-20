//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum, product, square;
    char op;

    printf("Welcome to the Arithmetic Adventure! \n");

    // Initialize variables
    num1 = 10;
    num2 = 20;
    sum = 0;
    product = 1;
    square = 0;

    // Get operation from user
    printf("Enter operation (+, -, x, /): ");
    scanf(" %c", &op);

    // Perform arithmetic operations
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
    printf("Result of %d + %d is %d\n", num1, num2, sum);
    printf("Result of %d x %d is %d\n", num1, num2, product);
    printf("Result of %d / %d is %d\n", num1, num2, square);

    // Add some magic
    if (sum == MAGIC_NUMBER) {
        printf("Congratulations, you found the secret number! \n");
    }

    return 0;
}