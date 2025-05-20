//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int number) {
    if (number <= 1) return false;
    if (number <= 3) return true;

    if (number % 2 == 0 || number % 3 == 0) return false;

    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) return false;
    }
    return true;
}

// Function to generate prime numbers up to a specified limit
void generate_primes(int limit) {
    printf("Prime numbers up to %d:\n", limit);
    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            printf("%d ", num);
        }
    }
    printf("\n");
}

// Function to get user input with validation
int get_user_input(const char *prompt) {
    int input;
    char buffer[100];
    while (true) {
        printf("%s", prompt);
        fgets(buffer, sizeof(buffer), stdin);
        // Check if the input is valid
        if (sscanf(buffer, "%d", &input) == 1 && input > 0) {
            break;
        } else {
            printf("Invalid input. Please enter a positive integer.\n");
        }
    }
    return input;
}

// Function to provide additional options to the user
void display_options() {
    printf("Options:\n");
    printf("1. Generate prime numbers up to a limit\n");
    printf("2. Exit\n");
}

// Main function to control the flow of the program
int main() {
    int choice, limit;

    while (true) {
        display_options();
        choice = get_user_input("Enter your choice: ");

        if (choice == 1) {
            limit = get_user_input("Enter the upper limit for prime number generation: ");
            generate_primes(limit);
        } else if (choice == 2) {
            printf("Exiting the program.\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}