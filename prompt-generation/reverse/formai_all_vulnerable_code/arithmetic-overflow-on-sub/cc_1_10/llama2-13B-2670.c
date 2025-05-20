//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAGIC_NUMBER 42

// Function to calculate the factorial of a given number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

// Function to calculate the Fibonacci sequence of a given number
int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

// Function to calculate the prime factors of a given number
int primeFactors(int n) {
    int factors[100];
    int i, j, k;

    // Initialize factors array
    for (i = 0; i < 100; i++) {
        factors[i] = 0;
    }

    // Find prime factors
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            factors[i-2] = 1;
            n = n / i;
        }
    }

    // Check if n is 1
    if (n == 1) {
        return 1;
    }

    // Return the prime factors
    for (i = 0; i < 100; i++) {
        if (factors[i] == 1) {
            return factors[i];
        }
    }

    return 0;
}

int main() {
    int num, answer;

    // Get the number from the user
    printf("Enter a number: ");
    scanf("%d", &num);

    // Calculate the factorial
    answer = factorial(num);
    printf("The factorial of %d is %d\n", num, answer);

    // Calculate the Fibonacci sequence
    answer = fibonacci(num);
    printf("The Fibonacci sequence of %d is %d\n", num, answer);

    // Calculate the prime factors
    answer = primeFactors(num);
    printf("The prime factors of %d are %d\n", num, answer);

    return 0;
}