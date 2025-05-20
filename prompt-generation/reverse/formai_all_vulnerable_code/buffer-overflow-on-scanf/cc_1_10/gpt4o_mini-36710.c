//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to compute the sum of squares of integers up to n
long long sum_of_squares(int n) {
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += (long long)i * i;
    }
    return sum;
}

// Function to compute the factorial of n
long long factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

// Function to perform the benchmarking
void benchmark(int n) {
    clock_t start, end;
    double cpu_time_used;

    // Benchmark sum of squares
    start = clock();
    long long sum_squares = sum_of_squares(n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Sum of squares up to %d: %lld\n", n, sum_squares);
    printf("Time taken for sum of squares: %f seconds\n\n", cpu_time_used);
    
    // Benchmark factorial
    start = clock();
    long long fact = factorial(n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Factorial of %d: %lld\n", n, fact);
    printf("Time taken for factorial: %f seconds\n", cpu_time_used);
}

int main() {
    int n;

    // Welcome message
    printf("Welcome to the peaceful benchmarking program!\n");
    printf("This program will compute the sum of squares and the factorial of a number.\n");
    printf("Please enter a positive integer: ");
    
    // Read user input
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid input! Please enter a positive integer.\n");
        return EXIT_FAILURE;
    }
    
    // Begin benchmarking
    benchmark(n);
    
    // Farewell message
    printf("Thank you for using the benchmarking program. Have a serene day ahead!\n");
    
    return EXIT_SUCCESS;
}