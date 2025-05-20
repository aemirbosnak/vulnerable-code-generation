//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_PRIMES 10000

int primes[MAX_PRIMES];
int num_primes = 0;
int num_generated = 0;

void generate_primes(int n) {
    int i, j;
    for (i = 2; i <= n; i++) {
        if (is_prime(i)) {
            primes[num_primes++] = i;
            if (num_primes == MAX_PRIMES) {
                printf("Too many primes generated!\n");
                exit(1);
            }
        }
        if (num_generated % 100000 == 0) {
            printf("Generated %d primes so far...\n", num_generated);
        }
        num_generated++;
    }
}

int is_prime(int n) {
    int i;
    if (n <= 1) {
        return 0;
    }
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
    int n;
    if (argc < 2) {
        n = 1000;
    } else {
        n = atoi(argv[1]);
    }
    srand(time(NULL));
    generate_primes(n);
    printf("Generated %d primes:\n", num_primes);
    for (int i = 0; i < num_primes; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
    return 0;
}