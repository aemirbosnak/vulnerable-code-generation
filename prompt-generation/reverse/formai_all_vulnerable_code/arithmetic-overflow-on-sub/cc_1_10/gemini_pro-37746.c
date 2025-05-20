//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

// Function prototypes
uint64_t fib_recursive(uint64_t n);
uint64_t fib_iterative(uint64_t n);
uint64_t fib_matrix(uint64_t n);

// Benchmarking function
void benchmark(uint64_t (*fib)(uint64_t), uint64_t n) {
    clock_t start, end;
    double time_taken;

    // Start the clock
    start = clock();

    // Call the Fibonacci function
    fib(n);

    // Stop the clock
    end = clock();

    // Calculate the time taken
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the results
    printf("Time taken for n = %llu: %lf seconds\n", n, time_taken);
}

// Main function
int main() {
    uint64_t n;

    // Get the value of n from the user
    printf("Enter the value of n: ");
    scanf("%llu", &n);

    // Benchmark the three Fibonacci functions
    benchmark(fib_recursive, n);
    benchmark(fib_iterative, n);
    benchmark(fib_matrix, n);

    return 0;
}

// Recursive Fibonacci function
uint64_t fib_recursive(uint64_t n) {
    if (n <= 1) {
        return n;
    } else {
        return fib_recursive(n - 1) + fib_recursive(n - 2);
    }
}

// Iterative Fibonacci function
uint64_t fib_iterative(uint64_t n) {
    uint64_t a = 0, b = 1, c;

    for (uint64_t i = 0; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

// Matrix Fibonacci function
uint64_t fib_matrix(uint64_t n) {
    // Define the base cases
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }

    // Define the matrix
    uint64_t F[2][2] = {{1, 1}, {1, 0}};

    // Raise the matrix to the power of n
    for (uint64_t i = 2; i <= n; i++) {
        uint64_t temp[2][2];

        temp[0][0] = (F[0][0] * F[0][0] + F[0][1] * F[1][0]) % 1000000007;
        temp[0][1] = (F[0][0] * F[0][1] + F[0][1] * F[1][1]) % 1000000007;
        temp[1][0] = (F[1][0] * F[0][0] + F[1][1] * F[1][0]) % 1000000007;
        temp[1][1] = (F[1][0] * F[0][1] + F[1][1] * F[1][1]) % 1000000007;

        F[0][0] = temp[0][0];
        F[0][1] = temp[0][1];
        F[1][0] = temp[1][0];
        F[1][1] = temp[1][1];
    }

    // Return the result
    return F[0][0];
}