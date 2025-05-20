//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate the factorial of a number using recursion
unsigned long long int Factorial(unsigned int n) {
    if (n == 0)
        return 1;
    else
        return n * Factorial(n - 1);
}

// Function to calculate the nth Fibonacci number using recursion
unsigned long long int Fibonacci(unsigned int n) {
    if (n <= 1)
        return n;
    else
        return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
    clock_t start, end;
    unsigned int n;

    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%d", &n);

    // Calculate the start time
    start = clock();

    // Print the Fibonacci sequence up to n numbers
    printf("Fibonacci sequence up to %d numbers:\n", n);
    unsigned long long int fibPrev = 0, fibCurrent = 1;
    for (unsigned int i = 0; i < n; ++i) {
        printf("%llu ", fibCurrent);
        unsigned long long int temp = fibCurrent;
        fibCurrent += fibPrev;
        fibPrev = temp;
    }
    printf("\n");

    // Calculate the end time
    end = clock();

    // Calculate the time taken to generate the Fibonacci sequence
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Calculate the nth Fibonacci number recursively
    unsigned int nth_Fibonacci = Fibonacci(n);

    // Print the time taken and the nth Fibonacci number
    printf("Time taken to generate %d numbers: %.16f seconds\n", n, time_taken);
    printf("nth Fibonacci number: %llu\n", nth_Fibonacci);

    return 0;
}

// Function to calculate the Fibonacci sequence iteratively (for comparison)
void IterativeFibonacci(unsigned int n) {
    unsigned long long int fibPrev = 0, fibCurrent = 1;
    for (unsigned int i = 0; i < n; ++i) {
        unsigned long long int temp = fibCurrent;
        fibCurrent += fibPrev;
        fibPrev = temp;
    }
}