//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the nth Fibonacci number using the Binet's Formula
double fibonacci(int n) {
    double phi = (1 + sqrt(5)) / 2;
    return round((pow(phi, n) - pow(1 - phi, n)) / sqrt(5));
}

// Function to calculate the sum of the first n Fibonacci numbers
double fibonacci_sum(int n) {
    double phi = (1 + sqrt(5)) / 2;
    return round((pow(phi, n + 2) - pow(1 - phi, n + 2)) / sqrt(5) - 1);
}

// Function to check if a number is prime
int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to find the greatest common divisor of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to find the least common multiple of two numbers
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// Function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    // Print the first 10 Fibonacci numbers
    printf("The first 10 Fibonacci numbers are:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    // Print the sum of the first 10 Fibonacci numbers
    printf("The sum of the first 10 Fibonacci numbers is: %d\n", fibonacci_sum(10));

    // Check if 17 is a prime number
    printf("Is 17 a prime number? %s\n", is_prime(17) ? "Yes" : "No");

    // Find the greatest common divisor of 12 and 18
    printf("The greatest common divisor of 12 and 18 is: %d\n", gcd(12, 18));

    // Find the least common multiple of 12 and 18
    printf("The least common multiple of 12 and 18 is: %d\n", lcm(12, 18));

    // Calculate the factorial of 5
    printf("The factorial of 5 is: %d\n", factorial(5));

    return 0;
}