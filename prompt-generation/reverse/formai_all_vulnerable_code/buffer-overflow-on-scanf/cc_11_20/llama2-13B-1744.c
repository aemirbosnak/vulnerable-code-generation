//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum;
    char op;

    // Initialize variables
    num1 = 13;
    num2 = 27;
    op = '+';

    // Perform arithmetic operations
    if (op == '+') {
        sum = num1 + num2;
    } else if (op == '-') {
        sum = num1 - num2;
    } else if (op == '*') {
        sum = num1 * num2;
    } else if (op == '/') {
        sum = num1 / num2;
    } else if (op == '%') {
        sum = num1 % num2;
    } else {
        sum = MAGIC_NUMBER;
    }

    // Print results
    printf("Result: %d\n", sum);

    // Ask user for next input
    printf("Enter a number (or 'q' to quit): ");
    scanf("%d%c", &num1, &op);

    // Repeat arithmetic operations until 'q' is entered
    while (op != 'q') {
        // Perform arithmetic operations again
        if (op == '+') {
            sum = num1 + num2;
        } else if (op == '-') {
            sum = num1 - num2;
        } else if (op == '*') {
            sum = num1 * num2;
        } else if (op == '/') {
            sum = num1 / num2;
        } else if (op == '%') {
            sum = num1 % num2;
        } else {
            sum = MAGIC_NUMBER;
        }

        // Print results
        printf("Result: %d\n", sum);

        // Ask user for next input
        printf("Enter a number (or 'q' to quit): ");
        scanf("%d%c", &num1, &op);
    }

    // Exit program when 'q' is entered
    if (op == 'q') {
        printf("Goodbye!\n");
        return 0;
    }

    return 1;
}