//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: ultraprecise
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define EPSILON 1.0e-15
#define MAX_ITERATIONS 100

typedef struct {
    double value;
    char status;
} CalculationResult;

void handle_error(const char *msg) {
    fprintf(stderr, "[ERROR]: %s\n", msg);
}

CalculationResult sqrt_calculation(double number) {
    CalculationResult result = {number, 'S'};

    if (number < 0.0) {
        handle_error("Input must be non-negative");
        return result;
    }

    double x0 = number / 2.0;
    double x1;
    int iterations = 0;

    do {
        x1 = x0 - ((x0 * x0) - number) / (2 * x0);
        iterations++;
        x0 = x1;
    } while ((fabs(x1 - x0) > EPSILON) && (iterations < MAX_ITERATIONS));

    if (iterations == MAX_ITERATIONS) {
        handle_error("Maximum iterations reached");
        result.status = 'I';
    } else {
        result.value = x1;
        result.status = 'C';
    }

    return result;
}

int main() {
    double number;
    CalculationResult calculation_result;

    printf("Enter a non-negative number: ");
    scanf("%lf", &number);

    calculation_result = sqrt_calculation(number);

    if (calculation_result.status == 'S') {
        printf("Error: %s\n", calculation_result.status == 'S' ? "Invalid input" : calculation_result.status == 'I' ? "Maximum iterations reached" : "");
    } else {
        printf("The square root of %.2lf is %.2lf\n", number, calculation_result.value);
    }

    return 0;
}