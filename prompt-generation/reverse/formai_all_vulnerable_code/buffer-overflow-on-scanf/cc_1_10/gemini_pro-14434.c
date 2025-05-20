//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate a list of prime numbers
int* generatePrimes(int numPrimes) {
    int* primes = malloc(sizeof(int) * numPrimes);
    int count = 0;
    int i = 2;
    while (count < numPrimes) {
        if (isPrime(i)) {
            primes[count++] = i;
        }
        i++;
    }
    return primes;
}

// Function to print a list of prime numbers
void printPrimes(int* primes, int numPrimes) {
    for (int i = 0; i < numPrimes; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}

int main() {
    int numPrimes;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &numPrimes);

    int* primes = generatePrimes(numPrimes);

    printf("The first %d prime numbers are: ", numPrimes);
    printPrimes(primes, numPrimes);

    free(primes);

    return 0;
}