//MISTRAL-7B DATASET v1.0 Category: Prime Number Generator ; Style: shocked
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int num;
    bool is_prime;
} prime_number;

void generate_primes(prime_number *primes, int limit) {
    int i, j, sqrt_num;

    for (i = 0; primes[i].num < limit; i++) {
        primes[i].num = i + 2;
        primes[i].is_prime = true;

        for (j = 0; primes[j].num <= sqrt(primes[i].num); j++) {
            if (primes[i].num % primes[j].num == 0) {
                primes[i].is_prime = false;
                break;
            }
        }

        if (primes[i].is_prime) {
            printf("\033[1;31m%d is a prime number!\033[0m\n", primes[i].num);
        }
    }
}

int main() {
    int limit;
    prime_number *primes;

    printf("\033[1;31mShocked Prime Number Generator\033[0m\n");
    printf("Enter the limit: ");
    scanf("%d", &limit);

    primes = malloc(limit * sizeof(prime_number));

    srand(time(NULL));

    generate_primes(primes, limit);

    free(primes);

    return 0;
}