//Falcon-180B DATASET v1.0 Category: Error handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <errno.h>
#include <assert.h>
#include <err.h>

int main() {
    double x, y, result;
    int err;

    // Prompt user for input
    printf("Enter a number: ");
    if (scanf("%lf", &x)!= 1) {
        errx(1, "Invalid input");
    }

    // Check for divide by zero error
    if (x == 0) {
        errx(1, "Divide by zero error");
    }

    // Prompt user for second input
    printf("Enter another number: ");
    if (scanf("%lf", &y)!= 1) {
        errx(1, "Invalid input");
    }

    // Check for overflow error
    if (isnan(x) || isnan(y)) {
        errx(1, "Overflow error");
    }

    // Perform division
    if (y == 0) {
        errx(1, "Divide by zero error");
    }
    result = x / y;

    // Check for underflow error
    if (isnan(result) || isinf(result)) {
        errx(1, "Underflow error");
    }

    // Print result
    printf("The result is %.2lf\n", result);

    return 0;
}