//FormAI DATASET v1.0 Category: Computer Biology ; Style: recursive
#include <stdio.h>

// Recursive function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Recursive function to calculate the nth fibonacci number
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Recursive function to calculate the sum of digits in a number
int sum_of_digits(int n) {
    if (n == 0) {
        return 0;
    } else {
        return (n % 10) + sum_of_digits(n / 10);
    }
}

// Recursive function to calculate the gcd of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int n;

    // Calculate the factorial of a number
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &n);
    printf("%d! = %d\n", n, factorial(n));

    // Calculate the nth fibonacci number
    printf("Enter n to calculate the nth fibonacci number: ");
    scanf("%d", &n);
    printf("Fibonacci(%d) = %d\n", n, fibonacci(n));

    // Calculate the sum of digits in a number
    printf("Enter a number to calculate the sum of its digits: ");
    scanf("%d", &n);
    printf("Sum of digits in %d = %d\n", n, sum_of_digits(n));

    // Calculate the gcd of two numbers
    int a, b;
    printf("Enter two numbers to calculate their gcd: ");
    scanf("%d %d", &a, &b);
    printf("GCD(%d, %d) = %d\n", a, b, gcd(a, b));

    return 0;
}