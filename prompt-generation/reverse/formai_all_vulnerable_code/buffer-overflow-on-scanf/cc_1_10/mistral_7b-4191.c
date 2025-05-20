//MISTRAL-7B DATASET v1.0 Category: Prime Number Generator ; Style: energetic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LIMIT 65536 // Maximum limit to generate prime numbers
#define BUFFER_SIZE 1024 // Buffer size for prime number storage

typedef struct {
    int num;
    bool is_prime;
} number_t;

void sieve_of_eratosthenes(number_t *numbers, int limit) {
    int i, j;

    for (i = 0; i < limit; ++i) {
        numbers[i].num = i;
        numbers[i].is_prime = true;
    }

    for (i = 2; i * i <= limit; ++i) {
        if (numbers[i].is_prime) {
            for (j = i * i; j <= limit; j += i) {
                numbers[j].is_prime = false;
            }
        }
    }
}

void print_prime_numbers(number_t *numbers, int count) {
    int i;

    printf("Prime numbers up to %d:\n", MAX_LIMIT);

    for (i = 0; i < count; ++i) {
        if (numbers[i].is_prime) {
            printf("%d ", numbers[i].num);
        }
    }

    printf("\n");
}

int main() {
    number_t numbers[BUFFER_SIZE];
    int limit, count = 0;

    srand(time(NULL));

    printf("Enter the limit to generate prime numbers up to: ");
    scanf("%d", &limit);

    if (limit > MAX_LIMIT) {
        printf("Limit too high! Maximum limit is %d.\n", MAX_LIMIT);
        return 1;
    }

    sieve_of_eratosthenes(numbers, limit);

    for (int i = 0; i < limit; ++i) {
        if (numbers[i].is_prime) {
            count++;
        }
    }

    if (count == 0) {
        printf("There are no prime numbers up to %d.\n", limit);
    } else {
        print_prime_numbers(numbers, count);
    }

    return 0;
}

// Generates prime numbers using the Sieve of Eratosthenes algorithm
// in an energetic and creative way!