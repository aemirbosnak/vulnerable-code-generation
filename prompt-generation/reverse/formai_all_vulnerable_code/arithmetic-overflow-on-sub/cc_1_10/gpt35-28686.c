//FormAI DATASET v1.0 Category: Error handling ; Style: artistic
/* Artistic C Error Handling Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {

    // Define variables
    int num, denom, result;
    char op;

    // Prompt user for input
    printf("Please enter an expression in the form of num op denom: ");
    scanf("%d %c %d", &num, &op, &denom);

    // Check if denominator is zero
    if (denom == 0) {
        printf("Oops! The denominator cannot be zero.\n");
        exit(EXIT_FAILURE);
    }

    // Calculate result based on operator
    switch (op) {
        case '+':
            result = num + denom;
            break;
        case '-':
            result = num - denom;
            break;
        case '*':
            result = num * denom;
            break;
        case '/':
            result = num / denom;
            break;
        default:
            printf("Oops! %c is not a valid operator.\n", op);
            exit(EXIT_FAILURE);
    }

    // Check for overflow
    if (result < num || result < denom) {
        printf("Oops! The result is too large to be represented.\n");
        exit(EXIT_FAILURE);
    }

    // Print the result
    printf("The result of %d %c %d is %d.\n", num, op, denom, result);

    return 0;
}

/* End of program */