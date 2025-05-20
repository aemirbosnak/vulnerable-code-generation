//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define PARANOIA_LEVEL 10

struct paranoia {
    uint8_t prime_checker[PARANOIA_LEVEL];
    uint8_t prime_count;
    uint32_t prime_cache[PARANOIA_LEVEL];
};

static void
init_paranoia(struct paranoia *p)
{
    memset(p, 0, sizeof(*p));
    p->prime_checker[0] = 1;
    p->prime_checker[1] = 1;
    p->prime_count = 2;
}

static uint32_t
get_prime(struct paranoia *p, uint8_t n)
{
    if (n < p->prime_count) {
        return p->prime_cache[n];
    }

    uint32_t next_prime = p->prime_cache[p->prime_count - 1] + 2;
    while (1) {
        uint8_t i;

        for (i = 0; i < PARANOIA_LEVEL; i++) {
            if (p->prime_checker[i] == 0) {
                continue;
            }

            if (next_prime % p->prime_cache[i] == 0) {
                break;
            }
        }

        if (i == PARANOIA_LEVEL) {
            break;
        }

        next_prime += 2;
    }

    if (n == p->prime_count) {
        p->prime_cache[p->prime_count] = next_prime;
        p->prime_count++;
    }

    return next_prime;
}

int
main(void)
{
    struct paranoia p;
    uint32_t n;

    init_paranoia(&p);

    printf("Enter the number of primes to generate: ");
    scanf("%u", &n);

    for (uint32_t i = 0; i < n; i++) {
        printf("%u\n", get_prime(&p, i));
    }

    return 0;
}