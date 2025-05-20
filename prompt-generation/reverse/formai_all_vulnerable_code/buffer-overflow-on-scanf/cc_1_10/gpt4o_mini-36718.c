//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: satisfied
#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) {
        return false; // 0 and 1 are not prime numbers
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false; // Found a divisor, not a prime
        }
    }
    return true; // No divisors found, it is a prime number
}

// Function to generate and print prime numbers within a range
void generate_primes(int start, int end) {
    printf("Prime numbers between %d and %d are:\n", start, end);
    bool found_prime = false; // Flag to check if at least one prime is found

    for (int num = start; num <= end; num++) {
        if (is_prime(num)) {
            printf("%d ", num);
            found_prime = true; // At least one prime number found
        }
    }

    if (!found_prime) {
        printf("No prime numbers found in the range.\n");
    }
    printf("\n");
}

// Function to get valid user input
int get_user_input(const char* prompt) {
    int input;
    while (true) {
        printf("%s", prompt);
        if (scanf("%d", &input) == 1 && input >= 0) {
            break; // Input is a valid non-negative integer
        } else {
            printf("Invalid input. Please enter a non-negative integer.\n");
            while(getchar() != '\n'); // Clear the input buffer
        }
    }
    return input;
}

int main() {
    // Introduction
    printf("Welcome to the Prime Number Generator!\n");
    printf("This program will display all prime numbers in a given range.\n");
    
    // Get the starting and ending numbers for the range
    int start = get_user_input("Enter the starting number of the range: ");
    int end = get_user_input("Enter the ending number of the range: ");

    // Ensure the starting number is less than or equal to the ending number
    if (start > end) {
        printf("The starting number must be less than or equal to the ending number.\n");
        return 1; // Exit the program with an error
    }

    // Generate and print the prime numbers
    generate_primes(start, end);

    // Conclusion message
    printf("Thank you for using the Prime Number Generator. Goodbye!\n");
    return 0; // Successful program termination
}