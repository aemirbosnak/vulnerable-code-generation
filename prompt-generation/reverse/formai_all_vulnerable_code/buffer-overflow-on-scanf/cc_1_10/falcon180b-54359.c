//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the factorial of a number
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate the nth Fibonacci number
int fibonacci(int n) {
    int t1 = 0, t2 = 1, nextTerm;
    for (int i = 2; i < n; i++) {
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    return t1;
}

// Function to calculate the sum of squares of odd numbers up to n
int sumOfSquares(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i += 2) {
        sum += i * i;
    }
    return sum;
}

int main() {
    int n;

    // Prompt user for input
    printf("Enter a number: ");
    scanf("%d", &n);

    // Calculate factorial of n
    printf("Factorial of %d is %d\n", n, factorial(n));

    // Calculate the nth Fibonacci number
    printf("The %dth Fibonacci number is %d\n", n, fibonacci(n));

    // Calculate the sum of squares of odd numbers up to n
    printf("The sum of squares of odd numbers up to %d is %d\n", n, sumOfSquares(n));

    return 0;
}