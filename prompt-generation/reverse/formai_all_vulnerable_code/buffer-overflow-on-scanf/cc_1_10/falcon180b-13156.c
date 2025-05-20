//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX_PRIME 10000
#define MAX_NUM 1000000

void sieveOfEratosthenes(int n) {
    int i, j;
    int primes[MAX_PRIME];
    int count = 0;

    for (i = 2; i <= n; i++) {
        primes[count++] = i;
    }

    for (i = 2; i * i <= n; i++) {
        for (j = 0; j < count; j++) {
            if (primes[j] == i) {
                continue;
            }
            if (primes[j] % i == 0) {
                break;
            }
        }
        if (j == count) {
            primes[count++] = i;
        }
    }

    printf("Prime numbers up to %d:\n", n);
    for (i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    sieveOfEratosthenes(n);

    return 0;
}