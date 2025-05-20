//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to find the greatest common divisor of two integers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to find the least common multiple of two integers
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

// Function to find the sum of the digits of an integer
int sumDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Function to find the factorial of an integer
int factorial(int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

// Function to find the nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int a, b;

    // Get two integers from the user
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    // Swap the two integers
    swap(&a, &b);

    // Find the greatest common divisor of the two integers
    int g = gcd(a, b);

    // Find the least common multiple of the two integers
    int l = lcm(a, b);

    // Find the sum of the digits of the two integers
    int s1 = sumDigits(a);
    int s2 = sumDigits(b);

    // Find the factorial of the two integers
    int f1 = factorial(a);
    int f2 = factorial(b);

    // Find the nth Fibonacci number for the two integers
    int fib1 = fibonacci(a);
    int fib2 = fibonacci(b);

    // Print the results
    printf("The swapped integers are: %d %d\n", a, b);
    printf("The greatest common divisor of %d and %d is: %d\n", a, b, g);
    printf("The least common multiple of %d and %d is: %d\n", a, b, l);
    printf("The sum of the digits of %d is: %d\n", a, s1);
    printf("The sum of the digits of %d is: %d\n", b, s2);
    printf("The factorial of %d is: %d\n", a, f1);
    printf("The factorial of %d is: %d\n", b, f2);
    printf("The %dth Fibonacci number is: %d\n", a, fib1);
    printf("The %dth Fibonacci number is: %d\n", b, fib2);

    return 0;
}