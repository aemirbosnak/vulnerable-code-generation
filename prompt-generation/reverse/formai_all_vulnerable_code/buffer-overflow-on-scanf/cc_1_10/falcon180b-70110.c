//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: scientific
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10000000
#define MAX_PRIMES 10000

// Function to check if a number is prime
int is_prime(int n) {
    int i, sqrt_n;
    sqrt_n = sqrt(n);
    for (i = 2; i <= sqrt_n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate prime numbers
void generate_primes(int num_primes, int *primes) {
    int i, j, is_prime;
    for (i = 2; i <= MAX_NUM; i++) {
        is_prime = 1;
        for (j = 0; j < i - 1; j++) {
            if (i % primes[j] == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime && num_primes > 0) {
            primes[num_primes - 1] = i;
            num_primes--;
        }
    }
}

// Function to print primes in a formatted manner
void print_primes(int num_primes, int *primes) {
    int i;
    printf("Prime numbers:\n");
    for (i = 0; i < num_primes; i++) {
        printf("%d\n", primes[i]);
    }
}

int main() {
    int num_primes, primes[MAX_PRIMES];
    srand(time(NULL));

    // Get number of primes to generate from user
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &num_primes);

    // Generate prime numbers
    generate_primes(num_primes, primes);

    // Print prime numbers
    print_primes(num_primes, primes);

    return 0;
}