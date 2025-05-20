//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printPrimes(int *primes, int count);
bool isPrime(int number);
int* generatePrimes(int limit, int *count);

int main() {
    int limit;
    int count;
    int *primes = NULL;

    printf("Welcome to the Prime Number Generator!\n");
    printf("Please enter the upper limit for generating prime numbers: ");
    if (scanf("%d", &limit) != 1 || limit <= 1) {
        fprintf(stderr, "Invalid input. Please enter a positive integer greater than 1.\n");
        return EXIT_FAILURE;
    }

    primes = generatePrimes(limit, &count);
    if (primes == NULL) {
        fprintf(stderr, "Error allocating memory for prime numbers.\n");
        return EXIT_FAILURE;
    }

    printPrimes(primes, count);

    free(primes);
    return EXIT_SUCCESS;
}

int* generatePrimes(int limit, int *count) {
    int *tempPrimes = malloc((limit / 2) * sizeof(int)); // Rough estimation
    if (tempPrimes == NULL) {
        return NULL;
    }

    int tempCount = 0;

    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            tempPrimes[tempCount++] = i;
        }
    }

    // Resize to fit the exact number of primes found
    int *primes = realloc(tempPrimes, tempCount * sizeof(int));
    *count = tempCount;
    return primes;
}

bool isPrime(int number) {
    if (number < 2) return false;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

void printPrimes(int *primes, int count) {
    printf("Prime numbers up to the given limit:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\nTotal prime numbers found: %d\n", count);
}