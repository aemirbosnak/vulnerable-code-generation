//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a function to calculate the factorial of a given integer
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Define a function to calculate the nth Fibonacci number
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
    int n, m;
    double x, y;

    // Read two integers from the user
    printf("Enter two integers: ");
    scanf("%d%d", &n, &m);

    // Calculate the factorial of n and store it in a variable
    int fact = factorial(n);

    // Calculate the nth Fibonacci number and store it in a variable
    int fib = fibonacci(n);

    // Calculate the ratio of the Fibonacci number to the factorial
    y = fib / fact;

    // Print the result
    printf("The ratio of the %dth Fibonacci number to the factorial is %lf\n", n, y);

    // Calculate the ratio of the Fibonacci number to the factorial using long double precision
    y = fibonacci(n);
    x = factorial(n);
    long double ratio = y / x;
    printf("The ratio of the %dth Fibonacci number to the factorial using long double precision is %Lf\n", n, ratio);

    return 0;
}