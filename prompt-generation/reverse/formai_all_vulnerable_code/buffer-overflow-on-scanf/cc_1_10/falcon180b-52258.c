//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

int isPrime(int num);

int main() {
    int start, end, count = 0, primeCount = 0;
    int primes[100];
    int i = 0;
    srand(time(NULL)); // seed random number generator with current time

    printf("Enter the starting number: ");
    scanf("%d", &start);

    printf("Enter the ending number: ");
    scanf("%d", &end);

    for (int j = start; j <= end; j++) {
        if (isPrime(j)) {
            primes[i] = j;
            i++;
            primeCount++;
        }
    }

    printf("Total prime numbers found: %d\n", primeCount);
    printf("Prime numbers between %d and %d:\n", start, end);

    for (int k = 0; k < primeCount; k++) {
        printf("%d ", primes[k]);
    }

    return 0;
}

int isPrime(int num) {
    if (num <= 1) {
        return FALSE;
    }

    int i = 2;
    while (i <= num / 2) {
        if (num % i == 0) {
            return FALSE;
        }
        i++;
    }

    return TRUE;
}