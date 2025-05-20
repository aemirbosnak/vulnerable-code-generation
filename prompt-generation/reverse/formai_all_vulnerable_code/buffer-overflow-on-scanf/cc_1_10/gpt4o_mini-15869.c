//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void generatePrimes(int n);
bool isPrime(int num);
void displayPrimes(int *primes, int count);
void freeMemory(int *primes);

int main() {
    int n;

    printf("Enter the upper limit to generate prime numbers: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("There are no prime numbers less than 2.\n");
        return 1;
    }

    printf("Generating prime numbers up to %d...\n", n);
    generatePrimes(n);

    return 0;
}

void generatePrimes(int n) {
    int *primes = malloc(n * sizeof(int));
    if (primes == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int count = 0;
    for (int num = 2; num <= n; num++) {
        if (isPrime(num)) {
            primes[count] = num;
            count++;
        }
    }

    displayPrimes(primes, count);
    freeMemory(primes);
}

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;

    if (num % 2 == 0 || num % 3 == 0) return false;

    for (int i = 5; i <= sqrt(num); i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }

    return true;
}

void displayPrimes(int *primes, int count) {
    if (count == 0) {
        printf("No prime numbers found.\n");
        return;
    }

    printf("Prime numbers:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}

void freeMemory(int *primes) {
    free(primes);
}