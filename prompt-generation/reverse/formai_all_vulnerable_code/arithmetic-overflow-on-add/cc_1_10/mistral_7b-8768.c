//MISTRAL-7B DATASET v1.0 Category: Prime Number Generator ; Style: brave
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int size;
    int *numbers;
} sieve;

void sieve_init(sieve *s, int limit) {
    s->size = limit;
    s->numbers = calloc(limit + 1, sizeof(int));
    for (int i = 0; i <= limit; ++i) {
        s->numbers[i] = 1;
    }
    s->numbers[0] = s->numbers[1] = 0;
}

void sieve_generate(sieve *s) {
    int p = 2;
    while (p * p <= s->size) {
        if (s->numbers[p] > 0) {
            for (int i = p * p; i <= s->size; i += p) {
                s->numbers[i] = 0;
            }
        }
        for (int i = p + p; i <= s->size; i += 2 * p) {
            if (s->numbers[i] > 0) {
                break;
            }
            p++;
        }
    }
}

void print_primes(sieve s) {
    for (int i = 2; i < s.size; ++i) {
        if (s.numbers[i] > 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);

    sieve my_sieve;
    sieve_init(&my_sieve, limit);
    sieve_generate(&my_sieve);
    print_primes(my_sieve);

    int fd = open("/dev/urandom", O_RDONLY);
    char buffer[32];
    read(fd, buffer, sizeof(buffer));
    close(fd);

    srand(strtoul(buffer, NULL, 16));

    int num_to_find = rand() % limit + 1;
    printf("Searching for prime number %d...\n", num_to_find);

    int found = 0;
    for (int i = 2; i < my_sieve.size; ++i) {
        if (my_sieve.numbers[i] > 0 && i == num_to_find) {
            printf("Found prime number %d!\n", i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Could not find prime number %d.\n", num_to_find);
    }

    free(my_sieve.numbers);

    return 0;
}