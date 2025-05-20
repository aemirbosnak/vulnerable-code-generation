//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    if (num <= 3) {
        return true;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }
    
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate prime numbers up to a limit
void generate_primes(int limit) {
    if (limit < 2) {
        printf("There are no prime numbers less than %d.\n", limit);
        return;
    }
    
    printf("Prime numbers up to %d are:\n", limit);
    
    // Special case for 2, the only even prime
    if (limit >= 2) {
        printf("2\n");
    }
    
    for (int num = 3; num <= limit; num += 2) {
        if (is_prime(num)) {
            printf("%d\n", num);
        }
    }
}

// Function to get user input with error-checking
int get_user_input() {
    int input;
    while (true) {
        printf("Enter the limit up to which you want to generate prime numbers: ");
        if (scanf("%d", &input) == 1 && input >= 0) {
            // Clear the input buffer
            while(getchar() != '\n');
            return input;
        }
        else {
            printf("Invalid input. Please enter a non-negative integer.\n");
            while(getchar() != '\n'); // Clear invalid input
        }
    }
}

// Function to print the menu and handle user choice
void display_menu() {
    int choice;
    
    while (true) {
        printf("\n--- Prime Number Generator ---\n");
        printf("1. Generate prime numbers\n");
        printf("2. Exit\n");
        printf("Choose an option: ");
        
        scanf("%d", &choice);
        
        if (choice == 1) {
            int limit = get_user_input();
            generate_primes(limit);
        } else if (choice == 2) {
            printf("Exiting the program. Thank you!\n");
            exit(0);
        } else {
            printf("Invalid choice. Please select 1 or 2.\n");
        }
    }
}

int main() {
    display_menu();
    return 0;
}