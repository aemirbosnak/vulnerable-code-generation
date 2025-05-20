//Falcon2-11B DATASET v1.0 Category: Digital signal processing ; Style: Ken Thompson
#include <stdio.h>
#include <math.h>

// Function to calculate the sum of two numbers
int sum(int a, int b) {
    return a + b;
}

// Function to calculate the product of two numbers
int product(int a, int b) {
    return a * b;
}

// Function to calculate the power of a number
int power(int a, int b) {
    return pow(a, b);
}

// Function to calculate the square root of a number
double sqrt(double a) {
    return sqrt(a);
}

// Function to calculate the logarithm of a number
double log(double a) {
    return log(a);
}

// Function to calculate the factorial of a number
int factorial(int a) {
    int result = 1;
    for (int i = 1; i <= a; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate the Fibonacci sequence
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        int result = fibonacci(n-1) + fibonacci(n-2);
        return result;
    }
}

int main() {
    // Call the functions and print the results
    int a = 5;
    int b = 7;
    int sum_result = sum(a, b);
    int product_result = product(a, b);
    int power_result = power(a, b);
    double sqrt_result = sqrt(a);
    double log_result = log(a);
    int factorial_result = factorial(a);
    int fibonacci_result = fibonacci(a);

    printf("Sum of %d and %d is %d\n", a, b, sum_result);
    printf("Product of %d and %d is %d\n", a, b, product_result);
    printf("Power of %d to the power of %d is %d\n", a, b, power_result);
    printf("Square root of %f is %f\n", a, sqrt_result);
    printf("Logarithm of %f is %f\n", a, log_result);
    printf("Factorial of %d is %d\n", a, factorial_result);
    printf("Fibonacci sequence of %d is %d\n", a, fibonacci_result);

    return 0;
}