//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CONFIG_MAX_NUMBER 1000000

// Function to check if a number is prime
bool is_prime(unsigned int number) {
    if (number <= 1) {
        return false;
    }

    for (unsigned int i = 2; i <= number / 2; ++i) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

// Function to generate prime numbers up to a given limit
void generate_primes(unsigned int limit) {
    // Create an array to store the prime numbers
    unsigned int *primes = malloc(limit * sizeof(unsigned int));

    // Initialize the array with all numbers up to the limit
    for (unsigned int i = 0; i < limit; ++i) {
        primes[i] = i + 1;
    }

    // Mark all non-prime numbers in the array
    for (unsigned int i = 2; i <= limit / 2; ++i) {
        if (primes[i - 1] != 0) {
            for (unsigned int j = i * i; j <= limit; j += i) {
                primes[j - 1] = 0;
            }
        }
    }

    // Print the prime numbers
    for (unsigned int i = 0; i < limit; ++i) {
        if (primes[i] != 0) {
            printf("%u ", primes[i]);
        }
    }

    // Free the memory allocated for the array
    free(primes);
}

int main() {
    // Get the user's input for the limit
    unsigned int limit;
    printf("Enter the limit up to which you want to generate prime numbers: ");
    scanf("%u", &limit);

    // Check if the user's input is valid
    if (limit < 1) {
        printf("Invalid input. The limit must be greater than or equal to 1.\n");
        return EXIT_FAILURE;
    }

    // Generate the prime numbers
    generate_primes(limit);

    return EXIT_SUCCESS;
}