//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to check if a number is prime
int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate a list of prime numbers
void generate_primes(int n, int* primes) {
    int count = 0;
    int num = 2;
    while (count < n) {
        if (is_prime(num)) {
            primes[count] = num;
            count++;
        }
        num++;
    }
}

int main() {
    int n;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &n);

    int primes[n];

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate a list of n prime numbers
    generate_primes(n, primes);

    // Print the list of prime numbers
    printf("List of %d prime numbers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    return 0;
}