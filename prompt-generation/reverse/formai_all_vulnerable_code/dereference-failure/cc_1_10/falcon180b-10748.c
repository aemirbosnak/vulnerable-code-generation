//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUM 100000
#define MAX_PRIMES 1000

// Function to check if a number is prime
int isPrime(int num) {
    int i;
    for (i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate prime numbers
void generatePrimes(int primes[], int count) {
    int i, j;
    for (i = 2; count > 0; i++) {
        if (isPrime(i)) {
            primes[count - 1] = i;
            count--;
        }
    }
}

int main() {
    int primes[MAX_PRIMES];
    int numPrimes;
    int i;

    // Get number of primes to generate
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &numPrimes);

    // Generate prime numbers
    generatePrimes(primes, numPrimes);

    // Print prime numbers
    printf("The first %d prime numbers are:\n", numPrimes);
    for (i = 0; i < numPrimes; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    return 0;
}