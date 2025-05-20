//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/**
 * A program that generates prime numbers up to a specified limit.
 * This program utilizes the Sieve of Eratosthenes algorithm,
 * which is efficient for finding all primes smaller than a given number.
 */

/**
 * Function to generate prime numbers using the Sieve of Eratosthenes.
 * @param limit: The upper limit for generating prime numbers.
 */
void generate_primes(int limit) {
    if (limit < 2) {
        printf("No prime numbers less than 2.\n");
        return;
    }

    // Create an array to keep track of prime number status (true = prime, false = non-prime)
    bool *is_prime = malloc((limit + 1) * sizeof(bool));
    if (is_prime == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the array: assume all numbers are prime initially
    for (int i = 0; i <= limit; i++) {
        is_prime[i] = true;
    }

    is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime numbers

    // Sieve of Eratosthenes algorithm
    for (int p = 2; p <= sqrt(limit); p++) {
        if (is_prime[p]) {
            // Mark all multiples of p as non-prime
            for (int multiple = p * p; multiple <= limit; multiple += p) {
                is_prime[multiple] = false;
            }
        }
    }

    // Output all prime numbers
    printf("Prime numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    // Free the allocated memory
    free(is_prime);
}

/**
 * Main function to execute the program.
 * It will prompt the user to input an upper limit for the prime number generation.
 */
int main() {
    int limit;

    // Prompt user for input
    printf("Enter the upper limit for generating prime numbers: ");
    if (scanf("%d", &limit) != 1) {
        fprintf(stderr, "Invalid input. Please enter an integer.\n");
        return EXIT_FAILURE;
    }

    // Generate and display prime numbers
    generate_primes(limit);

    return EXIT_SUCCESS;
}