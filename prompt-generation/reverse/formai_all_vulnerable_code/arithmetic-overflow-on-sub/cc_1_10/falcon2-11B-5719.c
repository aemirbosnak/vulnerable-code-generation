//Falcon2-11B DATASET v1.0 Category: Benchmarking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <omp.h>

#define NUM_ITERATIONS 1000000

// Function to calculate the square root using the Newton-Raphson method
double newton_raphson_sqrt(double x) {
    double y = x;
    double error = 1.0;

    for (int i = 0; i < NUM_ITERATIONS; i++) {
        double f = y - (x / y);
        y = (y + x / y) / 2.0;
        error = f * f;
    }

    return sqrt(y);
}

// Function to calculate the square root using the bisection method
double bisection_sqrt(double x) {
    double a = 0.0;
    double b = x;
    double c = (a + b) / 2.0;
    double eps = 1e-6;

    for (int i = 0; i < NUM_ITERATIONS; i++) {
        double f = b - (a * (a / b) / (c * (c / b)));
        if (f < eps) {
            return c;
        } else if (f > -eps) {
            b = c;
        } else {
            c = (a + b) / 2.0;
        }
    }
}

int main() {
    clock_t start_time, end_time;
    double newton_time, bisection_time;

    // Initialize the seed for random number generation
    srand(time(NULL));

    // Generate a random number to use as input for the square root calculation
    double x = (double)rand() / RAND_MAX;

    // Calculate the execution time for the Newton-Raphson method
    start_time = clock();
    newton_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;

    // Calculate the square root using the Newton-Raphson method
    double result = newton_raphson_sqrt(x);

    // Calculate the execution time for the bisection method
    start_time = clock();
    bisection_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;

    // Calculate the square root using the bisection method
    double result2 = bisection_sqrt(x);

    // Output the results
    printf("Newton-Raphson square root: %f\n", result);
    printf("Bisection square root: %f\n", result2);
    printf("Newton-Raphson time: %f seconds\n", newton_time);
    printf("Bisection time: %f seconds\n", bisection_time);

    return 0;
}