//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: Claude Shannon
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10000000
#define TRUE 1
#define FALSE 0

// Function to check if a number is prime
int isPrime(int num) {
    int i;
    for (i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return FALSE;
        }
    }
    return TRUE;
}

// Function to generate prime numbers
void generatePrimes(int start, int end) {
    int i, j, count = 0;
    int primes[MAX_NUM];
    srand(time(NULL));

    // Sieve of Eratosthenes algorithm
    for (i = 2; i <= end; i++) {
        primes[i] = TRUE;
    }

    for (i = 2; i <= sqrt(end); i++) {
        if (primes[i] == TRUE) {
            for (j = i*i; j <= end; j += i) {
                primes[j] = FALSE;
            }
        }
    }

    // Print prime numbers
    for (i = start; i <= end; i++) {
        if (primes[i] == TRUE && i!= 1) {
            printf("%d ", i);
            count++;
        }
        if (count >= 10) {
            break;
        }
    }
}

int main() {
    int start, end, numPrimes;

    // Get user input for range and number of primes
    printf("Enter the starting number: ");
    scanf("%d", &start);
    printf("Enter the ending number: ");
    scanf("%d", &end);
    printf("Enter the number of primes: ");
    scanf("%d", &numPrimes);

    // Generate prime numbers
    generatePrimes(start, end);

    return 0;
}