//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    int number1, number2, sum, difference, product, quotient, remainder;
    char operation;

    printf("Welcome to the Arithmetic Adventure!\n");

    // Initialize variables
    number1 = 10;
    number2 = 20;
    sum = 0;
    difference = 0;
    product = 0;
    quotient = 0;
    remainder = 0;

    // Get operation from user
    printf("Enter an operation (+, -, x, /): ");
    scanf("%c", &operation);

    // Perform operation
    if (operation == '+') {
        sum = number1 + number2;
    } else if (operation == '-') {
        difference = number1 - number2;
    } else if (operation == '*') {
        product = number1 * number2;
    } else if (operation == '/') {
        quotient = number1 / number2;
        remainder = number1 % number2;
    }

    // Print results
    printf("Result of %d + %d is %d\n", number1, number2, sum);
    printf("Result of %d - %d is %d\n", number1, number2, difference);
    printf("Result of %d x %d is %d\n", number1, number2, product);
    printf("Result of %d / %d is %d with remainder %d\n", number1, number2, quotient, remainder);

    // Add some magic
    if (sum == MAGIC_NUMBER || difference == MAGIC_NUMBER || product == MAGIC_NUMBER || quotient == MAGIC_NUMBER) {
        printf("Congratulations! You found the magic number %d!\n", MAGIC_NUMBER);
    }

    return 0;
}