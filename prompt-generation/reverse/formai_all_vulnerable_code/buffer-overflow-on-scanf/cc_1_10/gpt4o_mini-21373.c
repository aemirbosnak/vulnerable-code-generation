//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void displayPrimes(int *primes, int size);
int isPrime(int number);
void generatePrimes(int n);

int main() {
    int n;
    printf("Welcome to the Prime Number Generator!\n");
    printf("Please enter the upper limit to generate prime numbers: ");
    if (scanf("%d", &n) != 1 || n < 2) {
        printf("Invalid input. Please enter an integer greater than 1.\n");
        return 1;
    }

    generatePrimes(n);
    return 0;
}

void generatePrimes(int n) {
    int *primes = malloc((n + 1) * sizeof(int));
    if (primes == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    int count = 0;
    for (int num = 2; num <= n; num++) {
        if (isPrime(num)) {
            primes[count++] = num;
        }
    }

    printf("\nGenerated Prime Numbers up to %d:\n", n);
    displayPrimes(primes, count);
    free(primes);
}

int isPrime(int number) {
    if (number < 2) return 0;
    if (number == 2) return 1; // 2 is the only even prime number
    if (number % 2 == 0) return 0; // Exclude all other even numbers

    int sqrtNum = (int)sqrt(number);
    for (int i = 3; i <= sqrtNum; i += 2) {
        if (number % i == 0) {
            return 0;
        }
    }
    return 1;
}

void displayPrimes(int *primes, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}