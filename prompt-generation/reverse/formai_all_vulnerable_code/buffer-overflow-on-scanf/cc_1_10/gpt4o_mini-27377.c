//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) 
        return false;
    if (num <= 3) 
        return true;
    if (num % 2 == 0 || num % 3 == 0) 
        return false;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) 
            return false;
    }
    return true;
}

// Function to generate prime numbers up to a specified limit
void generate_primes(int limit) {
    if (limit < 2) {
        printf("There are no prime numbers less than %d\n", limit);
        return;
    }

    // Allocate memory to store primes
    int* primes = malloc(limit * sizeof(int));
    int count = 0;

    printf("Prime numbers up to %d:\n", limit);
    for (int i = 2; i < limit; i++) {
        if (is_prime(i)) {
            primes[count++] = i;
            printf("%d ", i);
        }
    }
    printf("\nTotal primes found: %d\n", count);

    // Free allocated memory
    free(primes);
}

// Function to display a menu
void display_menu() {
    printf("Welcome to the Prime Number Generator!\n");
    printf("1. Generate primes up to a certain limit\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

// Function to get user input
int get_user_input() {
    int input;
    while (scanf("%d", &input) != 1) {
        printf("Invalid input. Please enter a valid number: ");
        while (getchar() != '\n'); // clear the input buffer
    }
    return input;
}

int main() {
    int option;
    int limit;

    do {
        display_menu();
        option = get_user_input();

        switch (option) {
            case 1:
                printf("Enter the limit for prime number generation: ");
                limit = get_user_input();
                generate_primes(limit);
                break;

            case 2:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 2);

    return 0;
}