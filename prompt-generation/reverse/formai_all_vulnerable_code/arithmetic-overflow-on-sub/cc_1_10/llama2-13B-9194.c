//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 100
#define MIN_VALUE -100
#define MAX_VALUE 100

// Function to calculate the factorial of a given number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate the Fibonacci sequence of a given number
int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to calculate the golden ratio of a given number
float goldenRatio(int n) {
    return (float)(n + sqrt(n * n + 1)) / (2 * n);
}

// Function to calculate the nearest perfect square of a given number
int nearestPerfectSquare(int n) {
    int square = 0;
    while (square < n) {
        square = square * 2 + 1;
    }
    return square;
}

int main() {
    int n, i;
    float ratio;

    // Calculate the factorial of a given number
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printf("The factorial of %d is %d\n", n, factorial(n));

    // Calculate the Fibonacci sequence of a given number
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printf("The Fibonacci sequence of %d is %d\n", n, fibonacci(n));

    // Calculate the golden ratio of a given number
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    ratio = goldenRatio(n);
    printf("The golden ratio of %d is %f\n", n, ratio);

    // Calculate the nearest perfect square of a given number
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printf("The nearest perfect square of %d is %d\n", n, nearestPerfectSquare(n));

    return 0;
}