//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: safe
/* C Prime Number Generator */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int num) {
    int i;
    for (i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int num, count = 0, primeCount = 0;

    printf("Enter the number of integers to generate: ");
    scanf("%d", &num);

    int* primes = (int*) malloc(num * sizeof(int));

    if (primes == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    int j = 2;
    primes[0] = j;
    primeCount++;

    for (int i = 1; i < num; i++) {
        while (isPrime(j) == 0) {
            j++;
        }
        primes[i] = j;
        j++;
        primeCount++;
    }

    printf("Prime numbers generated:\n");

    for (int i = 0; i < num; i++) {
        if (primes[i] == 0) {
            printf("%d\n", primes[i]);
        }
    }

    printf("\nTotal number of primes generated: %d\n", primeCount);

    return 0;
}

/* End of program */