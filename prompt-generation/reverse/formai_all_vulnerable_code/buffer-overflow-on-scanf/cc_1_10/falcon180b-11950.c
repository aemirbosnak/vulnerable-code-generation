//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: safe
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int isPrime(int n);
void sieveOfEratosthenes(int n);

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    sieveOfEratosthenes(n);
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

void sieveOfEratosthenes(int n) {
    int primes[n + 1];

    for (int i = 2; i <= n; i++) {
        primes[i] = 1;
    }

    for (int i = 2; i <= sqrt(n); i++) {
        if (primes[i] == 1) {
            for (int j = i * i; j <= n; j += i) {
                primes[j] = 0;
            }
        }
    }

    printf("Prime numbers up to %d:\n", n);
    for (int i = 2; i <= n; i++) {
        if (primes[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
}