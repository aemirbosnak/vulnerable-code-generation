//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000000
#define TRUE 1
#define FALSE 0

int isPrime(int num);
void sieveOfEratosthenes(int limit);

int main() {
    int limit, i, j, count = 0;
    printf("Enter the limit: ");
    scanf("%d", &limit);
    sieveOfEratosthenes(limit);
    printf("\nPrime numbers up to %d:\n", limit);
    for (i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
            count++;
        }
        if (count == 10) {
            break;
        }
    }
    return 0;
}

int isPrime(int num) {
    if (num <= 1) {
        return FALSE;
    }
    int i;
    for (i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return FALSE;
        }
    }
    return TRUE;
}

void sieveOfEratosthenes(int limit) {
    int i, j;
    int primes[MAX];
    for (i = 0; i <= limit; i++) {
        primes[i] = TRUE;
    }
    primes[0] = primes[1] = FALSE;
    for (i = 2; i <= sqrt(limit); i++) {
        if (primes[i]) {
            for (j = i * i; j <= limit; j += i) {
                primes[j] = FALSE;
            }
        }
    }
}