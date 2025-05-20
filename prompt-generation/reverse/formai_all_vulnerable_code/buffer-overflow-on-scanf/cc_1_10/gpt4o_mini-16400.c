//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: real-life
#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int number) {
    if (number <= 1) return false; // Numbers less than or equal to 1 are not prime
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) return false; // Found a divisor, not a prime
    }
    return true; // This number is prime
}

// Function to generate prime numbers up to a specified limit
void generatePrimes(int limit) {
    printf("Chef's Prime Number Special Menu:\n");
    printf("------------------------------------------------\n");
    for (int num = 2; num <= limit; num++) {
        if (isPrime(num)) {
            printf("Serving Prime Number: %d\n", num);
        }
    }
    printf("------------------------------------------------\n");
}

// Function to display the restaurant menu
void displayMenu() {
    printf("Welcome to the Prime Number Restaurant!\n");
    printf("Please select an option from the menu below:\n");
    printf("1. Generate Prime numbers up to a specific limit.\n");
    printf("2. Exit the restaurant.\n");
    printf("------------------------------------------------\n");
}

// Function to take orders from the customer
void takeOrder() {
    int choice, limit;
    while (true) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the upper limit to generate prime numbers: ");
                scanf("%d", &limit);
                if (limit < 2) {
                    printf("Limit must be greater than or equal to 2 to find prime numbers.\n");
                    break;
                }
                generatePrimes(limit);
                break;
            case 2:
                printf("Thank you for dining with us! Have a great day!\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    printf("Welcome to the Prime Number Restaurant!\n");
    takeOrder();
    return 0;
}