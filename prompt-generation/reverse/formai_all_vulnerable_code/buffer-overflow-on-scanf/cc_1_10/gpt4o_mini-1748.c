//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void greetUser() {
    printf("Welcome to the Prime Number Generator!\n");
    printf("This program will help you find all the prime numbers up to a specified limit.\n");
}

bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

void findPrimes(int limit) {
    printf("Generating prime numbers up to: %d\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void menu() {
    printf("\n----- Prime Number Generator Menu -----\n");
    printf("1. Generate primes up to a limit\n");
    printf("2. Exit\n");
    printf("---------------------------------------\n");
}

int main() {
    int choice;
    int limit;

    greetUser();

    while (true) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the limit for prime number generation: ");
            scanf("%d", &limit);
            if (limit < 0) {
                printf("Please enter a positive integer.\n");
                continue;
            }
            findPrimes(limit);
        } else if (choice == 2) {
            printf("Thank you for using the Prime Number Generator. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}