//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: intelligent
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void printWelcomeMessage() {
    printf("Welcome to the Prime Number Generator!\n");
    printf("This program will generate prime numbers up to a given limit.\n");
}

bool isPrime(int number) {
    if (number < 2) return false;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

void generatePrimes(int limit) {
    printf("Generating prime numbers up to %d:\n", limit);
    for (int num = 2; num <= limit; num++) {
        if (isPrime(num)) {
            printf("%d ", num);
        }
    }
    printf("\n");
}

void displayMenu() {
    printf("Menu:\n");
    printf("1. Generate primes up to a limit\n");
    printf("2. Exit\n");
}

int getUserChoice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int getLimitFromUser() {
    int limit;
    printf("Enter the limit for generating prime numbers: ");
    scanf("%d", &limit);
    return limit;
}

void handleUserChoice(int choice) {
    switch (choice) {
        case 1: {
            int limit = getLimitFromUser();
            generatePrimes(limit);
            break;
        }
        case 2:
            printf("Thank you for using the Prime Number Generator. Goodbye!\n");
            exit(0);
            break;
        default:
            printf("Invalid choice! Please try again.\n");
    }
}

int main() {
    printWelcomeMessage();

    while (true) {
        displayMenu();
        int choice = getUserChoice();
        handleUserChoice(choice);
    }

    return 0;
}