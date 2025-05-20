//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: brave
#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i*i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to display a menu for the game
void display_menu() {
    printf("Welcome to the Prime Number Quest!\n");
    printf("Your mission, should you choose to accept it, is to discover prime numbers!\n");
    printf("1. Enter a number to check if it is prime\n");
    printf("2. List prime numbers up to a certain limit\n");
    printf("3. Generate a list of the first N prime numbers\n");
    printf("4. Exit\n");
    printf("Choose an option (1-4): ");
}

// Function to find and print prime numbers up to a limit
void list_primes_up_to(int limit) {
    printf("Prime numbers up to %d are: ", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Function to generate and print the first N prime numbers
void generate_n_primes(int n) {
    int count = 0;
    int number = 2; // Starting point for prime checking
    printf("The first %d prime numbers are: ", n);
    while (count < n) {
        if (is_prime(number)) {
            printf("%d ", number);
            count++;
        }
        number++;
    }
    printf("\n");
}

int main() {
    int choice;
    do {
        display_menu();
        scanf("%d", &choice);

        if (choice == 1) {
            int number;
            printf("Enter a number to check if it is prime: ");
            scanf("%d", &number);
            if (is_prime(number)) {
                printf("%d is a prime number!\n", number);
            } else {
                printf("%d is not a prime number.\n", number);
            }
        } else if (choice == 2) {
            int limit;
            printf("Enter the limit up to which you want prime numbers: ");
            scanf("%d", &limit);
            list_primes_up_to(limit);
        } else if (choice == 3) {
            int n;
            printf("How many prime numbers do you wish to see? ");
            scanf("%d", &n);
            generate_n_primes(n);
        } else if (choice == 4) {
            printf("Exiting the Prime Number Quest... Brave adventurer, farewell!\n");
        } else {
            printf("Invalid choice. Please choose between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}