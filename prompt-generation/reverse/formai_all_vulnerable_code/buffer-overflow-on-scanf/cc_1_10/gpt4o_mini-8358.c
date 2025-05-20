//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: recursive
#include <stdio.h>
#include <time.h>

// Recursive function to calculate the nth Fibonacci number
unsigned long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to benchmark the execution time of the Fibonacci function
void benchmark_fibonacci(int n) {
    clock_t start_time, end_time;
    double time_taken;

    // Start the clock
    start_time = clock();
    
    // Calculate Fibonacci number
    unsigned long long result = fibonacci(n);
    
    // Stop the clock
    end_time = clock();

    // Calculate the time taken in seconds
    time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    // Output the result and time taken
    printf("Fibonacci(%d) = %llu\n", n, result);
    printf("Time taken to compute Fibonacci(%d) = %f seconds\n", n, time_taken);
}

int main() {
    int n;

    printf("Enter a positive integer (to compute Fibonacci): ");
    scanf("%d", &n);

    // Input validation
    if (n < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }

    // Benchmark the Fibonacci function
    benchmark_fibonacci(n);
    
    return 0;
}