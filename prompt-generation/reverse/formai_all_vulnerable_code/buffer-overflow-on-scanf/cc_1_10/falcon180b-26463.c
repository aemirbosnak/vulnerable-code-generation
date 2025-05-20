//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_NUM 100000000

int isPrime(int num);
void sieve(int n, int primes[]);

int main() {
    int n, count = 0;
    int primes[MAX_NUM];

    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &n);

    srand(time(NULL));
    for (int i = 2; i <= MAX_NUM; i++) {
        primes[i] = i;
    }

    sieve(n, primes);

    printf("The first %d prime numbers are:\n", n);
    for (int i = 2; i <= MAX_NUM; i++) {
        if (primes[i] == i) {
            printf("%d ", i);
            count++;
        }
        if (count == n) {
            break;
        }
    }

    return 0;
}

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

void sieve(int n, int primes[]) {
    int i, j;
    for (i = 2; i <= MAX_NUM; i++) {
        primes[i] = 1;
    }

    for (i = 2; i <= sqrt(MAX_NUM); i++) {
        if (primes[i] == 1) {
            for (j = i * i; j <= MAX_NUM; j += i) {
                primes[j] = 0;
            }
        }
    }

    int count = 0;
    for (i = 2; i <= MAX_NUM; i++) {
        if (primes[i] == 1) {
            primes[i] = count + 1;
            count++;
        }
        if (count == n) {
            break;
        }
    }
}