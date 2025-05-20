//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate the sum of the digits of a number
int sum_of_digits(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n % 10 + sum_of_digits(n / 10);
    }
}

// Function to check if a number is prime
int is_prime(int n) {
    if (n <= 1) {
        return 0;
    } else {
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                return 0;
            }
        }
        return 1;
    }
}

// Function to find the greatest common divisor of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// Function to find the least common multiple of two numbers
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("The factorial of %d is %d\n", n, factorial(n));
    printf("The sum of the digits of %d is %d\n", n, sum_of_digits(n));
    printf("Is %d prime? %s\n", n, is_prime(n) ? "Yes" : "No");
    printf("The greatest common divisor of %d and 12 is %d\n", n, gcd(n, 12));
    printf("The least common multiple of %d and 12 is %d\n", n, lcm(n, 12));

    return 0;
}