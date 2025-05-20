//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

// Returns an array of boolean values indicating whether each index is prime
bool* eratosthenes_sieve(int max_num) {
    // Allocate array with enough space for all numbers from 2 to max_num
    bool *is_prime = calloc(max_num - 1, sizeof(bool));
    if (is_prime == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for sieve\n");
        exit(EXIT_FAILURE);
    }

    // Mark all numbers as prime initially
    for (int i = 0; i < max_num - 1; i++) {
        is_prime[i] = true;
    }

    // Process only up to sqrt(max_num) in order to eliminate duplicates
    int max_divisor = sqrt(max_num);
    for (int i = 2; i <= max_divisor; i++) {
        // If i is prime, mark all of its multiples as not prime
        if (is_prime[i - 2]) {
            for (int j = i * i; j <= max_num; j += i) {
                is_prime[j - 2] = false;
            }
        }
    }

    return is_prime;
}

int main() {
    int max_num;

    // Get user input for maximum number to generate primes up to
    do {
        printf("Enter a positive integer up to %d: ", INT_MAX);
        if (scanf("%d", &max_num) != 1) {
            fprintf(stderr, "Error: Invalid input\n");
            exit(EXIT_FAILURE);
        }
        if (max_num <= 1) {
            printf("Input must be greater than 1\n");
        }
    } while (max_num <= 1);

    // Generate primes up to max_num and print them out
    bool *primes = eratosthenes_sieve(max_num);
    printf("Prime numbers up to %d:\n", max_num);
    for (int i = 2; i <= max_num; i++) {
        if (primes[i - 2]) {
            printf("%d\n", i);
        }
    }

    free(primes);
    return 0;
}