//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the factorial of a given number
long long int factorial(int n) {
    long long int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate the nth Fibonacci number
long long int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to calculate the square root of a given number
double sqrt(double x) {
    return sqrt(x);
}

int main() {
    int n;
    double x;

    // Prompt the user for the number of Fibonacci numbers to calculate
    printf("Enter the number of Fibonacci numbers to calculate: ");
    scanf("%d", &n);

    // Calculate and display the Fibonacci numbers
    for (int i = 0; i < n; i++) {
        printf("%lld ", fibonacci(i));
    }

    // Prompt the user for a number to calculate the square root of
    printf("\nEnter a number to calculate the square root of: ");
    scanf("%lf", &x);

    // Calculate and display the square root of the input number
    printf("\nThe square root of %.2f is %.2f\n", x, sqrt(x));

    // Calculate and display the factorial of the first 10 numbers
    printf("\nThe factorials of the first 10 numbers are:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d! = %lld\n", i, factorial(i));
    }

    return 0;
}