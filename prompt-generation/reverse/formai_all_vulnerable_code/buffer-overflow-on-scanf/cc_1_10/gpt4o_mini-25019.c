//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
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

// Function to generate and print prime numbers within a range
void generate_primes(int start, int end) {
    printf("Generating prime numbers between %d and %d:\n", start, end);
    for (int num = start; num <= end; num++) {
        if (is_prime(num)) {
            printf("%d ", num);
        }
    }
    printf("\nDone!\n");
}

// Function to get user input
void get_user_input(int *start, int *end) {
    printf("Enter the start of the range: ");
    scanf("%d", start);
    printf("Enter the end of the range: ");
    scanf("%d", end);
    if (*start > *end) {
        printf("Invalid range! The start must be less than or equal to the end.\n");
        exit(1);
    }
}

int main() {
    int start, end;

    printf("Welcome to the Prime Number Generator!\n");
    
    // Get user input for the range
    get_user_input(&start, &end);

    // Generate primes in the specified range
    generate_primes(start, end);

    // Ask user if they want to generate more primes
    char choice;
    do {
        printf("Would you like to generate primes for another range? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y') {
            get_user_input(&start, &end);
            generate_primes(start, end);
        }
    } while (choice == 'y');

    printf("Thank you for using the Prime Number Generator. Goodbye!\n");

    return 0;
}