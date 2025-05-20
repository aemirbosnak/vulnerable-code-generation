//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum, product, difference, quotient, remainder;
    char operation;

    printf("Welcome to the Arithmetic Playground!\n");

    // Initialize variables
    num1 = 5;
    num2 = 10;
    sum = 0;
    product = 0;
    difference = 0;
    quotient = 0;
    remainder = 0;

    // Get operation from user
    printf("Enter an operation (+, -, x, /): ");
    scanf("%c", &operation);

    // Perform operation
    switch (operation) {
        case '+':
            sum = num1 + num2;
            break;
        case '-':
            difference = num1 - num2;
            break;
        case '*':
            product = num1 * num2;
            break;
        case '/':
            quotient = num1 / num2;
            remainder = num1 % num2;
            break;
        default:
            printf("Invalid operation! Please try again.\n");
            return 1;
    }

    // Print results
    printf("Result of %d + %d is %d\n", num1, num2, sum);
    printf("Result of %d - %d is %d\n", num1, num2, difference);
    printf("Result of %d * %d is %d\n", num1, num2, product);
    printf("Result of %d / %d is %d with remainder %d\n", num1, num2, quotient, remainder);

    // Add some magic
    if (sum == MAGIC_NUMBER || product == MAGIC_NUMBER || quotient == MAGIC_NUMBER) {
        printf("Congratulations! You have found the %s of %d and %d!\n",
               (sum == MAGIC_NUMBER) ? "sum" : (product == MAGIC_NUMBER) ? "product" : "quotient",
               num1, num2);
    }

    return 0;
}