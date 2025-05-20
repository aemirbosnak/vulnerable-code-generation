//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// Function to check if a number is prime
int isPrime(int n) {
    int i;
    for (i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            return FALSE;
        }
    }
    return TRUE;
}

// Function to generate prime numbers
void generatePrimes(int num) {
    int i, j;
    int primes[10000]; // Array to store prime numbers
    int count = 0; // Counter for number of prime numbers found

    printf("Generating %d prime numbers...\n", num);

    // Check if 2 is prime
    if (isPrime(2)) {
        primes[count] = 2;
        count++;
    }

    // Generate remaining prime numbers
    for (i = 3; count < num; i++) {
        if (isPrime(i)) {
            primes[count] = i;
            count++;
        }
    }

    // Print prime numbers
    printf("\nPrime numbers: ");
    for (i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}

int main() {
    int num;

    // Post-apocalyptic message
    printf("In the aftermath of the Great Cataclysm, humanity struggles to survive.\n");
    printf("The remnants of civilization have banded together in small communities,\n");
    printf("each one fighting to eke out a living in this harsh new world.\n");
    printf("One such community has tasked you with finding prime numbers,\n");
    printf("believing that these special numbers hold the key to rebuilding society.\n");
    printf("How many prime numbers will you find?\n");

    // Get number of primes to generate from user
    scanf("%d", &num);

    // Generate prime numbers
    generatePrimes(num);

    return 0;
}