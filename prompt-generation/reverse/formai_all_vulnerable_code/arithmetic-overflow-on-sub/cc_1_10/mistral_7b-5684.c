//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define MAX_N 50000000
#define NUM_RUNS 10

typedef uint64_t fib_t;

// Function to calculate Fibonacci number using recursion
fib_t fib(fib_t n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    clock_t start, end;
    double total_time = 0.0;
    fib_t n;

    // Initialize random seed for varying n value
    srand(time(NULL));

    // Run benchmark for given number of runs
    for (int i = 0; i < NUM_RUNS; i++) {
        // Generate random number between 1 and MAX_N
        n = (fib_t)(rand() % (MAX_N - 1)) + 1;

        // Start clock before calculation
        start = clock();

        // Calculate Fibonacci number
        fib_t fib_num = fib(n);

        // End clock after calculation
        end = clock();

        // Calculate time taken for current calculation
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Add time taken to total time
        total_time += time_taken;

        // Print Fibonacci number and time taken
        printf("Fibonacci(%llu) = %llu, Time taken: %f seconds\n", n, fib_num, time_taken);
    }

    // Print average time taken for all calculations
    printf("Average time taken: %f seconds\n", total_time / NUM_RUNS);

    return 0;
}