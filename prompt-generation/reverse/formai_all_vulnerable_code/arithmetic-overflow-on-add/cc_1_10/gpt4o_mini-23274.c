//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_primes(int limit) {
    // Create an array to track which numbers are prime
    bool *is_prime = malloc((limit + 1) * sizeof(bool));
    if (is_prime == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }

    // Initialize all numbers as prime
    for (int i = 0; i <= limit; i++) {
        is_prime[i] = true;
    }

    // 0 and 1 are not primes
    is_prime[0] = is_prime[1] = false;

    // Sieve of Eratosthenes
    for (int p = 2; p * p <= limit; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                is_prime[i] = false; // Mark multiples of p as non-prime
            }
        }
    }

    // Print the prime numbers
    printf("Prime numbers up to %d are:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    // Free allocated memory
    free(is_prime);
}

int main() {
    int limit;

    // User input for the limit
    printf("Enter the upper limit for prime number generation: ");
    if (scanf("%d", &limit) != 1 || limit < 2) {
        fprintf(stderr, "Please enter an integer greater than or equal to 2.\n");
        return 1;
    }

    print_primes(limit);
    
    return 0;
}