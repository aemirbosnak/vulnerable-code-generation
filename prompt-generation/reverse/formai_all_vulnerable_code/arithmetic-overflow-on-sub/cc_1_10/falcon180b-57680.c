//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the golden ratio
#define golden_ratio (1.61803398875)

// Define a function to calculate the nth Fibonacci number using recursion
long long fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

// Define a function to calculate the sum of the first n Fibonacci numbers
double fibonacci_sum(int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += fibonacci(i);
    }
    return (double)sum;
}

// Define a function to calculate the ratio of two consecutive Fibonacci numbers
double fibonacci_ratio(int n) {
    long long prev = fibonacci(n-1);
    long long curr = fibonacci(n);
    return (double)curr / prev;
}

// Define a function to calculate the nth root of a number using Newton's method
double nth_root(double num, int n) {
    double guess = num / n;
    while (fabs(guess*guess - num) > 0.0001) {
        guess = (guess + num / guess) / 2;
    }
    return guess;
}

int main() {
    // Prompt the user for the number of Fibonacci numbers to sum
    int n;
    printf("Enter the number of Fibonacci numbers to sum: ");
    scanf("%d", &n);

    // Calculate the sum of the first n Fibonacci numbers
    double sum = fibonacci_sum(n);

    // Print the sum
    printf("The sum of the first %d Fibonacci numbers is: %.0lf\n", n, sum);

    // Calculate the ratio of the (n-1)th and nth Fibonacci numbers
    double ratio = fibonacci_ratio(n);

    // Print the ratio
    printf("The ratio of the (n-1)th and nth Fibonacci numbers is: %.6lf\n", ratio);

    // Calculate the nth root of the sum
    double root = nth_root(sum, n);

    // Print the nth root
    printf("The nth root of the sum of the first %d Fibonacci numbers is: %.6lf\n", n, root);

    return 0;
}