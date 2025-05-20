//Falcon-180B DATASET v1.0 Category: Error handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

int main(int argc, char* argv[]) {
    int i, j, n;
    double x, y, z;

    // check for correct number of arguments
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <number of terms> <value of x>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // check for valid value of x
    if (fabs(atof(argv[2])) >= 1) {
        fprintf(stderr, "Invalid value of x\n");
        exit(EXIT_FAILURE);
    }

    // get number of terms from command line argument
    n = atoi(argv[1]);

    // calculate sum of series
    printf("Series: ");
    for (i = 0; i < n; i++) {
        x = pow(-1, i);
        y = pow(x, 3.0);
        z = y / (3.0 * factorial(i));
        printf("%.4f ", z);
    }
    printf("\n");

    return 0;
}

int factorial(int n) {
    int i, result = 1;

    for (i = 1; i <= n; i++) {
        if (i > 12) {
            fprintf(stderr, "Error: Factorial of %d is too large\n", n);
            exit(EXIT_FAILURE);
        }
        result *= i;
    }

    return result;
}