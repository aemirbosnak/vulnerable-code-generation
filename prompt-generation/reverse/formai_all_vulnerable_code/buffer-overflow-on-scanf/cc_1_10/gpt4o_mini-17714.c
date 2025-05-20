//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) return 0; // 0 and 1 are not prime numbers
    if (num <= 3) return 1; // 2 and 3 are prime numbers

    // Check for factors from 5 to the square root of num
    for (int i = 5; i <= sqrt(num); i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) 
            return 0; // not prime
    }
    return 1; // num is prime
}

// Function to generate prime numbers up to a specified limit
void generatePrimes(int limit) {
    if (limit < 2) {
        printf("There are no prime numbers less than 2.\n");
        return;
    }

    printf("Generating prime numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Function to handle user input
void handleInput() {
    int limit;

    printf("Welcome to the Grateful Prime Number Generator!\n");
    printf("Please enter a positive integer as the upper limit for prime generation:\n");
    
    // Taking user input
    while (1) {
        printf("Enter limit: ");
        if (scanf("%d", &limit) == 1 && limit > 0) {
            break; // Valid input received
        } else {
            printf("Invalid input. Please enter a positive integer.\n");
            while (getchar() != '\n'); // Clear the input buffer
        }
    }

    generatePrimes(limit);
}

// Function to display credits
void displayCredits() {
    printf("\nThank you for using the Grateful Prime Number Generator!\n");
    printf("Created with care and gratitude by [Your Name].\n");
    printf("This program is designed to assist in generating prime numbers and educate on prime number properties.\n");
    printf("We appreciate your support in using this tool. Happy coding!\n");
}

int main() {
    // Call the input handling function to start the program
    handleInput();
    
    // Display credits at the end
    displayCredits();
    
    return 0;
}