//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LEN 1024
#define EPS 1e-6

int main() {
    double x, y, z;
    char str[MAX_LEN];

    // Example 1: Divide by zero error
    x = 10;
    y = 0;
    z = x / y;
    if (z == INFINITY) {
        printf("Error: Division by zero detected! (x / y = INFINITY)\n");
    } else {
        printf("Result: z = %f\n", z);
    }

    // Example 2: Negative number error
    x = -10;
    y = 10;
    z = x / y;
    if (z == -INFINITY) {
        printf("Error: Negative number detected! (x / y = -INFINITY)\n");
    } else {
        printf("Result: z = %f\n", z);
    }

    // Example 3: Nan (Not a Number) error
    x = NAN;
    y = 10;
    z = x / y;
    if (z != NAN) {
        printf("Error: Nan detected! (x / y = %f, expected NAN)\n", z);
    } else {
        printf("Result: z = %f\n", z);
    }

    // Example 4: Underflow error
    x = 1000000;
    y = -1000000;
    z = x / y;
    if (z == 0) {
        printf("Error: Underflow detected! (x / y = 0)\n");
    } else {
        printf("Result: z = %f\n", z);
    }

    // Example 5: Overflow error
    x = 1000000000;
    y = -1000000000;
    z = x / y;
    if (z == INFINITY) {
        printf("Error: Overflow detected! (x / y = INFINITY)\n");
    } else {
        printf("Result: z = %f\n", z);
    }

    // Example 6: Special value error
    x = 1.0 / 0.0;
    if (x == INFINITY) {
        printf("Error: Special value detected! (1.0 / 0.0 = INFINITY)\n");
    } else {
        printf("Result: x = %f\n", x);
    }

    return 0;
}