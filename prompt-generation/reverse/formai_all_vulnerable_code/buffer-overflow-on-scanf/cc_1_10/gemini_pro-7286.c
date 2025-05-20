//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the nth Fibonacci number using recursion
int fib(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

// Function to calculate the factorial of a number using recursion
int fact(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}

// Function to calculate the sum of digits of a number using recursion
int sum_digits(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n % 10 + sum_digits(n / 10);
    }
}

// Function to calculate the reverse of a number using recursion
int reverse(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n % 10 * pow(10, floor(log10(n))) + reverse(n / 10);
    }
}

// Function to calculate the greatest common divisor of two numbers using recursion
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// Function to calculate the least common multiple of two numbers using recursion
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

// Function to calculate the nth term of a geometric progression using recursion
int gp(int a, int r, int n) {
    if (n == 0) {
        return a;
    } else {
        return a * pow(r, n - 1);
    }
}

// Function to calculate the nth term of an arithmetic progression using recursion
int ap(int a, int d, int n) {
    if (n == 0) {
        return a;
    } else {
        return a + (n - 1) * d;
    }
}

// Function to calculate the nth term of a harmonic progression using recursion
int hp(int a, int d, int n) {
    if (n == 0) {
        return a;
    } else {
        return a + (n - 1) * d;
    }
}

// Function to calculate the factorial of a number using a recursive loop
int fact_loop(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Fibonacci of %d: %d\n", n, fib(n));
    printf("Factorial of %d: %d\n", n, fact(n));
    printf("Sum of digits of %d: %d\n", n, sum_digits(n));
    printf("Reverse of %d: %d\n", n, reverse(n));
    printf("GCD of 12 and 18: %d\n", gcd(12, 18));
    printf("LCM of 12 and 18: %d\n", lcm(12, 18));
    printf("5th term of GP with a = 2 and r = 3: %d\n", gp(2, 3, 5));
    printf("5th term of AP with a = 2 and d = 3: %d\n", ap(2, 3, 5));
    printf("5th term of HP with a = 2 and d = 3: %d\n", hp(2, 3, 5));
    printf("Factorial of %d using loop: %d\n", n, fact_loop(n));

    return 0;
}