//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 50 // Desired Fibonacci number

typedef struct {
    char name[32];
    double time;
} Benchmark;

void fib(int n, int *a, int *b) {
    if (n <= 2) {
        *a = n - 1;
        *b = 1;
    } else {
        int c;
        fib(n - 1, b, &c);
        *a = *b + *a;
        *b = c;
    }
}

int main() {
    clock_t start, end;
    double elapsed_time;
    int a = 0, b = 1, c;

    printf("Benchmarking recursive Fibonacci calculation with %d iterations...\n", N);

    start = clock();
    fib(N, &a, &b);
    end = clock();

    elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    Benchmark benchmark = {
        "Recursive Fibonacci",
        elapsed_time
    };

    printf("Recursive Fibonacci(%d) = %d\n", N, a);
    printf("Elapsed time: %.12fs\n", elapsed_time);

    printf("\nComparison with iterative approach:\n");

    start = clock();
    for (int i = 0; i <= N; i++) {
        int fib_iterative = a + b;
        a = b;
        b = fib_iterative;
    }
    end = clock();

    elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    Benchmark benchmark_iterative = {
        "Iterative Fibonacci",
        elapsed_time
    };

    printf("Iterative Fibonacci(%d) = %d\n", N, a);
    printf("Elapsed time: %.12fs\n", elapsed_time);

    // Comparing results and printing benchmark data
    if (a == fibonacci(N)) {
        printf("\nBoth approaches return the correct Fibonacci number.\n");
        printf("Benchmark comparison:\n");
        printf("-----------------------\n");
        printf("%s\t\t\t| %-32s\t| %-10s\n", "", "Function name", "Elapsed time (s)");
        printf("-----------------------\n");
        printf("%s\t\t\t| %-32s\t| %-10.12fs\n", "", benchmark.name, benchmark.time);
        printf("%s\t\t\t| %-32s\t| %-10.12fs\n", "", benchmark_iterative.name, benchmark_iterative.time);
    } else {
        printf("\nWarning: Iterative approach returns incorrect Fibonacci number!\n");
    }

    return 0;
}

// Iterative Fibonacci calculation for comparison
int fibonacci(int n) {
    int a = 0, b = 1, c;

    for (int i = 0; i <= N; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return a;
}