//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long recursiveFibonacci(int n) {
    if (n <= 1) return n;
    return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
}

unsigned long long iterativeFibonacci(int n) {
    if (n <= 1) return n;
    unsigned long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

void measureTime(int n) {
    // Measure recursive Fibonacci
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    unsigned long long rec_result = recursiveFibonacci(n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Recursive Fibonacci of %d is %llu, calculated in %f seconds\n", n, rec_result, cpu_time_used);

    // Measure iterative Fibonacci
    start = clock();
    unsigned long long iter_result = iterativeFibonacci(n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Iterative Fibonacci of %d is %llu, calculated in %f seconds\n", n, iter_result, cpu_time_used);
}

int main() {
    int n;

    printf("Enter a number to calculate Fibonacci: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Please enter a non-negative integer.\n");
        return EXIT_FAILURE;
    }

    printf("---Fibonacci Calculation---\n");
    measureTime(n);

    return EXIT_SUCCESS;
}