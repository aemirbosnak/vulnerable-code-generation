//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 100
#define EPSILON 0.00001
#define MIN_NUMBER 0.0

void error_message(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

double square_root(double number) {
    double guess, last_guess, result;

    if (number < MIN_NUMBER) {
        error_message("Error: The number must be non-negative.\n");
    }

    guess = number / 2.0;
    last_guess = NAN;

    for (int i = 0; i < MAX_ITERATIONS; i++) {
        result = guess * (1.0 - ((guess * guess) - number) / (2.0 * guess));

        if (isnan(last_guess) || fabs(guess - result) < EPSILON) {
            last_guess = guess;
            break;
        }

        guess = result;
    }

    return result;
}

int main(int argc, char *argv[]) {
    double number;

    if (argc != 2) {
        error_message("Error: Please provide a number as a command-line argument.\n");
    }

    number = atof(argv[1]);

    if (isnan(number)) {
        error_message("Error: Invalid number provided as a command-line argument.\n");
    }

    printf("The square root of %.2lf is %.2lf\n", number, square_root(number));

    return 0;
}