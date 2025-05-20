//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
void displayMenu();
int getUserInput();
bool isPrime(int number);
void generatePrimes(int limit);
void printPrimes(int* primes, int count);

// Main function
int main() {
    int limit;
    displayMenu();
    limit = getUserInput();
    generatePrimes(limit);
    return 0;
}

// Function to display the main menu
void displayMenu() {
    printf("Welcome to the Prime Number Generator!\n");
    printf("=====================================\n");
    printf("This program generates all prime numbers up to a specified limit.\n");
    printf("=====================================\n");
}

// Function to get user input for the limit
int getUserInput() {
    int limit;
    printf("Enter the upper limit for prime number generation: ");
    if (scanf("%d", &limit) != 1 || limit <= 1) {
        printf("Invalid input! Please enter an integer greater than 1.\n");
        exit(EXIT_FAILURE);
    }
    return limit;
}

// Function to check if a number is prime
bool isPrime(int number) {
    if (number <= 1) return false;
    if (number <= 3) return true;
    if (number % 2 == 0 || number % 3 == 0) return false;
    
    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0)
            return false;
    }
    return true;
}

// Function to generate prime numbers and print them
void generatePrimes(int limit) {
    int* primes = malloc(limit * sizeof(int));
    if (primes == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    int count = 0;

    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            primes[count++] = i;
        }
    }

    printPrimes(primes, count);
    free(primes);
}

// Function to print the prime numbers
void printPrimes(int* primes, int count) {
    printf("Prime numbers up to the specified limit are:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}