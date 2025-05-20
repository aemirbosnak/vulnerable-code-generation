//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))

// Function to calculate Fibonacci sequence recursively
int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

// Function to calculate the elapsed time in microseconds
unsigned long long microseconds() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (unsigned long long)ts.tv_sec * 1000000 + ts.tv_nsec;
}

int main() {
    int n;
    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%d", &n);

    unsigned long long start, end;

    // Generate Fibonacci sequence
    printf("Fibonacci sequence of length %d:\n", n);
    for (int i = 0; i < n; ++i) {
        int fib_number = fib(i);
        printf("%d ", fib_number);
    }
    printf("\n");

    // Measure the time taken to generate the Fibonacci sequence
    start = microseconds();

    // Generate the Fibonacci sequence again
    for (int i = 0; i < n; ++i) {
        int fib_number = fib(i);
    }

    end = microseconds();

    // Print the time taken in microseconds
    unsigned long long time_taken = end - start;
    printf("Time taken to generate the Fibonacci sequence of length %d: %llu microseconds.\n", n, time_taken);

    return 0;
}