//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }

    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

// Function to generate prime numbers up to a given limit
void generatePrimes(int limit) {
    printf("Prime numbers up to %d:\n", limit);

    // Create an array to store the prime numbers
    int *primes = (int *)malloc(sizeof(int) * limit);
    int numPrimes = 0;

    // Iterate through all the numbers up to the limit
    for (int i = 2; i <= limit; ++i) {
        // Check if the number is prime
        if (isPrime(i)) {
            // Add the number to the array of prime numbers
            primes[numPrimes++] = i;
        }
    }

    // Print the prime numbers
    for (int i = 0; i < numPrimes; ++i) {
        printf("%d ", primes[i]);
    }

    printf("\n");

    // Free the memory allocated for the array of prime numbers
    free(primes);
}

int main() {
    // Get the limit from the user
    int limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);

    // Generate the prime numbers up to the given limit
    generatePrimes(limit);

    return 0;
}