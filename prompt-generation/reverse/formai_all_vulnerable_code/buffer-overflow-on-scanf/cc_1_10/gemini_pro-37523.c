//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Sieve of Eratosthenes algorithm
void sieve_of_eratosthenes(bool *primes, int n) {
    // Initialize all elements to true
    for (int i = 0; i <= n; i++) {
        primes[i] = true;
    }

    // Set 0 and 1 to false
    primes[0] = primes[1] = false;

    // Iterate over all numbers from 2 to the square root of n
    for (int i = 2; i <= (int)sqrt(n); i++) {
        // If i is prime, mark all multiples of i as false
        if (primes[i]) {
            for (int j = i * i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }
}

// Print all prime numbers up to n
void print_primes(int n) {
    // Create a boolean array to store prime numbers
    bool *primes = malloc((n + 1) * sizeof(bool));

    // Use the Sieve of Eratosthenes algorithm to find all prime numbers up to n
    sieve_of_eratosthenes(primes, n);

    // Print all prime numbers
    for (int i = 2; i <= n; i++) {
        if (primes[i]) {
            printf("%d\n", i);
        }
    }

    // Free the memory allocated for the boolean array
    free(primes);
}

int main() {
    // Get the input from the user
    int n;
    printf("Enter the maximum number to generate prime numbers for: ");
    scanf("%d", &n);

    // Print all prime numbers up to n
    print_primes(n);

    return 0;
}