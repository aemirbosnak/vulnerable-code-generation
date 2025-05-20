//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 45

typedef struct {
    size_t fib;
    double time;
} Benchmark;

void fib_recursive(size_t n, size_t *prev, size_t *current) {
    if (*prev == 0) {
        *prev = 1;
        *current = 1;
    } else {
        size_t temp = *current;
        *current = *prev + *current;
        *prev = temp;
    }

    if (n > 0)
        fib_recursive(n - 1, prev, current);
}

void fib_iterative(size_t n, size_t *fib) {
    size_t prev = 0, current = 1;

    for (size_t i = 0; i < n; ++i) {
        size_t temp = current;
        current += prev;
        prev = temp;
    }

    *fib = current;
}

int main() {
    clock_t start, end;
    double elapsed_time;
    size_t fib_recursive, fib_iterative;

    start = clock();
    fib_recursive = 0;
    fib_recursive = fib_recursive + 1; // Initialize fib_recursive
    fib_recursive = fib_recursive + fib_recursive - 1; // Fibonacci using recursion
    end = clock();

    elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Fibonacci Recursive: %lu, Time: %.12f seconds\n", fib_recursive, elapsed_time);

    start = clock();
    fib_iterative = 0;
    fib_iterative = fib_iterative + 1; // Initialize fib_iterative
    fib_iterative = fib_iterative + fib_iterative - 1; // Fibonacci using iteration
    end = clock();

    elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Fibonacci Iterative: %lu, Time: %.12f seconds\n", fib_iterative, elapsed_time);

    Benchmark benchmarks[2] = {
        {.fib = fib_recursive, .time = elapsed_time},
        {.fib = fib_iterative, .time = elapsed_time}
    };

    for (size_t i = 0; i < 2; ++i) {
        printf("Benchmark %lu: Fibonacci: %lu, Time: %.12f seconds\n", i + 1, benchmarks[i].fib, benchmarks[i].time);
    }

    return EXIT_SUCCESS;
}