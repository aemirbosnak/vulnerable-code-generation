//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
long long factorial(int n);
bool is_prime(int n);
void fibonacci(int n);
void print_menu();
void handle_choice(int choice);

int main() {
    int choice;

    while (1) {
        print_menu();
        printf("Enter your choice (1-5, or 0 to exit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        } else {
            handle_choice(choice);
        }
    }

    return 0;
}

// Function to print the menu
void print_menu() {
    printf("\nMath Operations Menu:\n");
    printf("1. Calculate Factorial\n");
    printf("2. Check if a number is Prime\n");
    printf("3. Generate Fibonacci Series\n");
    printf("4. Exit\n");
    printf("Please select an operation:\n");
}

// Function to handle the user's choice
void handle_choice(int choice) {
    int number;

    switch (choice) {
        case 1:
            printf("Enter a non-negative integer for factorial: ");
            scanf("%d", &number);
            if (number < 0) {
                printf("Factorial is not defined for negative numbers.\n");
            } else {
                printf("Factorial of %d is %lld\n", number, factorial(number));
            }
            break;

        case 2:
            printf("Enter a number to check if it is prime: ");
            scanf("%d", &number);
            if (is_prime(number)) {
                printf("%d is a prime number.\n", number);
            } else {
                printf("%d is not a prime number.\n", number);
            }
            break;

        case 3:
            printf("Enter the number of Fibonacci terms to generate: ");
            scanf("%d", &number);
            if (number < 0) {
                printf("Please enter a non-negative integer.\n");
            } else {
                printf("Fibonacci Series:\n");
                fibonacci(number);
            }
            break;

        default:
            printf("Invalid choice! Please try again.\n");
            break;
    }
}

// Function to calculate factorial of n
long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Function to check if n is prime
bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Function to generate Fibonacci series
void fibonacci(int n) {
    long long a = 0, b = 1, c;
    for (int i = 0; i < n; i++) {
        printf("%lld ", a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
}