//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A quirky function to test if a number is prime
bool is_prime(int number) {
    if (number <= 1) {
        return false; // Numbers less than 2 are not primes
    }
    for (int i = 2; i * i <= number; i++) { // Testing only till the square root
        if (number % i == 0) { // Check for divisibility
            return false; // We found a divisor, not a prime
        }
    }
    return true; // The number is prime if we found no divisors
}

// A whimsical function to print prime numbers within a given range
void print_primes_in_range(int start, int end) {
    printf("✨🔍 Seeking Prime Numbers Between %d and %d... 🔍✨\n", start, end);

    // Prepare to embark on this prime number voyage!
    bool found_any_prime = false;
    for (int current = start; current <= end; current++) {
        if (is_prime(current)) {
            printf("🌟 Found a prime! It's %d 🌟\n", current);
            found_any_prime = true;
        }
    }

    if (!found_any_prime) {
        printf("💔 Alas! No prime numbers were found in the realm between %d and %d! 💔\n", start, end);
    } else {
        printf("🎉 Huzzah! The cosmic dance of primes continues! 🎉\n");
    }
}

// A function to display menu and capture user choices
void display_menu() {
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("🌌 Welcome to the Prime Number Generator! 🌌\n");
    printf("1. Generate prime numbers in a specific range\n");
    printf("2. Exit the enigmatic realm\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Please enter your choice (1 or 2): ");
}

// The grand finale, the main function
int main() {
    int choice;
    int start, end;

    do {
        display_menu(); // Present the options to the user
        scanf("%d", &choice); // Gather the user's choice

        // If the user wishes to embark on a journey of primes
        if (choice == 1) {
            printf("🔔 Let’s start our journey! Enter the start of the range: ");
            scanf("%d", &start);
            printf("🔔 Now, enter the end of the range: ");
            scanf("%d", &end);

            // Ensure a valid range
            if (start > end) {
                printf("⚠️ Oops! The start must be less than or equal to the end! Please try again. ⚠️\n");
            } else {
                print_primes_in_range(start, end); // Prime searching begins here
            }

        } else if (choice == 2) {
            printf("🔮 Until we meet again in the land of numbers! Goodbye! 🔮\n");
        } else {
            printf("❌ Invalid choice, my friend! Try again! ❌\n");
        }

    } while (choice != 2); // Continue until the user decides to exit

    return 0; // The grand exit
}