//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// Function to print Fibonacci numbers in an array
void print_fibonacci(int n) {
    if (n < 1) {
        return;
    }
    long long *fib = (long long *)malloc(n * sizeof(long long));
    if (fib == NULL) {
        perror("Unable to allocate memory");
        exit(EXIT_FAILURE);
    }

    fib[0] = 0;
    if (n > 1) {
        fib[1] = 1;
    }

    // Iteratively calculate Fibonacci numbers
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Print Fibonacci numbers
    printf("Fibonacci Series:\n");
    for (int i = 0; i < n; i++) {
        printf("%lld ", fib[i]);
    }
    printf("\n");

    free(fib);
}

// Function to calculate Fibonacci numbers using parallelization
void parallel_fibonacci(int n) {
    if (n < 1) {
        return;
    }
    long long *fib = (long long *)malloc(n * sizeof(long long));
    if (fib == NULL) {
        perror("Unable to allocate memory");
        exit(EXIT_FAILURE);
    }

    fib[0] = 0;
    if (n > 1) {
        fib[1] = 1;
    }

    // Parallelize the Fibonacci calculation
#pragma omp parallel for
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Print Fibonacci numbers
    printf("Fibonacci Series (Parallel):\n");
    for (int i = 0; i < n; i++) {
        printf("%lld ", fib[i]);
    }
    printf("\n");

    free(fib);
}


int main() {
    int n;

    printf("Enter the number of Fibonacci terms to display: ");
    scanf("%d", &n);

    // Get Fibonacci series
    print_fibonacci(n);

    // Get Parallel Fibonacci series
    parallel_fibonacci(n);

    return 0;
}