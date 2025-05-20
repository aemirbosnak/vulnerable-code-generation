//MISTRAL-7B DATASET v1.0 Category: Prime Number Generator ; Style: ultraprecise
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_PRIME_LENGTH 50
#define MIN_PRIME 2
#define MAX_PRIME 2147483647

bool is_prime(unsigned long long int num) {
    if (num <= 1) {
        return false;
    }

    for (unsigned long long int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

void print_prime(unsigned long long int prime) {
    char prime_string[MAX_PRIME_LENGTH];

    if (sprintf(prime_string, "%llu", prime) >= MAX_PRIME_LENGTH) {
        fprintf(stderr, "Error: Prime number too large to print.\n");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", prime_string);
}

void generate_primes(unsigned long long int start, unsigned long long int end) {
    unsigned long long int num;

    for (num = start; num <= end; num++) {
        if (is_prime(num)) {
            print_prime(num);
        }
    }
}

int main() {
    unsigned long long int m, n;

    if (scanf("%llu%llu", &m, &n) != 2) {
        fprintf(stderr, "Error: Invalid input.\n");
        exit(EXIT_FAILURE);
    }

    if (m > n) {
        unsigned long long int temp = m;
        m = n;
        n = temp;
    }

    generate_primes(m, n);

    return EXIT_SUCCESS;
}