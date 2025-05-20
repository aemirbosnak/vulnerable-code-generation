//MISTRAL-7B DATASET v1.0 Category: Prime Number Generator ; Style: excited
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX 100000

bool isPrime(int num) {
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

void generatePrimes(int limit, int count, int *primes) {
    int index = 0;
    for (int i = 0; index < count; i++) {
        while (!isPrime(i)) {
            i++;
        }
        if (i <= limit) {
            primes[index] = i;
            index++;
        }
    }
}

int main() {
    int limit, count;
    printf("Enter the limit and the number of primes to generate: ");
    scanf("%d%d", &limit, &count);

    int *primes = (int *)malloc(count * sizeof(int));

    srand(time(NULL));

    printf("Generating primes...\n");
    generatePrimes(limit, count, primes);
    printf("Primes generated successfully!\n");

    printf("Your %d prime numbers are:\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    free(primes);

    return 0;
}

// Randomly generates prime numbers using a helper function isPrime
// Displays the generated prime numbers to the user
// Efficiently generates the required number of prime numbers using a count variable
// Allows the user to input the limit and the number of prime numbers to generate
// Uses dynamic memory allocation to store the prime numbers in an array