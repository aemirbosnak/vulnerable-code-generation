//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void displayPrimes(int*, int);
bool isPrime(int);
void generatePrimes(int);

int main() {
    int limit;

    printf("Enter the limit for prime number generation: ");
    if (scanf("%d", &limit) != 1 || limit < 2) {
        fprintf(stderr, "Please enter a valid integer greater than 1.\n");
        return EXIT_FAILURE;
    }

    generatePrimes(limit);
    return EXIT_SUCCESS;
}

void generatePrimes(int limit) {
    int* primes = (int*)malloc(limit * sizeof(int));
    if (primes == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    int count = 0;

    for (int number = 2; number <= limit; number++) {
        if (isPrime(number)) {
            primes[count++] = number;
        }
    }

    displayPrimes(primes, count);
    free(primes);
}

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    if (num <= 3) {
        return true;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

void displayPrimes(int* primes, int count) {
    printf("Prime numbers up to the limit:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}