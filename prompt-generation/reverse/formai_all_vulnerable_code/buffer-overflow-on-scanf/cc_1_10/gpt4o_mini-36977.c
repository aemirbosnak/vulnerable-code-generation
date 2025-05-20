//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int number);
void generate_primes(int limit);
void print_primes(int* primes, int count);
int* find_primes(int limit, int* count);

int main() {
    int limit;
    printf("Enter the upper limit for generating prime numbers: ");
    scanf("%d", &limit);

    if (limit < 2) {
        printf("Please enter a limit greater than or equal to 2.\n");
        return 1;
    }

    generate_primes(limit);

    return 0;
}

int is_prime(int number) {
    if (number <= 1) return 0;
    if (number <= 3) return 1;

    if (number % 2 == 0 || number % 3 == 0) return 0;

    for (int i = 5; i <= sqrt(number); i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return 0;
        }
    }
    return 1;
}

void generate_primes(int limit) {
    int count = 0;
    int* primes = find_primes(limit, &count);
    if (primes != NULL) {
        print_primes(primes, count);
        free(primes);
    }
}

int* find_primes(int limit, int* count) {
    int* primes = malloc(limit * sizeof(int));
    if (primes == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            primes[*count] = num;
            (*count)++;
        }
    }
    
    return primes;
}

void print_primes(int* primes, int count) {
    printf("Prime numbers up to the specified limit:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}