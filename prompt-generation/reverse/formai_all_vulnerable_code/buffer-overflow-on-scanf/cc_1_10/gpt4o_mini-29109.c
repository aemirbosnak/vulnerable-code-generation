//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function declaration
void printPrimes(int limit);
bool isPrime(int number);

int main() {
    int limit;

    // Welcome message
    printf("Welcome to the Prime Number Generator!\n");
    printf("Let's discover some prime numbers together!\n");

    // Getting user input
    printf("Enter the upper limit to find prime numbers: ");
    scanf("%d", &limit);

    // Input validation
    while (limit <= 1) {
        printf("Please enter a positive integer greater than 1: ");
        scanf("%d", &limit);
    }

    printf("Generating prime numbers up to %d...\n", limit);
    printPrimes(limit);

    printf("Prime number generation completed! Keep exploring the wonders of numbers!\n");
    return 0;
}

// Function to print all prime numbers up to the limit
void printPrimes(int limit) {
    printf("Prime numbers are:\n");
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Function to check if a number is prime
bool isPrime(int number) {
    if (number <= 1) return false; // 0 and 1 are not prime numbers
    if (number <= 3) return true; // 2 and 3 are prime numbers

    // Check divisibility by 2 and 3
    if (number % 2 == 0 || number % 3 == 0) return false;

    // Check for factors up to the square root of the number
    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) return false;
    }
    return true;
}