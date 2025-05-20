//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sieve_of_eratosthenes(int n, int *primes, int *count) {
    int *is_prime = malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) {
        is_prime[i] = 1; // Assume all numbers are prime initially
    }
    is_prime[0] = is_prime[1] = 0; // 0 and 1 are not prime

    for (int p = 2; p <= sqrt(n); p++) {
        if (is_prime[p]) {
            for (int multiple = p * p; multiple <= n; multiple += p) {
                is_prime[multiple] = 0; // Mark non-prime numbers
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes[(*count)++] = i; // Collect prime numbers
        }
    }
    free(is_prime);
}

unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

void print_primes(int *primes, int count) {
    printf("Generated Prime Numbers:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}

void show_operations(int *primes, int count) {
    int operation;
    do {
        printf("\nChoose an operation:\n");
        printf("1. Add two primes\n");
        printf("2. Multiply two primes\n");
        printf("3. Factorial of a prime\n");
        printf("4. Exit\n");
        printf("Your choice: ");
        scanf("%d", &operation);

        if (operation == 1) {
            int p1, p2;
            printf("Enter two prime indexes (0 to %d): ", count-1);
            scanf("%d %d", &p1, &p2);
            if (p1 < count && p2 < count) {
                printf("Result of %d + %d = %d\n", primes[p1], primes[p2], primes[p1] + primes[p2]);
            } else {
                printf("Invalid indexes.\n");
            }
        } else if (operation == 2) {
            int p1, p2;
            printf("Enter two prime indexes (0 to %d): ", count-1);
            scanf("%d %d", &p1, &p2);
            if (p1 < count && p2 < count) {
                printf("Result of %d * %d = %lld\n", primes[p1], primes[p2], (long long)primes[p1] * primes[p2]);
            } else {
                printf("Invalid indexes.\n");
            }
        } else if (operation == 3) {
            int p;
            printf("Enter a prime index (0 to %d): ", count-1);
            scanf("%d", &p);
            if (p < count) {
                printf("Factorial of %d = %llu\n", primes[p], factorial(primes[p]));
            } else {
                printf("Invalid index.\n");
            }
        } else if (operation == 4) {
            printf("Exiting...\n");
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    } while (operation != 4);
}

int main() {
    int max_range;
    printf("Enter the upper limit for prime generation: ");
    scanf("%d", &max_range);

    if (max_range < 2) {
        printf("Please enter a value greater than 1.\n");
        return 1;
    }

    int *primes = malloc(max_range * sizeof(int));
    int prime_count = 0;

    sieve_of_eratosthenes(max_range, primes, &prime_count);
    print_primes(primes, prime_count);
    show_operations(primes, prime_count);

    free(primes);
    return 0;
}