//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the factorial of a number
long long int factorial(int n);

// Function to calculate the nth Fibonacci number
double fibonacci(int n);

// Function to calculate the sum of the series 1/n^2
double series_sum(int n);

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    // Calculate and print the factorial of n
    printf("Factorial of %d: %lld\n", n, factorial(n));

    // Calculate and print the nth Fibonacci number
    printf("Fibonacci number: %.2lf\n", fibonacci(n));

    // Calculate and print the sum of the series 1/n^2
    printf("Series sum: %.2lf\n", series_sum(n));

    return 0;
}

// Function to calculate the factorial of a number
long long int factorial(int n) {
    long long int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate the nth Fibonacci number
double fibonacci(int n) {
    double a = 1, b = 1, c;
    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// Function to calculate the sum of the series 1/n^2
double series_sum(int n) {
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += 1/pow(i, 2);
    }
    return sum;
}