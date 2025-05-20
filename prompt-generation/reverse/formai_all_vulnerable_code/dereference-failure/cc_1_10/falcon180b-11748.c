//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUM 1000000
#define IS_PRIME(n) ((n) > 1)

// Function to check if a number is prime or not
int isPrime(int n) {
    if (n <= 1)
        return 0;

    int i;

    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

// Function to generate all prime numbers up to a given limit
void generatePrimes(int limit) {
    int i, j;
    int *primes = (int *) malloc((limit + 1) * sizeof(int));
    int count = 0;

    primes[count++] = 2;

    for (i = 3; i <= limit; i += 2) {
        if (isPrime(i)) {
            primes[count++] = i;
        }
    }

    printf("Prime numbers up to %d:\n", limit);

    for (i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }

    free(primes);
}

int main() {
    int limit;

    printf("Enter the limit: ");
    scanf("%d", &limit);

    if (limit <= 1 || limit > MAX_NUM) {
        printf("Invalid limit.\n");
        return 1;
    }

    generatePrimes(limit);

    return 0;
}