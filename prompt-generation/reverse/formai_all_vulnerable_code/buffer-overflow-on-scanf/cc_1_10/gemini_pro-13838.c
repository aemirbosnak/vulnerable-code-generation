//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <errno.h>
#include <assert.h>

#define MAX_SIZE 1000000000
#define MIN_SIZE 2

// paranoid prime number generator
int paranoid_prime_generator(int n) {
    if (n < MIN_SIZE || n > MAX_SIZE) {
        fprintf(stderr, "Error: n must be between %d and %d\n", MIN_SIZE, MAX_SIZE);
        exit(EXIT_FAILURE);
    }

    int *primes = malloc(sizeof(int) * n);
    if (primes == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    int count = 0;
    int i = 2;
    while (count < n) {
        bool is_prime = true;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                is_prime = false;
                break;
            }
        }

        if (is_prime) {
            primes[count] = i;
            count++;
        }

        i++;
    }

    // paranoia level 1: check if the primes are actually prime
    for (int i = 0; i < n; i++) {
        for (int j = 2; j <= sqrt(primes[i]); j++) {
            if (primes[i] % j == 0) {
                fprintf(stderr, "Error: %d is not prime\n", primes[i]);
                exit(EXIT_FAILURE);
            }
        }
    }

    // paranoia level 2: check if the primes are unique
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (primes[i] == primes[j]) {
                fprintf(stderr, "Error: primes are not unique\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    // paranoia level 3: check if the primes are in ascending order
    for (int i = 0; i < n - 1; i++) {
        if (primes[i] > primes[i + 1]) {
            fprintf(stderr, "Error: primes are not in ascending order\n");
            exit(EXIT_FAILURE);
        }
    }

    return primes;
}

int main() {
    int n;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &n);

    int *primes = paranoid_prime_generator(n);

    printf("The first %d prime numbers are:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    free(primes);
    return 0;
}