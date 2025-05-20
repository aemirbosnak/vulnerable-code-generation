//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Function to determine if a number is prime
int is_prime(int num) {
    if (num <= 1) return 0;  // Numbers less than 2 are not prime
    if (num <= 3) return 1;  // 2 and 3 are prime numbers

    // Check for even numbers and multiples of 3
    if (num % 2 == 0 || num % 3 == 0) return 0;

    // Start checking from 5 and test every sixth number (5, 11, 17, ...)
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }
    return 1;  // If no factors found, it's prime
}

// Function to generate prime numbers up to a specified limit
void generate_primes(int limit) {
    printf("Generating prime numbers up to: %d\n", limit);
    printf("Prime numbers are:\n");

    // Loop through all numbers from 2 to 'limit'
    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            printf("%d ", num);  // Print the prime number
        }
    }
    printf("\n");
}

// Function to interactively ask for a limit and generate primes
void interactive_prime_generator() {
    int limit;

    // Request user input for the limit
    printf("Enter a positive integer as the upper limit for prime generation: ");
    while (1) {
        int check = scanf("%d", &limit);
        // Ensure the input is valid
        if (check != 1 || limit < 2) {
            printf("Please enter a valid integer greater than or equal to 2: ");
            while (getchar() != '\n');  // Clear the input buffer
        } else {
            break;  // Valid input received
        }
    }

    // Generate and display prime numbers up to the specified limit
    generate_primes(limit);
}

// Menu for the user to select an option
void print_menu() {
    printf("\n--- Prime Number Generator Menu ---\n");
    printf("1. Generate primes up to a limit\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
}

// Main function to orchestrate the program
int main() {
    int choice;

    // Keep running the program until the user decides to exit
    do {
        print_menu();
        scanf("%d", &choice);  // Get user's choice

        switch (choice) {
            case 1:  // Generate primes option
                interactive_prime_generator();
                break;

            case 2:  // Exit option
                printf("Exiting the program. Have a nice day!\n");
                break;

            default:  // Invalid choice
                printf("Invalid choice. Please select 1 or 2.\n");
                break;
        }
    } while (choice != 2);

    return 0;  // End of the program
}