//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Check if a number is prime.
 *
 * @param n The number to check.
 * @return True if n is prime, false otherwise.
 */
bool is_prime(int n) {
    if (n < 2) {
        return false;
    }
    if (n % 2 == 0 && n != 2) {
        return false;
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

/**
 * Generate the first n prime numbers.
 *
 * @param n The number of prime numbers to generate.
 * @return An array of the first n prime numbers.
 */
int* generate_primes(int n) {
    if (n < 1) {
        return NULL;
    }
    int* primes = malloc(sizeof(int) * n);
    int count = 0;
    for (int i = 2; ; i++) {
        if (is_prime(i)) {
            primes[count] = i;
            count++;
            if (count == n) {
                break;
            }
        }
    }
    return primes;
}

int main() {
    int n;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &n);
    int* primes = generate_primes(n);
    if (primes == NULL) {
        printf("Invalid input.\n");
        return EXIT_FAILURE;
    }
    printf("The first %d prime numbers are:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
    free(primes);
    return EXIT_SUCCESS;
}