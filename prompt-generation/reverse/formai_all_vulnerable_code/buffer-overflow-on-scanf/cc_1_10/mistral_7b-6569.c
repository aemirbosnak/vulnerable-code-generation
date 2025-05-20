//MISTRAL-7B DATASET v1.0 Category: Performance-Critical Component ; Style: minimalist
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAX_PRIMES 10000

void sieve(uint32_t *primes, size_t limit) {
    size_t i, j;
    uint32_t mark = 0;

    memset(primes, 0, sizeof(uint32_t) * limit);

    for (i = 2; i < limit; ++i) {
        if (!primes[i]) {
            primes[i] = i;
            for (j = i * i; j < limit; j += i) {
                primes[j] = mark;
            }
        }
    }
}

bool is_prime(uint32_t n) {
    static uint32_t primes[MAX_PRIMES];
    size_t i;

    if (n <= 1) {
        return false;
    }

    sieve(primes, MAX_PRIMES);

    for (i = 0; primes[i] * primes[i] <= n; ++i) {
        if (n % primes[i] == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    uint32_t num, i;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (!is_prime(num)) {
        printf("%d is not a prime number.\n", num);
    } else {
        printf("%d is a prime number.\n", num);
    }

    for (i = 1; i <= 10 && i <= num; ++i) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}