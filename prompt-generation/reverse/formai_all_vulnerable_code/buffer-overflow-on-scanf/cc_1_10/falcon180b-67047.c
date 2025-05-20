//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a function to calculate the nth Fibonacci number
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Define a function to calculate the sum of the squares of the first n natural numbers
int sum_of_squares(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * i;
    }
    return sum;
}

// Define a function to calculate the factorial of a given number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Define a function to calculate the nth prime number
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

// Define a function to check if a given number is prime or not
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

int main() {
    int n;

    // Prompt the user to enter a number
    printf("Enter a number: ");
    scanf("%d", &n);

    // Calculate the nth Fibonacci number
    int fib = fibonacci(n);
    printf("The %dth Fibonacci number is: %d\n", n, fib);

    // Calculate the sum of the squares of the first n natural numbers
    int sum = sum_of_squares(n);
    printf("The sum of the squares of the first %d natural numbers is: %d\n", n, sum);

    // Calculate the factorial of n
    int fact = factorial(n);
    printf("The factorial of %d is: %d\n", n, fact);

    // Calculate the nth prime number
    int prime = nth_prime(n);
    printf("The %dth prime number is: %d\n", n, prime);

    return 0;
}