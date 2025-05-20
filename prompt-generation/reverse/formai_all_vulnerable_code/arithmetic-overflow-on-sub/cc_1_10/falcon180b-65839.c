//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate the factorial of a number
long long factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Function to calculate the nth Fibonacci number
long long fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to calculate the sum of the first n odd numbers
long long sum_of_odd_numbers(int n) {
    return (2 * n - 1) * n / 2;
}

// Function to calculate the sum of the first n even numbers
long long sum_of_even_numbers(int n) {
    return n * (2 * n - 1);
}

// Function to benchmark the performance of the above functions
void benchmark() {
    int n;
    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    for (int i = 0; i < n; i++) {
        factorial(10);
        fibonacci(10);
        sum_of_odd_numbers(10);
        sum_of_even_numbers(10);
    }
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("CPU time used: %lf seconds\n", cpu_time_used);
}

int main() {
    benchmark();
    return 0;
}