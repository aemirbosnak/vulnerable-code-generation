//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRIME_LIMIT 1000000

void print_intro() {
    printf("========================================\n");
    printf("     Welcome to Prime Number Finder!   \n");
    printf("========================================\n");
    printf("This program helps you find all prime numbers up to a specified limit.\n");
    printf("Prime numbers are natural numbers greater than 1, \n");
    printf("which cannot be formed by multiplying two smaller natural numbers.\n");
    printf("Enjoy finding primes! Let’s get started!\n");
    printf("========================================\n");
}

void print_primes(int limit) {
    printf("Finding prime numbers up to: %d\n\n", limit);
    
    // Using an array to keep track of prime numbers
    int *is_prime = malloc((limit + 1) * sizeof(int));
    if (is_prime == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    // Initialize all numbers as prime
    for (int i = 0; i <= limit; i++) {
        is_prime[i] = 1; // Assume all numbers are prime initially
    }
    is_prime[0] = is_prime[1] = 0; // 0 and 1 are not prime numbers

    // Sieve of Eratosthenes algorithm to find all primes
    for (int i = 2; i*i <= limit; i++) {
        if (is_prime[i]) {
            for (int j = i*i; j <= limit; j += i) {
                is_prime[j] = 0; // Marking as non-prime
            }
        }
    }

    // Print all prime numbers
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    // Clean up memory
    free(is_prime);
}

int main() {
    int limit;

    print_intro();
    
    // Loop until a valid limit is entered
    while (1) {
        printf("Enter the upper limit for prime number generation (max %d): ", MAX_PRIME_LIMIT);
        scanf("%d", &limit);

        if (limit < 2) {
            printf("Please enter a number greater than or equal to 2.\n");
        } else if (limit > MAX_PRIME_LIMIT) {
            printf("The limit exceeds the maximum allowed limit of %d.\n", MAX_PRIME_LIMIT);
        } else {
            break; // Exit the loop if input is valid
        }
    }

    print_primes(limit);
    
    // Closure message
    printf("Thank you for using Prime Number Finder! Goodbye!\n");
    return 0;
}