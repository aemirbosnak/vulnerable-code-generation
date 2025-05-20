//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototype declarations
void welcomeMessage();
bool isPrime(int number);
void generatePrimes(int limit);
void printPrimesInRange(int start, int end);

// Welcome message function
void welcomeMessage() {
    printf("**********************************\n");
    printf("* Welcome to the Prime Number Generator! *\n");
    printf("**********************************\n");
    printf("Let's find some prime numbers together! \n\n");
}

// Function to check if a number is prime
bool isPrime(int number) {
    if (number < 2) {
        return false; // 0 and 1 are not prime numbers
    }
    
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false; // Found a divisor, not prime
        }
    }
    return true; // No divisors found, it's prime!
}

// Function to generate primes up to a given limit
void generatePrimes(int limit) {
    printf("Generating prime numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\nHappy Prime Number Hunting!\n");
}

// Function to print primes in a specific range
void printPrimesInRange(int start, int end) {
    if (start < 2) {
        start = 2; // Start from the first prime number
    }
    
    printf("Generating prime numbers between %d and %d:\n", start, end);
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\nAwesome, we found some primes in that range!\n");
}

// Main function
int main() {
    welcomeMessage();

    int option;
    do {
        printf("\nSelect an option:\n");
        printf("1. Generate primes up to a limit\n");
        printf("2. Generate primes within a range\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &option);
        
        switch (option) {
            case 1: {
                int limit;
                printf("Enter the limit: ");
                scanf("%d", &limit);
                generatePrimes(limit);
                break;
            }
            case 2: {
                int start, end;
                printf("Enter the start of the range: ");
                scanf("%d", &start);
                printf("Enter the end of the range: ");
                scanf("%d", &end);
                printPrimesInRange(start, end);
                break;
            }
            case 3:
                printf("Thank you for using the Prime Number Generator! Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please select 1, 2, or 3.\n");
        }
    } while (option != 3);

    return 0;
}