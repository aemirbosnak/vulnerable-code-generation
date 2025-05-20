//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the factorial of a number using recursion
long long int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

// Function to calculate the nth Fibonacci number using recursion
int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to calculate the sum of the series 1 + 1/2 + 1/3 +... + 1/n using recursion
double harmonic_series(int n) {
    if (n == 1)
        return 1;
    else
        return 1 / n + harmonic_series(n - 1);
}

// Function to calculate the nth prime number using recursion
int is_prime(int n) {
    if (n <= 1)
        return 0;
    else if (n == 2)
        return 1;
    else if (n % 2 == 0)
        return 0;
    else
        return is_prime(n - 1);
}

int main() {
    int n;

    // Prompt the user to enter a number
    printf("Enter a number: ");
    scanf("%d", &n);

    // Calculate the factorial of the number
    printf("The factorial of %d is %lld.\n", n, factorial(n));

    // Calculate the nth Fibonacci number
    printf("The %dth Fibonacci number is %d.\n", n, fibonacci(n));

    // Calculate the sum of the first n terms of the harmonic series
    printf("The sum of the first %d terms of the harmonic series is %.2lf.\n", n, harmonic_series(n));

    // Calculate the nth prime number
    printf("The %dth prime number is %d.\n", n, is_prime(n));

    return 0;
}