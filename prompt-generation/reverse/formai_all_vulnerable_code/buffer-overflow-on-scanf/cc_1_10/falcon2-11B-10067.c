//Falcon2-11B DATASET v1.0 Category: Error handling ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate factorial of a number
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to check if a number is prime
int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to print prime numbers up to a given number
void printPrimeNumbers(int n) {
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Check if the input is a valid number
    if (n < 0) {
        printf("Invalid input! Please enter a positive integer.\n");
        return 1;
    }

    // Check if the input is a prime number
    if (!isPrime(n)) {
        printf("The input number %d is not a prime number.\n", n);
        return 1;
    }

    // Print prime numbers up to the input number
    printPrimeNumbers(n);

    return 0;
}