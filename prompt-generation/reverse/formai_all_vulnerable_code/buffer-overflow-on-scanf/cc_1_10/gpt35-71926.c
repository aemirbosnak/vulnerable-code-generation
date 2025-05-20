//FormAI DATASET v1.0 Category: Error handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>

/* custom error codes */
#define DIV_ZERO_ERROR 1
#define BAD_INPUT_ERROR 2

/* function prototypes */
int divide(int, int);
int safe_read_int();

/* program entry point */
int main() {
    int dividend, divisor, quotient;

    /* read dividend and divisor from user */
    printf("Enter the dividend: ");
    dividend = safe_read_int();
    printf("Enter the divisor: ");
    divisor = safe_read_int();

    /* try to perform division */
    if (divisor == 0) {
        printf("Error: Division by zero.\n");
        exit(DIV_ZERO_ERROR);
    } else {
        quotient = divide(dividend, divisor);
        printf("Result: %d\n", quotient);
    }

    return 0;
}

/***** function definitions *****/

/* divide two integers */
int divide(int a, int b) {
    return a / b;
}

/* read an integer from stdin */
int safe_read_int() {
    int num;
    char term;

    if (scanf("%d%c", &num, &term) != 2 || term != '\n') {
        printf("Error: Invalid input.\n");
        exit(BAD_INPUT_ERROR);
    }

    return num;
}