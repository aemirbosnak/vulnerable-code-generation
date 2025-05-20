//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
void printIntroduction();
void generatePrimes(int);
int isPrime(int);
void displayPrimes(int*, int);

int main() {
    printIntroduction();
    
    int limit;
    printf("Enter the upper limit (positive integer) to generate prime numbers: ");
    while (scanf("%d", &limit) != 1 || limit <= 0) {
        printf("Please enter a valid positive integer: ");
        while (getchar() != '\n'); // Clear invalid input
    }

    generatePrimes(limit);
    return 0;
}

void printIntroduction() {
    printf("===========================================\n");
    printf("          Prime Number Generator          \n");
    printf("===========================================\n");
    printf("Welcome brave coder! This program will help you\n");
    printf("generate all prime numbers up to a specified limit.\n\n");
}

void generatePrimes(int limit) {
    // Dynamic allocation for prime numbers
    int *primes = malloc(limit * sizeof(int));
    if (primes == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    int count = 0; // Count of the primes found
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            primes[count++] = i; // Store the prime number
        }
    }

    // Display the found prime numbers
    displayPrimes(primes, count);
    free(primes); // Free allocated memory
}

int isPrime(int num) {
    if (num < 2) return 0; // Numbers less than 2 are not prime
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0; // Not a prime number
        }
    }
    return 1; // Is a prime number
}

void displayPrimes(int* primes, int count) {
    printf("\nList of prime numbers:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n\nTotal prime numbers found: %d\n", count);
    printf("Thank you for using the Prime Number Generator!\n");
    printf("===========================================\n");
}