//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 100000
#define MIN_NUM 0

// Function to calculate the factorial of a given number
int factorial(int n) {
    if (n == 0) return 1;
    else return n * factorial(n-1);
}

// Function to calculate the nth Fibonacci number
int fibonacci(int n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else return fibonacci(n-1) + fibonacci(n-2);
}

// Function to calculate the sum of the digits of a given number
int sum_digits(int n) {
    int sum = 0;
    while (n != 0) {
        sum += (n % 10) + (n / 10);
        n /= 10;
    }
    return sum;
}

// Function to calculate the number of prime numbers less than or equal to a given number
int num_primes(int n) {
    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (isprime(i)) count++;
    }
    return count;
}

// Function to check if a given number is prime
int isprime(int n) {
    if (n == 1) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n, m, sum;

    // Ask the user for the first number
    printf("Enter the first number: ");
    scanf("%d", &n);

    // Ask the user for the second number
    printf("Enter the second number: ");
    scanf("%d", &m);

    // Calculate the sum of the two numbers
    sum = n + m;

    // Calculate the factorial of the sum
    int factorial_sum = factorial(sum);

    // Calculate the nth Fibonacci number
    int fibonacci_sum = fibonacci(n);

    // Calculate the sum of the digits of the sum
    int sum_digits_sum = sum_digits(sum);

    // Calculate the number of prime numbers less than or equal to the sum
    int num_primes_sum = num_primes(sum);

    // Print the results
    printf("The sum of %d and %d is %d\n", n, m, sum);
    printf("The factorial of %d is %d\n", sum, factorial_sum);
    printf("The nth Fibonacci number is %d\n", fibonacci_sum);
    printf("The sum of the digits of %d is %d\n", sum, sum_digits_sum);
    printf("The number of prime numbers less than or equal to %d is %d\n", sum, num_primes_sum);

    return 0;
}