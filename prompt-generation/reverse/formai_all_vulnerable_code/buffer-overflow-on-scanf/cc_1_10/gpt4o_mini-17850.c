//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printPrimes(int limit);
int isPrime(int num);
void encryptAndPrint(int *primes, int count);

int main() {
    int limit;

    printf("Unleash the Mysteries of the Prime Numbers!\n");
    printf("Enter a mystical limit: ");
    scanf("%d", &limit);

    if(limit < 2) {
        printf("The magic starts from 2. Enter a higher number!\n");
        return 1;
    }

    printf("Finding primes up to %d...\n", limit);
    printPrimes(limit);

    return 0;
}

void printPrimes(int limit) {
    int count = 0;
    int *primes = malloc(limit * sizeof(int));

    printf("Behold the primes:\n");
    for(int i = 2; i <= limit; i++) {
        if(isPrime(i)) {
            primes[count++] = i;
            printf("%d ", i);
        }
    }
    printf("\n");

    encryptAndPrint(primes, count);
    free(primes);
}

int isPrime(int num) {
    if(num <= 1) return 0;
    if(num <= 3) return 1;
    if(num % 2 == 0 || num % 3 == 0) return 0;

    for(int i = 5; i * i <= num; i += 6) {
        if(num % i == 0 || num % (i + 2) == 0) return 0;
    }
    return 1;
}

void encryptAndPrint(int *primes, int count) {
    printf("Encrypting the square of each prime:\n");

    for(int i = 0; i < count; i++) {
        int squared = primes[i] * primes[i];
        int encrypted = squared ^ 0xFC;  // A simple encryption technique
        printf("Prime: %d, Square: %d, Encrypted Square: %d\n", primes[i], squared, encrypted);
    }
}