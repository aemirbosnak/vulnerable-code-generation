//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A simple function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// A function to generate the first n prime numbers
int* generatePrimes(int n) {
    // Allocate memory for the array of prime numbers
    int* primes = malloc(sizeof(int) * n);

    // Initialize the array with the first two prime numbers
    primes[0] = 2;
    primes[1] = 3;

    // Iterate over the remaining numbers
    int count = 2;
    int i = 5;
    while (count < n) {
        // Check if the number is prime
        if (isPrime(i)) {
            // Add the number to the array of prime numbers
            primes[count] = i;
            count++;
        }
        // Increment the number
        i += 2;
    }

    // Return the array of prime numbers
    return primes;
}

// A function to print the first n prime numbers
void printPrimes(int n) {
    // Generate the first n prime numbers
    int* primes = generatePrimes(n);

    // Print the prime numbers
    for (int i = 0; i < n; i++) {
        printf("%d ", primes[i]);
    }

    // Free the memory allocated for the array of prime numbers
    free(primes);
}

// The main function
int main() {
    // Get the number of prime numbers to generate from the user
    int n;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &n);

    // Print the first n prime numbers
    printPrimes(n);

    return 0;
}