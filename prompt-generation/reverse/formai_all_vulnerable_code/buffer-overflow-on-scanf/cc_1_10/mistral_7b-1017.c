//MISTRAL-7B DATASET v1.0 Category: Performance-Critical Component ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_FIB_NUM 45 // Maximum Fibonacci number to calculate

// Function to calculate nth Fibonacci number using recursion
unsigned long long fib_recursive(unsigned int n) {
    if (n <= 1)
        return n;

    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

// Function to calculate nth Fibonacci number using memoization
unsigned long long fib_memoization(unsigned int n, unsigned long long memo[MAX_FIB_NUM + 1]) {
    if (n <= 1)
        return n;

    if (memo[n] != 0)
        return memo[n];

    memo[n] = fib_memoization(n - 1, memo) + fib_memoization(n - 2, memo);

    return memo[n];
}

int main() {
    unsigned long long start_time, end_time, fib_num;
    unsigned long long memo[MAX_FIB_NUM + 1] = { 0 };

    printf("Enter the Fibonacci number to calculate: ");
    scanf("%llu", &fib_num);

    // Measuring the execution time for recursive function
    start_time = clock();
    fib_num = fib_recursive(fib_num);
    end_time = clock();

    printf("Fibonacci number using recursion: %llu\n", fib_num);
    printf("Time taken by recursive function: %.6f ms\n", (end_time - start_time) / (double)CLOCKS_PER_SEC);

    // Resetting the start time for memoization function
    memset(memo, 0, sizeof(memo));
    start_time = clock();
    fib_num = fib_memoization(fib_num, memo);
    end_time = clock();

    printf("Fibonacci number using memoization: %llu\n", fib_num);
    printf("Time taken by memoization function: %.6f ms\n", (end_time - start_time) / (double)CLOCKS_PER_SEC);

    return 0;
}