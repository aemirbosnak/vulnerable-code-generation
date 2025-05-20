//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Function to check if a number is prime
int is_prime(int n) {
    int i;
    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate a prime number
int generate_prime(int n) {
    int i, j, count = 0;
    int *primes = malloc(sizeof(int) * n);
    int *is_composite = malloc(sizeof(int) * (n + 1));

    // Initialize all numbers as prime
    for (i = 2; i <= n; i++) {
        primes[count++] = i;
    }

    // Sieve of Eratosthenes algorithm
    for (i = 2; i * i <= n; i++) {
        if (is_composite[i] == 0) {
            for (j = i * i; j <= n; j += i) {
                is_composite[j] = 1;
            }
        }
    }

    // Find the first prime number greater than or equal to n
    while (count < n) {
        i++;
        if (is_composite[i] == 0) {
            primes[count++] = i;
        }
    }

    // Free memory
    free(is_composite);

    return primes[n - 1];
}

int main() {
    int n;

    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &n);

    int *primes = malloc(sizeof(int) * n);
    int i;

    // Generate n prime numbers
    for (i = 0; i < n; i++) {
        primes[i] = generate_prime(i + 1);
        printf("%d ", primes[i]);
    }

    free(primes);

    return 0;
}