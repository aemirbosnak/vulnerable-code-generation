//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void generatePrimes(int limit) {
    // Allocate memory for the array that holds info on prime numbers
    bool *isPrime = malloc((limit + 1) * sizeof(bool));
    if (isPrime == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Initialize all entries as true. A value in isPrime[i] will
    // finally be false if 'i' is Not a prime, otherwise true.
    for (int i = 0; i <= limit; i++) {
        isPrime[i] = true;
    }

    // 0 and 1 are not prime numbers
    isPrime[0] = false;
    isPrime[1] = false;

    // Implementing Sieve of Eratosthenes
    for (int p = 2; p * p <= limit; p++) {
        // If isPrime[p] is not changed, then it is a prime
        if (isPrime[p]) {
            // Update all multiples of p
            for (int multiple = p * p; multiple <= limit; multiple += p) {
                isPrime[multiple] = false;
            }
        }
    }

    // Output all prime numbers
    printf("Prime numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    // Free the allocated array
    free(isPrime);
}

int main() {
    int limit;

    printf("Enter the upper limit to generate prime numbers: ");
    while (scanf("%d", &limit) != 1 || limit < 2) {
        printf("Please enter a valid integer greater than 1: ");
        while (getchar() != '\n'); // Clear invalid input
    }

    // Call function to generate primes up to the limit
    generatePrimes(limit);

    return 0;
}