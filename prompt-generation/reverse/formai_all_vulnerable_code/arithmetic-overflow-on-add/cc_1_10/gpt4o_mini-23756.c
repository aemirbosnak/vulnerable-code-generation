//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to print the prime numbers up to a given limit
void printPrimes(int limit) {
    bool *isPrime = malloc((limit + 1) * sizeof(bool));
    
    if (isPrime == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // Initialize all numbers as prime
    for (int i = 0; i <= limit; i++) {
        isPrime[i] = true;
    }

    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers

    // Sieve of Eratosthenes algorithm
    for (int i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    // Print the prime numbers
    printf("Prime numbers up to %d:\n", limit);
    for (int i = 0; i <= limit; i++) {
        if (isPrime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    free(isPrime);
}

// Function to handle user input and validations
void getUserInput() {
    int limit;
    printf("Enter the upper limit for prime number generation: ");

    // Read user input and validate
    while (true) {
        if (scanf("%d", &limit) != 1 || limit < 2) {
            printf("Invalid input. Please enter a positive integer greater than or equal to 2: ");
            while (getchar() != '\n'); // Clear invalid input
        } else {
            break;
        }
    }

    printPrimes(limit);
}

int main() {
    printf("Welcome to the Prime Number Generator!\n");
    printf("This program will generate all prime numbers up to a specified limit.\n");

    getUserInput();

    printf("Thank you for using the Prime Number Generator. Goodbye!\n");
    return 0;
}