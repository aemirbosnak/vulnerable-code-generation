//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: realistic
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
    double sum, avg;

    // Read two integers from the user
    printf("Enter two integers: ");
    scanf("%d%d", &n, &m);

    // Calculate the factorial of n
    int factorial_n = factorial(n);

    // Calculate the nth Fibonacci number
    int fibonacci_n = fibonacci(n);

    // Calculate the sum of the two numbers
    sum = factorial_n + fibonacci_n;

    // Calculate the average of the two numbers
    avg = (double)sum / (double)n;

    // Print the results
    printf("The sum of %d and %d is %d.\n", n, m, sum);
    printf("The average of %d and %d is %f.\n", n, m, avg);

    return 0;
}