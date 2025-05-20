//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void sieve_of_eratosthenes(int limit) {
    // Dynamic array allocation for the sieve
    unsigned char *is_prime = malloc((limit + 1) * sizeof(unsigned char));
    if (is_prime == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Initialize all entries as prime
    for (int i = 0; i <= limit; i++) {
        is_prime[i] = 1; // Assume all numbers are prime
    }
    is_prime[0] = is_prime[1] = 0; // 0 and 1 are not prime numbers

    // Start the sieve of Eratosthenes
    for (int p = 2; p <= sqrt(limit); p++) {
        if (is_prime[p]) {
            for (int multiple = p * p; multiple <= limit; multiple += p) {
                is_prime[multiple] = 0; // Mark multiples as non-prime
            }
        }
    }

    // Print all prime numbers found
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

int main() {
    // Measure execution time
    clock_t start_time, end_time;

    // Define the limit for finding primes
    int limit;
    printf("Enter an upper limit to find prime numbers: ");
    scanf("%d", &limit);

    // Start timing
    start_time = clock();

    // Run the prime number calculation
    sieve_of_eratosthenes(limit);

    // Stop timing
    end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Execution Time: %f seconds\n", time_taken);
    
    return 0;
}