//MISTRAL-7B DATASET v1.0 Category: Prime Number Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

typedef struct {
    int number;
    bool is_prime;
} prime_number;

void sieve_of_eratosthenes(prime_number *primes, int limit) {
    int i, j;

    for (i = 0; i < limit; i++) {
        primes[i].number = i;
        primes[i].is_prime = true;
    }

    primes[0].is_prime = false;
    primes[1].is_prime = false;

    for (i = 2; i * i < limit; i++) {
        if (primes[i].is_prime) {
            for (j = i * i; j < limit; j += i) {
                primes[j].is_prime = false;
            }
        }
    }
}

void print_primes(prime_number *primes, int limit) {
    int i;

    printf("Prime numbers up to %d:\n", limit);

    for (i = 0; primes[i].number <= limit && primes[i].is_prime; i++) {
        printf("%d ", primes[i].number);
    }

    printf("\n");
}

int main() {
    int limit, num_primes;
    clock_t start, end;
    prime_number *primes;

    printf("Enter the limit for prime number generation: ");
    scanf("%d", &limit);

    start = clock();

    primes = (prime_number *) calloc(limit, sizeof(prime_number));

    sieve_of_eratosthenes(primes, limit);

    print_primes(primes, limit);

    num_primes = 0;
    for (int i = 0; primes[i].number <= limit && primes[i].is_prime; i++) {
        num_primes++;
    }

    printf("Number of prime numbers up to %d: %d\n", limit, num_primes);

    free(primes);

    end = clock();

    printf("Elapsed time: %f seconds\n", (float) (end - start) / CLOCKS_PER_SEC);

    return 0;
}