//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
bool isPrime(int num);
void generatePrimes(int limit);
void printPrimeCount(int count);

// Main function to drive the program
int main() {
    int upperLimit;
    char choice;

    printf("🎉 Welcome to the Prime Number Generator! 🎉\n");
    printf("Let's unveil the magic of prime numbers together!\n");

    while (1) {
        printf("\nPlease enter the upper limit up to which you want to find prime numbers: ");
        scanf("%d", &upperLimit);

        if (upperLimit < 2) {
            printf("Oops! The limit should be greater than 1. Try again!\n");
            continue;
        }

        printf("\n✨ Generating prime numbers up to %d... ✨\n", upperLimit);
        generatePrimes(upperLimit);

        printf("\nWould you like to generate primes up to another limit? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') {
            printf("Thank you for using the Prime Number Generator! Goodbye! 👋\n");
            break;
        }
    }

    return 0;
}

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false; // 1 and 0 are not prime numbers
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false; // Found a divisor, not a prime
        }
    }
    return true; // No divisors found, it's a prime
}

// Function to generate and print all primes up to a given limit
void generatePrimes(int limit) {
    int primeCount = 0;

    printf("Prime numbers up to %d are: \n", limit);
    for (int num = 2; num <= limit; num++) {
        if (isPrime(num)) {
            printf("%d ", num);
            primeCount++;
        }
    }
    
    printf("\n");
    printPrimeCount(primeCount);
}

// Function to print the count of prime numbers found
void printPrimeCount(int count) {
    printf("Total number of prime numbers found: %d\n", count);
}