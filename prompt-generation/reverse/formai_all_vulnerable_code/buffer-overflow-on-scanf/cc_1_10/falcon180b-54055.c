//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_NUM 1000000

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void generate_primes(int num_primes, int min_prime) {
    srand(time(NULL));
    int primes[MAX_NUM];
    int count = 0;
    for (int i = 2; count < num_primes; i++) {
        if (is_prime(i)) {
            primes[count] = i;
            count++;
        }
    }
    if (count < num_primes) {
        printf("Error: Not enough prime numbers found.\n");
        exit(1);
    }
    for (int i = 0; i < num_primes; i++) {
        if (primes[i] < min_prime) {
            primes[i] = primes[i] + (min_prime - primes[i] % min_prime);
        }
    }
    printf("Prime numbers:\n");
    for (int i = 0; i < num_primes; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}

int main() {
    int num_primes;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &num_primes);
    int min_prime;
    printf("Enter the minimum prime number to generate: ");
    scanf("%d", &min_prime);
    generate_primes(num_primes, min_prime);
    return 0;
}