//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) {
        return 0; // Numbers less than 2 are not prime
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0; // If divisible by any number, it's not prime
        }
    }
    return 1; // Number is prime
}

// Function to generate primes up to a certain limit
void generatePrimes(int limit) {
    if (limit < 2) {
        printf("No prime numbers found.\n");
        return;
    }
    
    printf("Prime numbers up to %d:\n", limit);
    for (int num = 2; num <= limit; num++) {
        if (isPrime(num)) {
            printf("%d ", num);
        }
    }
    printf("\n");
}

// Function to find the next prime number after a given number
int nextPrime(int start) {
    int num = start + 1; // Start checking from the next number
    while (!isPrime(num)) {
        num++; // Increment num until a prime is found
    }
    return num; // Return the next prime number
}

// Function for user interaction and input
void userInteraction() {
    int choice, limit, startNum;

    while (1) {
        printf("\nPrime Number Generator Menu:\n");
        printf("1. Generate primes up to a specific limit\n");
        printf("2. Find the next prime number after a specific number\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the limit: ");
                scanf("%d", &limit);
                generatePrimes(limit);
                break;
            case 2:
                printf("Enter the number to find the next prime after: ");
                scanf("%d", &startNum);
                int next = nextPrime(startNum);
                printf("The next prime number after %d is %d.\n", startNum, next);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0); // Exit the program
                break;
            default:
                printf("Invalid choice. Please enter a valid option (1-3).\n");
        }
    }
}

// Main function
int main() {
    printf("Welcome to the Prime Number Generator!\n");
    userInteraction(); // Start user interaction loop
    return 0;
}