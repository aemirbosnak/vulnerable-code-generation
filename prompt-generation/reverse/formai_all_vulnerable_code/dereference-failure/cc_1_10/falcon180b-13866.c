//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PRIME_NUMBER 1000
#define MAX_PRIME_NUMBER_STRING_LENGTH 8

typedef struct {
    int *primeNumbers;
    int primeNumberCount;
} PrimeNumbers;

int isPrime(int n);
void generatePrimeNumbers(PrimeNumbers *primeNumbers);
void printPrimeNumbers(PrimeNumbers primeNumbers);

int main() {
    PrimeNumbers primeNumbers;
    generatePrimeNumbers(&primeNumbers);
    printPrimeNumbers(primeNumbers);
    return 0;
}

int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

void generatePrimeNumbers(PrimeNumbers *primeNumbers) {
    int *primeNumbersArray = malloc(MAX_PRIME_NUMBER * sizeof(int));
    primeNumbers->primeNumbers = primeNumbersArray;
    primeNumbers->primeNumberCount = 0;

    int i = 2;
    while (primeNumbers->primeNumberCount < MAX_PRIME_NUMBER) {
        if (isPrime(i)) {
            primeNumbersArray[primeNumbers->primeNumberCount++] = i;
        }
        i++;
    }
}

void printPrimeNumbers(PrimeNumbers primeNumbers) {
    printf("Prime numbers:\n");
    for (int i = 0; i < primeNumbers.primeNumberCount; i++) {
        printf("%d ", primeNumbers.primeNumbers[i]);
    }
    printf("\n");
}