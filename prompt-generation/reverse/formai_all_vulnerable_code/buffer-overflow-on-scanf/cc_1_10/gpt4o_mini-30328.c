//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_NUM 1000

// Function to check primality using trial division
bool is_prime(int number) {
    if (number <= 1) return false; // Eliminating 0, 1, and negative numbers
    if (number <= 3) return true;  // 2 and 3 are prime numbers

    // Check for even numbers and multiples of 3
    if (number % 2 == 0 || number % 3 == 0) return false;

    // Check from 5 to the square root of the number
    int limit = (int)sqrt(number);
    for (int i = 5; i <= limit; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return false; // Divisible by a prime
        }
    }
    return true;
}

// Function to generate prime numbers within a given range
void generate_primes(int limit) {
    printf("Generating prime numbers up to: %d\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i); // Print the prime number
        }
    }
    printf("\n");
}

// Function to print and format the result
void print_primes(int *primes, int count) {
    printf("Total prime numbers found: %d\n", count);
    printf("Prime numbers: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
        if ((i + 1) % 10 == 0) printf("\n"); // Format output in a new line every 10 primes
    }
    printf("\n");
}

// Function to count and store prime numbers
int collect_primes(int limit, int *primes) {
    int prime_count = 0;
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            primes[prime_count++] = i; // Store prime
        }
    }
    return prime_count; // Return the count of primes found
}


int main() {
    int *primes = malloc(MAX_NUM * sizeof(int)); // Dynamic memory allocation for prime storage
    if (primes == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    int limit;
    printf("Enter the upper limit for prime generation (max %d): ", MAX_NUM);
    if (scanf("%d", &limit) != 1 || limit < 1 || limit > MAX_NUM) {
        fprintf(stderr, "Invalid input! Please enter a number between 1 and %d.\n", MAX_NUM);
        free(primes);
        return EXIT_FAILURE;
    }

    printf("Initiating prime number generation...\n");
    int count = collect_primes(limit, primes);
    print_primes(primes, count);

    free(primes); // Free allocated memory
    return EXIT_SUCCESS;
}