//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUM 1000 // Generate prime numbers up to 1000

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) return 0; // 0 and 1 are not prime numbers
    if (num <= 3) return 1; // 2 and 3 are prime
    if (num % 2 == 0 || num % 3 == 0) return 0; // Eliminate multiples of 2 and 3

    for (int i = 5; i <= sqrt(num); i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0; // Check divisibility for potential primes
    }

    return 1; // The number is prime
}

// Function to generate and print prime numbers up to a certain limit
void generate_primes(int limit) {
    // Array to hold the prime numbers
    int *primes = (int *)malloc(limit * sizeof(int));
    if (primes == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }

    int count = 0; // Counter for prime numbers found

    // Check every number from 2 to limit
    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            primes[count++] = num; // Store prime number
        }
    }

    // Print the prime numbers found
    printf("Prime numbers up to %d:\n", limit);
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
        // Print a new line after every 10 numbers for better readability
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
    printf("\n");

    // Clean up memory
    free(primes);
}

int main() {
    int limit;

    printf("Welcome to the Prime Number Generator!\n");
    printf("Please enter your upper limit for generating prime numbers (up to %d): ", MAX_NUM);
    scanf("%d", &limit);

    // Input validation
    if (limit < 2 || limit > MAX_NUM) {
        fprintf(stderr, "Error: Please enter a number between 2 and %d.\n", MAX_NUM);
        return 1;
    }

    // Generate and display prime numbers
    generate_primes(limit);

    return 0;
}