//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the sum of the series 1 + 1/2 + 1/3 +... + 1/n
double harmonic_series(int n) {
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += 1.0 / i;
    }
    return sum;
}

// Function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate the nth Fibonacci number using recursion
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    // Example usage of the harmonic_series function
    int n;
    printf("Enter the number of terms to sum in the harmonic series: ");
    scanf("%d", &n);
    double sum = harmonic_series(n);
    printf("The sum of the first %d terms of the harmonic series is: %.6f\n", n, sum);

    // Example usage of the factorial function
    int m;
    printf("Enter a number to calculate the factorial of: ");
    scanf("%d", &m);
    int result = factorial(m);
    printf("The factorial of %d is: %d\n", m, result);

    // Example usage of the fibonacci function
    int k;
    printf("Enter the nth Fibonacci number to calculate: ");
    scanf("%d", &k);
    int fib = fibonacci(k);
    printf("The %dth Fibonacci number is: %d\n", k, fib);

    return 0;
}