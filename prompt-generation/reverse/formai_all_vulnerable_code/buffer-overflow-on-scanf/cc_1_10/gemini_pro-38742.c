//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_PRIME 1000000

// A simple Sieve of Eratosthenes
bool* sieve_of_eratosthenes(int n) {
    bool* is_prime = malloc(sizeof(bool) * (n + 1));
    for (int i = 0; i <= n; i++) {
        is_prime[i] = true;
    }
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

// A segmented sieve to generate all the primes up to n
void segmented_sieve(int n) {
    // Create a boolean array to store the prime numbers
    bool* is_prime = malloc(sizeof(bool) * (n + 1));
    for (int i = 0; i <= n; i++) {
        is_prime[i] = true;
    }

    // Create a segment size
    int segment_size = sqrt(n);

    // Iterate over the segments
    for (int i = 1; i <= n; i += segment_size) {
        // Find the minimum and maximum of the current segment
        int min = i;
        int max = min + segment_size - 1;
        if (max > n) {
            max = n;
        }

        // Sieve the current segment
        bool* segment_is_prime = sieve_of_eratosthenes(max);

        // Transfer the results back to the main is_prime array
        for (int j = min; j <= max; j++) {
            is_prime[j] = segment_is_prime[j];
        }
    }

    // Print the prime numbers
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number up to which you want to generate prime numbers: ");
    scanf("%d", &n);
    segmented_sieve(n);
    return 0;
}