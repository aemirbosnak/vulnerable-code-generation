//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: portable
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void displayPrimes(int *primes, int count) {
    printf("Prime numbers:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}

bool isPrime(int number) {
    if (number <= 1) return false;
    if (number <= 3) return true;
    if (number % 2 == 0 || number % 3 == 0) return false;

    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

void generatePrimes(int start, int end) {
    if (start > end) {
        printf("Invalid range. Starting point must be less than or equal to the ending point.\n");
        return;
    }

    int *primes = malloc((end - start + 1) * sizeof(int));
    if (primes == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    int count = 0;

    for (int num = start; num <= end; num++) {
        if (isPrime(num)) {
            primes[count++] = num;
        }
    }

    displayPrimes(primes, count);
    free(primes);
}

int main() {
    int start, end;

    printf("Enter the starting range: ");
    while (scanf("%d", &start) != 1) {
        printf("Invalid input. Please enter an integer: ");
        while(getchar() != '\n'); // Clear input buffer
    }

    printf("Enter the ending range: ");
    while (scanf("%d", &end) != 1) {
        printf("Invalid input. Please enter an integer: ");
        while(getchar() != '\n'); // Clear input buffer
    }

    generatePrimes(start, end);

    return 0;
}