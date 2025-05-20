//MISTRAL-7B DATASET v1.0 Category: Prime Number Generator ; Style: optimized
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAX_LIMIT 65536

typedef struct {
    bool isPrime;
    uint16_t number;
} Sieve;

void sieve_init(Sieve *sieve, uint16_t limit) {
    memset(sieve, 0, sizeof(Sieve) * (limit + 1));
    for (uint16_t i = 0; i <= limit; i++) {
        sieve[i].number = i;
        sieve[i].isPrime = true;
    }
    sieve[0].isPrime = false;
    sieve[1].isPrime = false;
}

void sieve_generatePrimes(Sieve *sieve, uint16_t limit) {
    if (limit > MAX_LIMIT) {
        fprintf(stderr, "Limit too high\n");
        return;
    }

    for (uint16_t i = 2; i <= limit; i += 2) {
        if (sieve[i].isPrime) {
            for (uint16_t j = i * i; j <= limit; j += i * 2) {
                sieve[j].isPrime = false;
            }
        }
    }
}

int main() {
    Sieve sieve[MAX_LIMIT];
    uint16_t limit;

    printf("Enter the limit: ");
    scanf("%hu", &limit);

    sieve_init(sieve, limit);
    sieve_generatePrimes(sieve, limit);

    printf("Prime numbers up to %hu:\n", limit);
    for (uint16_t i = 2; i <= limit; i += 2) {
        if (sieve[i].isPrime) {
            printf("%hu ", sieve[i].number);
        }
    }
    printf("\n");

    return 0;
}