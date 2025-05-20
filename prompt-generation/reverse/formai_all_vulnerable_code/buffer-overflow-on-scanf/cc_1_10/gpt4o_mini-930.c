//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_ITERATIONS 1e6

void benchmark_sqrt() {
    clock_t start = clock();
    for (long i = 0; i < NUM_ITERATIONS; i++) {
        sqrt(i);
    }
    clock_t end = clock();
    printf("Square root benchmark took: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
}

void benchmark_pow() {
    clock_t start = clock();
    for (long i = 0; i < NUM_ITERATIONS; i++) {
        pow(i, 2);
    }
    clock_t end = clock();
    printf("Power benchmark took: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
}

void benchmark_log() {
    clock_t start = clock();
    for (long i = 1; i < NUM_ITERATIONS + 1; i++) { // Start from 1 to avoid log(0)
        log(i);
    }
    clock_t end = clock();
    printf("Logarithm benchmark took: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
}

void benchmark_exp() {
    clock_t start = clock();
    for (long i = 0; i < NUM_ITERATIONS; i++) {
        exp(i);
    }
    clock_t end = clock();
    printf("Exponential benchmark took: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
}

void display_menu() {
    printf("Math Benchmarking Tool\n");
    printf("Choose an operation to benchmark:\n");
    printf("1. Square Root (sqrt)\n");
    printf("2. Power (pow)\n");
    printf("3. Logarithm (log)\n");
    printf("4. Exponential (exp)\n");
    printf("5. Exit\n");
}

int main() {
    while (1) {
        display_menu();
        int choice = 0;

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear the input buffer
            continue;
        }
        
        switch (choice) {
            case 1:
                benchmark_sqrt();
                break;
            case 2:
                benchmark_pow();
                break;
            case 3:
                benchmark_log();
                break;
            case 4:
                benchmark_exp();
                break;
            case 5:
                printf("Exiting the benchmark tool.\n");
                exit(0);
            default:
                printf("Unknown option. Please try again.\n");
                break;
        }
    }
    return 0;
}