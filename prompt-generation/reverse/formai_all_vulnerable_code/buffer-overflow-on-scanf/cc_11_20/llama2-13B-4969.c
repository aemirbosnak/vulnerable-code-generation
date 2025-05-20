//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum, diff, mult, div;
    char op;

    printf("Welcome to the Arithmetic Adventure! \n");

    // Initialize variables
    num1 = 5;
    num2 = 10;
    sum = 0;
    diff = 0;
    mult = 1;
    div = 1;

    // Get the first operation from the user
    printf("Enter the first operation (+, -, x, /): ");
    scanf("%c", &op);

    // Perform the operation
    if (op == '+') {
        sum = num1 + num2;
    } else if (op == '-') {
        diff = num1 - num2;
    } else if (op == '*') {
        mult = num1 * num2;
    } else if (op == '/') {
        div = num1 / num2;
    }

    // Display the results
    printf("Result of %d + %d is %d\n", num1, num2, sum);
    printf("Result of %d - %d is %d\n", num1, num2, diff);
    printf("Result of %d * %d is %d\n", num1, num2, mult);
    printf("Result of %d / %d is %d\n", num1, num2, div);

    // Check if the user wants to continue
    printf("Do you want to continue? (y/n): ");
    scanf(" %c", &op);

    // Loop until the user says no
    while (op == 'y' || op == 'Y') {
        // Get the next operation from the user
        printf("Enter the next operation (+, -, x, /): ");
        scanf("%c", &op);

        // Perform the operation
        if (op == '+') {
            sum = num1 + num2;
        } else if (op == '-') {
            diff = num1 - num2;
        } else if (op == '*') {
            mult = num1 * num2;
        } else if (op == '/') {
            div = num1 / num2;
        }

        // Display the results
        printf("Result of %d + %d is %d\n", num1, num2, sum);
        printf("Result of %d - %d is %d\n", num1, num2, diff);
        printf("Result of %d * %d is %d\n", num1, num2, mult);
        printf("Result of %d / %d is %d\n", num1, num2, div);

        // Check if the user wants to continue
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &op);
    }

    // End the program
    printf("Thank you for playing the Arithmetic Adventure! \n");

    return 0;
}