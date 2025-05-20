//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int number) {
    if (number <= 1) {
        return false;
    }
    if (number <= 3) {
        return true;
    }
    if (number % 2 == 0 || number % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate prime numbers in a specified range
void generate_primes(int start, int end) {
    printf("Prime numbers between %d and %d:\n", start, end);
    
    // Loop through the range and check for prime numbers
    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Function to get user input with validation
int get_user_input(const char *prompt) {
    int value;
    printf("%s", prompt);
    while (scanf("%d", &value) != 1) {
        scanf("%*s"); // Clear invalid input
        printf("Invalid input. Please enter an integer: ");
    }
    return value;
}

int main() {
    printf("Welcome to the Prime Number Generator!\n");
    printf("This program will help you find prime numbers within a specified range.\n");

    // Get the start and end range from the user
    int start = get_user_input("Enter the starting number of the range: ");
    int end = get_user_input("Enter the ending number of the range: ");

    // Basic validation to ensure start is less than or equal to end
    if (start > end) {
        printf("Invalid range! The starting number should be less than or equal to the ending number.\n");
        return 1;
    }

    // Generate and display prime numbers for the specified range
    generate_primes(start, end);

    printf("Thank you for using the Prime Number Generator! Goodbye!\n");
    return 0;
}