//MISTRAL-7B DATASET v1.0 Category: Prime Number Generator ; Style: authentic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LIMIT 65536

bool is_valid_input(char *input) {
    int number;

    errno = 0;
    number = strtol(input, NULL, 10);

    if (errno == ERANGE || number < 0 || number > MAX_LIMIT) {
        return false;
    }

    return true;
}

void sieve_of_eratosthenes(int limit) {
    bool *prime = calloc(limit + 1, sizeof(bool));

    memset(prime, true, sizeof(bool) * (limit + 1));

    for (int p = 2; p * p <= limit; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                prime[i] = false;
            }
        }
    }

    for (int p = 2; p <= limit; p++) {
        if (prime[p]) {
            printf("%d\n", p);
        }
    }

    free(prime);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <limit>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (!is_valid_input(argv[1])) {
        fprintf(stderr, "Invalid input: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    sieve_of_eratosthenes(atoi(argv[1]));

    return EXIT_SUCCESS;
}