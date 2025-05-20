//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUMBER 1000000
#define MIN_NUMBER -1000000

int main() {
    int num1, num2, sum, diff, mult, div, mod;
    char op;

    // Initialize variables
    num1 = 0;
    num2 = 0;
    sum = 0;
    diff = 0;
    mult = 0;
    div = 0;
    mod = 0;
    op = '+';

    // Get two numbers from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Check if the numbers are valid
    if (num1 < MIN_NUMBER || num1 > MAX_NUMBER || num2 < MIN_NUMBER || num2 > MAX_NUMBER) {
        printf("Invalid input. Please enter valid numbers.\n");
        return 1;
    }

    // Perform arithmetic operations
    switch (op) {
        case '+':
            sum = num1 + num2;
            break;
        case '-':
            diff = num1 - num2;
            break;
        case '*':
            mult = num1 * num2;
            break;
        case '/':
            div = num1 / num2;
            break;
        case '%':
            mod = num1 % num2;
            break;
        default:
            printf("Invalid operator. Please enter a valid operator (+, -, *, /, or %).\n");
            return 1;
    }

    // Print the results
    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", diff);
    printf("Product: %d\n", mult);
    printf("Quotient: %d\n", div);
    printf("Modulus: %d\n", mod);

    return 0;
}