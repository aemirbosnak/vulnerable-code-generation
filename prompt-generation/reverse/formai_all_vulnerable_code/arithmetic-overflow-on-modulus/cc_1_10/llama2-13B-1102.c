//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUMBER 1000000
#define MIN_NUMBER 1

int main() {
    int num1, num2, sum, product, difference, quotient, remainder;
    char op;

    // Initialize variables
    num1 = 0;
    num2 = 0;
    sum = 0;
    product = 0;
    difference = 0;
    quotient = 0;
    remainder = 0;

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operator from the user
    printf("Enter the operator (+, -, x, /): ");
    scanf(" %c", &op);

    // Perform the arithmetic operation
    if (op == '+') {
        sum = num1 + num2;
    } else if (op == '-') {
        difference = num1 - num2;
    } else if (op == 'x') {
        product = num1 * num2;
    } else if (op == '/') {
        quotient = num1 / num2;
        remainder = num1 % num2;
    }

    // Print the results
    printf("The result of %d %c %d is %d\n", num1, op, num2, sum);

    // Print the remainder
    if (op == '/') {
        printf("The remainder is %d\n", remainder);
    }

    return 0;
}