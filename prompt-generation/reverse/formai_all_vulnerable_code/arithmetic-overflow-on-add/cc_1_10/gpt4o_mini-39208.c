//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void print_primes(int limit) {
    if (limit < 2) {
        return; // No prime numbers below 2
    }
    
    bool *is_prime = malloc((limit + 1) * sizeof(bool));
    
    if (is_prime == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the is_prime array
    for (int i = 0; i <= limit; i++) {
        is_prime[i] = true; // Assume all numbers are prime
    }
    
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not primes

    // Implementing the Sieve of Eratosthenes
    for (int p = 2; p <= (int)sqrt(limit); p++) {
        if (is_prime[p]) {
            for (int multiple = p * p; multiple <= limit; multiple += p) {
                is_prime[multiple] = false; // Marking multiples of p as not prime
            }
        }
    }

    // Print out the prime numbers
    printf("Prime numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    free(is_prime); // Free allocated memory
}

int main() {
    int limit;

    printf("Enter the upper limit for prime number generation: ");
    if (scanf("%d", &limit) != 1 || limit < 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return EXIT_FAILURE;
    }

    print_primes(limit);
    
    return EXIT_SUCCESS;
}