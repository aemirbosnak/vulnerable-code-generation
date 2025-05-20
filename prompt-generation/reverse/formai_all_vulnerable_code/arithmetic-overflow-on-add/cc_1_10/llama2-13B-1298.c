//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUMBER 100000
#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum, product, quotient, remainder;
    char op;

    // Initialize variables
    num1 = 0;
    num2 = 0;
    sum = 0;
    product = 0;
    quotient = 0;
    remainder = 0;
    op = '+';

    // Get input from user
    printf("Enter two numbers: ");
    scanf("%d%c", &num1, &op);
    printf("Enter another number: ");
    scanf("%d", &num2);

    // Perform math operations
    if (op == '+') {
        sum = num1 + num2;
    } else if (op == '-') {
        sum = num1 - num2;
    } else if (op == '*') {
        product = num1 * num2;
    } else if (op == '/') {
        quotient = num1 / num2;
        remainder = num1 % num2;
    }

    // Print results
    printf("Result of %d + %d = %d\n", num1, num2, sum);
    printf("Result of %d * %d = %d\n", num1, num2, product);
    printf("Result of %d / %d = %d with remainder %d\n", num1, num2, quotient, remainder);

    // Generate a random magic number
    int magic = (int) (rand() % MAGIC_NUMBER) + 1;

    // Check if the result of the math operations is equal to the magic number
    if (sum == magic || product == magic || quotient == magic || remainder == magic) {
        printf("Congratulations! You have found the magic number %d!\n", magic);
    } else {
        printf("Too bad, the result is not the magic number %d.\n", magic);
    }

    return 0;
}