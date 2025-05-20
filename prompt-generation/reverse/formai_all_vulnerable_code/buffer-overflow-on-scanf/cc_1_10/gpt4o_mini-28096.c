//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Function prototypes
bool is_prime(int num);
void generate_primes(int limit);
void print_primes(int *primes, int count);

int main() {
    int limit;
    
    // Asking user for the upper limit to generate primes
    printf("Enter the upper limit to generate prime numbers: ");
    if (scanf("%d", &limit) != 1 || limit < 2) {
        printf("Please enter a valid integer greater than or equal to 2.\n");
        return 1;
    }

    // Generate prime numbers for the given limit
    generate_primes(limit);

    return 0;
}

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;

    for (int i = 5; i <= sqrt(num); i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate primes up to a limit
void generate_primes(int limit) {
    int *primes = malloc(limit * sizeof(int));
    if (!primes) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }

    int count = 0;
    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            primes[count++] = num;
        }
    }

    // Print the prime numbers generated
    print_primes(primes, count);

    // Free allocated memory
    free(primes);
}

// Function to print the array of prime numbers
void print_primes(int *primes, int count) {
    printf("Prime numbers up to the specified limit:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}