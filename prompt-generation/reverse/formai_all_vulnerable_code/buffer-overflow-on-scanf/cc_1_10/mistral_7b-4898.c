//MISTRAL-7B DATASET v1.0 Category: Prime Number Generator ; Style: introspective
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define MAX_NUM 100000

bool is_prime(unsigned int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;

    for (unsigned int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return false;
    }

    return true;
}

void print_primes(unsigned int start, unsigned int end) {
    unsigned int i;

    printf("Primes between %u and %u:\n", start, end);

    for (i = start; i <= end; i++) {
        if (is_prime(i)) {
            printf("%u ", i);
        }
    }

    printf("\n");
}

void introspect_primes(void) {
    unsigned int num, i, j, limit;
    char buffer[128];

    printf("Enter the limit for prime number generation: ");
    scanf("%u", &num);

    printf("Calculating primes up to %u...\n", num);

    limit = (num < 2) ? 2 : num;

    for (i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            snprintf(buffer, sizeof(buffer), "Prime %u: %u\n", ++j, i);
            printf("%s", buffer);

            if (i >= num)
                break;
        }
    }
}

int main(void) {
    introspect_primes();

    return 0;
}