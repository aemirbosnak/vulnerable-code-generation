//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a function to calculate the nth Fibonacci number using recursion
long long int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

// Define a function to calculate the nth Lucas number using recursion
long long int lucas(int n) {
    if (n <= 1) {
        return n;
    } else {
        return lucas(n-1) + fibonacci(n-2);
    }
}

// Define a function to calculate the sum of the first n even numbers
long long int sum_even(int n) {
    return (n*(n+1))/2;
}

// Define a function to calculate the sum of the first n odd numbers
long long int sum_odd(int n) {
    return (n*n)/2;
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
    return num-1;
}

// Define a function to check if a number is prime
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
    // Prompt the user to enter a number
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    // Calculate and print the nth Fibonacci number
    printf("The %dth Fibonacci number is %lld.\n", n, fibonacci(n));

    // Calculate and print the nth Lucas number
    printf("The %dth Lucas number is %lld.\n", n, lucas(n));

    // Calculate and print the sum of the first n even numbers
    printf("The sum of the first %d even numbers is %lld.\n", n, sum_even(n));

    // Calculate and print the sum of the first n odd numbers
    printf("The sum of the first %d odd numbers is %lld.\n", n, sum_odd(n));

    // Calculate and print the nth prime number
    printf("The %dth prime number is %d.\n", n, nth_prime(n));

    return 0;
}