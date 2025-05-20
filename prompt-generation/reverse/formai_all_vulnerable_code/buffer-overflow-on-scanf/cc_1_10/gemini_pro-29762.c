//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: beginner-friendly
#include <stdio.h>

// Function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n-1);
}

// Function to calculate the sum of the digits of a number
int sumDigits(int n) {
    if (n == 0) {
        return 0;
    }
    return n % 10 + sumDigits(n / 10);
}

// Function to check if a number is a palindrome
int isPalindrome(int n) {
    if (n < 0) {
        return 0;
    }
    if (n < 10) {
        return 1;
    }
    if (n % 10 != n / 10 % 10) {
        return 0;
    }
    return isPalindrome(n / 100);
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

// Function to calculate the Fibonacci sequence
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

// Function to calculate the binomial coefficient
int binomialCoefficient(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }
    return binomialCoefficient(n-1, k-1) + binomialCoefficient(n-1, k);
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("The factorial of %d is %d\n", n, factorial(n));
    printf("The sum of the digits of %d is %d\n", n, sumDigits(n));
    printf("%d is %s a palindrome\n", n, isPalindrome(n) ? "" : "not");
    printf("The greatest common divisor of %d and %d is %d\n", n, n+1, gcd(n, n+1));
    printf("The least common multiple of %d and %d is %d\n", n, n+1, lcm(n, n+1));
    printf("The %dth Fibonacci number is %d\n", n, fibonacci(n));
    printf("The binomial coefficient of %d and %d is %d\n", n, n/2, binomialCoefficient(n, n/2));

    return 0;
}