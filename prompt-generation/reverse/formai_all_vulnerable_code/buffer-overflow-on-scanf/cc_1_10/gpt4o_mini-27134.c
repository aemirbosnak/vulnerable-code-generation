//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to check if a number is prime.
int isPrime(int number) {
    if (number <= 1) return 0; // 0 and 1 are not prime numbers
    if (number <= 3) return 1; // 2 and 3 are prime numbers
    if (number % 2 == 0 || number % 3 == 0) return 0; // Exclude multiples of 2 and 3

    // Check for prime through 6k ± 1 optimization
    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) return 0;
    }
    return 1;
}

// Function to generate a list of prime numbers up to a specified limit.
void generatePrimes(int limit) {
    printf("Generating prime numbers up to %d:\n", limit);
    for (int number = 2; number <= limit; number++) {
        if (isPrime(number)) {
            printf("%d ", number);
        }
    }
    printf("\n");
}

// Function to read input from the user in a robust manner.
int getUserInput() {
    int number;
    printf("Enter a positive integer limit for prime generation: ");
    
    // Check for valid integer input
    while (scanf("%d", &number) != 1 || number < 1) {
        printf("Invalid input. Please enter a positive integer: ");
        while(getchar() != '\n'); // clear input buffer
    }
    return number;
}

// Structure to hold the user request
typedef struct {
    int limit;
} PrimeRequest;

// Function to display a menu and get the user choice
int displayMenu() {
    int choice;
    printf("\n--- Prime Number Generator Menu ---\n");
    printf("1. Generate primes\n");
    printf("2. Exit\n");
    
    // Validate menu input
    printf("Choose an option: ");
    while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
        printf("Invalid option. Please choose again: ");
        while(getchar() != '\n'); // clear input buffer
    }
    return choice;
}

// Main function to drive the program
int main() {
    PrimeRequest request;
    int userChoice;

    do {
        userChoice = displayMenu();
        switch (userChoice) {
            case 1:
                request.limit = getUserInput();
                generatePrimes(request.limit);
                break;
            case 2:
                printf("Exiting the program. Thank you for using the Prime Number Generator.\n");
                break;
        }
    } while (userChoice != 2);

    return 0;
}