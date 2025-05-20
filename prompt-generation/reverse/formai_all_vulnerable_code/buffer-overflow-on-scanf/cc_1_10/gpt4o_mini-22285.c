//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) return 0; // Numbers less than 2 are not prime
    if (num <= 3) return 1; // 2 and 3 are prime numbers
    if (num % 2 == 0 || num % 3 == 0) return 0; // Eliminate multiples of 2 and 3

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to print primes in a given range
void print_primes_in_range(int start, int end) {
    printf("Exciting Prime Numbers between %d and %d:\n", start, end);
    int found = 0;

    for (int num = start; num <= end; num++) {
        if (is_prime(num)) {
            printf("%d ", num);
            found = 1;
        }
    }

    if (!found) {
        printf("No prime numbers found in this range!\n");
    }
    printf("\n");
}

// Interactive function to run the prime number generator
void prime_number_generator() {
    int start = 0, end = 0;

    printf("Welcome to the Prime Number Generator!\n");
    printf("Let's find some thrilling prime numbers!\n");

    // Get user input
    printf("Please enter the start of the range: ");
    scanf("%d", &start);
    
    printf("Now, please enter the end of the range: ");
    scanf("%d", &end);

    // Validate the input
    if (end < start) {
        printf("Oops! The end of the range should be greater than or equal to start.\n");
        return;
    }

    // Print prime numbers in the given range
    print_primes_in_range(start, end);
}

int main() {
    prime_number_generator();

    // Adding a loop to allow multiple queries
    char choice;
    do {
        printf("Would you like to find prime numbers in another range? (Y/N): ");
        scanf(" %c", &choice); // The space before %c handles newline

        if (choice == 'Y' || choice == 'y') {
            prime_number_generator();
        } else if (choice == 'N' || choice == 'n') {
            printf("Thank you for using the Prime Number Generator! Goodbye!\n");
        } else {
            printf("Invalid choice. Please enter Y or N.\n");
        }
    } while (choice != 'N' && choice != 'n');

    return 0;
}