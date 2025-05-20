//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printPrimes(bool *isPrime, int limit) {
    printf("Prime numbers up to %d:\n", limit);
    for (int num = 2; num <= limit; num++) {
        if (isPrime[num]) {
            printf("%d ", num);
        }
    }
    printf("\n");
}

bool* generatePrimes(int limit) {
    if (limit < 2) {
        return NULL; // No primes below 2
    }

    bool *isPrime = malloc((limit + 1) * sizeof(bool));
    if (isPrime == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i <= limit; i++) {
        isPrime[i] = true; // Assume all numbers are prime initially
    }
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime

    for (int p = 2; p * p <= limit; p++) {
        if (isPrime[p]) {
            for (int multiple = p * p; multiple <= limit; multiple += p) {
                isPrime[multiple] = false; // Mark all multiples of p as non-prime
            }
        }
    }

    return isPrime;
}

void cleanUp(bool *isPrime) {
    free(isPrime);
}

int main() {
    int limit;

    printf("Welcome to the Prime Number Generator!\n");
    printf("Please enter a positive integer as the upper limit for prime generation: ");
    
    while (scanf("%d", &limit) != 1 || limit < 1) {
        while(getchar() != '\n'); // Clear invalid input
        printf("Invalid input. Please enter a positive integer: ");
    }

    bool *isPrime = generatePrimes(limit);
    if (isPrime != NULL) {
        printPrimes(isPrime, limit);
        cleanUp(isPrime);
    } else {
        printf("No prime numbers to display for the given limit.\n");
    }

    return 0;
}