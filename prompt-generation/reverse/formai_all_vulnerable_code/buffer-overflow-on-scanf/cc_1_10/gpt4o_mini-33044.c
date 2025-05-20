//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Function to generate prime numbers up to a specified limit using the Sieve of Eratosthenes
void generate_primes(int limit) {
    if(limit < 2) {
        printf("There are no prime numbers less than 2.\n");
        return;
    }
    
    // Create an array to track prime numbers
    int *is_prime = malloc((limit + 1) * sizeof(int));
    if(is_prime == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return;
    }

    // Initialize the array
    for(int i = 0; i <= limit; i++) {
        is_prime[i] = 1; // Assume all numbers are prime initially
    }
    is_prime[0] = 0; // 0 is not a prime number
    is_prime[1] = 0; // 1 is not a prime number

    // Sieve of Eratosthenes algorithm to find prime numbers
    for(int p = 2; p * p <= limit; p++) {
        if(is_prime[p]) {
            for(int multiple = p * p; multiple <= limit; multiple += p) {
                is_prime[multiple] = 0; // Marking multiples of p as non-prime
            }
        }
    }

    // Print all prime numbers
    printf("Prime numbers up to %d:\n", limit);
    for(int i = 2; i <= limit; i++) {
        if(is_prime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    // Free the allocated memory
    free(is_prime);
}

// Main function to execute the program
int main() {
    int limit;

    // User input for the upper limit of prime numbers
    printf("Enter the upper limit to generate prime numbers: ");
    if(scanf("%d", &limit) != 1 || limit < 0) {
        fprintf(stderr, "Invalid input. Please enter a non-negative integer.\n");
        return 1;
    }

    // Generate and display prime numbers
    generate_primes(limit);

    return 0;
}