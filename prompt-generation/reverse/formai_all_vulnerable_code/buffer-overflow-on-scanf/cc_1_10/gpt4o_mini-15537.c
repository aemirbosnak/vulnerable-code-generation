//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int is_prime(int num);
void generate_primes(int limit);
void display_menu();
void get_user_input(int *limit);

int main() {
    // Variables for user input
    int limit;

    // Display the menu to the user
    display_menu();
    get_user_input(&limit);

    // Generate and display prime numbers up to the user-defined limit
    printf("Generating prime numbers up to %d:\n", limit);
    generate_primes(limit);

    return 0;
}

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) {
        return 0; // not prime
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; // not prime
        }
    }
    return 1; // prime
}

// Function to generate and display prime numbers up to a certain limit
void generate_primes(int limit) {
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Function to display a simple menu
void display_menu() {
    printf("====================================\n");
    printf("       Prime Number Generator       \n");
    printf("====================================\n");
    printf("This program generates all prime numbers up to a specified limit.\n");
    printf("Please enter a positive integer limit.\n");
}

// Function to get user input for the limit
void get_user_input(int *limit) {
    while (1) {
        printf("Enter a positive integer: ");
        scanf("%d", limit);

        if (*limit > 0) {
            break; // valid input
        } else {
            printf("Invalid input! Please enter a positive integer.\n");
        }
    }
}