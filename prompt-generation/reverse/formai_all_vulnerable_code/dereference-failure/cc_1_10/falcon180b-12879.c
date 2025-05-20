//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_NUM 1000000
#define MAX_PRIMES 10000

int isPrime(int n);
void generatePrimes(int num);

int main() {
    int num, count = 0;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &num);

    srand(time(NULL));
    int *primes = (int *) malloc(MAX_PRIMES * sizeof(int));

    for (int i = 2; count < num; i++) {
        if (isPrime(i)) {
            primes[count++] = i;
        }
    }

    printf("The first %d prime numbers are:\n", num);
    for (int i = 0; i < num; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    free(primes);
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

void generatePrimes(int num) {
    int primes[MAX_PRIMES], count = 0;
    for (int i = 2; count < num; i++) {
        if (isPrime(i)) {
            primes[count++] = i;
        }
    }
}