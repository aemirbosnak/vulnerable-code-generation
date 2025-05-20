//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate Fibonacci numbers recursively
unsigned long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to measure execution time
double measure_time(int n) {
    clock_t start, end;
    start = clock();
    
    unsigned long long result = fibonacci(n);
    
    end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("Fibonacci(%d) = %llu\n", n, result);
    
    return time_spent;
}

// Function to measure memory usage (approximation)
void measure_memory() {
    // Normally, we might use getrusage, but for this benchmark, we'll print a simple message
    printf("Memory usage measurement is system-dependent and varies with implementation.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <n>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    int n = atoi(argv[1]);
    
    if (n < 0) {
        fprintf(stderr, "Please enter a non-negative integer for Fibonacci computation.\n");
        exit(EXIT_FAILURE);
    }
    
    // Measure execution time for the Fibonacci calculation
    double execution_time = measure_time(n);
    printf("Execution time for Fibonacci(%d): %.6f seconds\n", n, execution_time);
    
    // Measure memory usage
    measure_memory();
    
    return 0;
}