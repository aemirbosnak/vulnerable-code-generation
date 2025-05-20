//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: Dennis Ritchie
#include <stdio.h>
#include <math.h>

// Function to calculate the nth Fibonacci number
long long int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

// Function to calculate the sum of the first n odd numbers
long long int sum_of_odds(int n) {
    return (2*n-1)*n/2;
}

// Function to calculate the factorial of a number
long long int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n-1);
}

// Function to calculate the nth prime number
int nth_prime(int n) {
    int count = 0;
    int num = 2;
    while (count < n) {
        if (isPrime(num)) {
            count++;
        }
        num++;
    }
    return num - 1;
}

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to calculate the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to calculate the least common multiple (LCM) of two numbers
int lcm(int a, int b) {
    return (a*b) / gcd(a, b);
}

int main() {
    // Example usage of the functions
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("The %dth Fibonacci number is %lld\n", n, fibonacci(n));
    printf("The sum of the first %d odd numbers is %lld\n", n, sum_of_odds(n));
    printf("The factorial of %d is %lld\n", n, factorial(n));
    printf("The %dth prime number is %d\n", n, nth_prime(n));
    printf("The GCD of %d and %d is %d\n", 24, 36, gcd(24, 36));
    printf("The LCM of %d and %d is %d\n", 24, 36, lcm(24, 36));
    return 0;
}