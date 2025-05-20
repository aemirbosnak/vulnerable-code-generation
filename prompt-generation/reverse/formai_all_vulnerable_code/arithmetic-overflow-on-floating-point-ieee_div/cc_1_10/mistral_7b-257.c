//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define NUM_ITERATIONS 10000000
#define NUM_DIGITS 20
#define SQUARE_NUMBER ((long long) pow(10, NUM_DIGITS) * 2)

typedef struct {
    char name[50];
    double time_taken;
} benchmark_result_t;

void my_sqrt(double x, double* result) {
    double guess = x / 2.0;
    double error = 1.0;

    while (error > 1e-15) {
        double temp = guess * (guess + x / guess);
        error = fabs(guess - result[0]) / fabs(guess);
        guess = temp;
    }

    *result = guess;
}

void print_benchmark_result(benchmark_result_t result) {
    printf("%s: %.16f seconds\n", result.name, result.time_taken);
}

int main() {
    double x = (double) SQUARE_NUMBER;
    double result;

    double start_time = clock();

    double result_array[1];
    my_sqrt(x, result_array);

    double end_time = clock();
    double time_taken = (end_time - start_time) / CLOCKS_PER_SEC;

    benchmark_result_t benchmark_result = {
        "Square root of ",
        time_taken
    };

    printf("Square root of %lld is %lf\n", SQUARE_NUMBER, result_array[0]);
    print_benchmark_result(benchmark_result);

    return 0;
}