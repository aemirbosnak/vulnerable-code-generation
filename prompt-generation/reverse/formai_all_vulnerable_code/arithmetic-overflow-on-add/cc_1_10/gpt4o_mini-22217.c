//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

void printPrimes(int limit) {
    // Allocate a boolean array to hold the status of each number up to the limit
    int *isPrime = (int *)malloc((limit + 1) * sizeof(int));
    if (isPrime == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Initialize all entries as true. A value in isPrime[i] will
    // eventually be false if i is Not a prime, true if i is a prime
    for (int i = 0; i <= limit; i++) {
        isPrime[i] = 1; // Assume all numbers are prime initially
    }

    // 0 and 1 are not prime numbers
    isPrime[0] = 0;
    isPrime[1] = 0;

    // Perform the Sieve of Eratosthenes algorithm
    for (int p = 2; p * p <= limit; p++) {
        // If isPrime[p] is not changed, then it is a prime
        if (isPrime[p]) {
            // Update all multiples of p
            for (int multiple = p * p; multiple <= limit; multiple += p) {
                isPrime[multiple] = 0; // Mark multiples as not prime
            }
        }
    }

    // Print all prime numbers
    printf("Prime numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    // Free the allocated memory
    free(isPrime);
}

int main() {
    int limit;

    printf("Welcome to the Prime Number Generator!\n");
    printf("Please enter the limit to generate prime numbers: ");
    if (scanf("%d", &limit) != 1 || limit < 2) {
        fprintf(stderr, "Invalid input. Please enter an integer greater than 1.\n");
        return EXIT_FAILURE;
    }

    // Call the function to print prime numbers
    printPrimes(limit);

    return EXIT_SUCCESS;
}