//MISTRAL-7B DATASET v1.0 Category: Prime Number Generator ; Style: introspective
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct {
    int number;
    bool is_prime;
} number_t;

void generate_numbers(number_t* numbers, int limit) {
    for (int i = 0; i < limit; ++i) {
        numbers[i].number = i;
        numbers[i].is_prime = true;
    }
}

void check_prime(number_t* numbers, int index) {
    if (numbers[index].number < 2) {
        numbers[index].is_prime = false;
        return;
    }

    for (int divisor = 2; divisor * divisor <= numbers[index].number; ++divisor) {
        if (numbers[index].number % divisor == 0) {
            numbers[index].is_prime = false;
            return;
        }
    }
}

void print_primes(number_t* numbers, int limit) {
    puts("Prime numbers up to and including the square root of the given limit:");

    for (int i = 0; i < limit; ++i) {
        if (numbers[i].is_prime) {
            printf("%d ", numbers[i].number);
        }
    }

    puts("");
}

int main() {
    int limit;

    puts("Enter the limit:");
    scanf("%d", &limit);

    number_t* numbers = malloc(limit * sizeof(number_t));

    if (numbers == NULL) {
        perror("Memory allocation failed");
        return EXIT_FAILURE;
    }

    srand(time(NULL));

    generate_numbers(numbers, limit);

    for (int i = 0; i < limit; ++i) {
        if (i % 100 == 0) {
            printf("Checking number %d...", numbers[i].number);
            fflush(stdout);
        }

        check_prime(numbers, i);

        if (i % 100 == 0) {
            puts("done.");
        }
    }

    print_primes(numbers, limit);

    free(numbers);

    return EXIT_SUCCESS;
}