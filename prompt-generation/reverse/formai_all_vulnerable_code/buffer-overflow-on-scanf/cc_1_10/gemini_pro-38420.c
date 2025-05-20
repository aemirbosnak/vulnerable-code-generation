//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Is the number prime?
int isPrime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    int i = 5;
    while (i * i <= n) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
        i += 6;
    }
    return 1;
}

// Generate a prime number.
int generatePrime(int n) {
    int p = n;
    while (!isPrime(p)) {
        p++;
    }
    return p;
}

// Generate a list of prime numbers.
int* generatePrimes(int n) {
    int* primes = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        primes[i] = generatePrime(i);
    }
    return primes;
}

// Print a list of prime numbers.
void printPrimes(int* primes, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}

// Main function.
int main() {
    int n;
    printf("How many prime numbers do you want to generate? ");
    scanf("%d", &n);

    int* primes = generatePrimes(n);
    printPrimes(primes, n);

    free(primes);
    return 0;
}