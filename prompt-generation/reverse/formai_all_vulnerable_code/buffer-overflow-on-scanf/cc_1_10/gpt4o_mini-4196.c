//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to calculate the factorial of a number
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to generate Fibonacci series up to n terms
void fibonacci(int n) {
    unsigned long long a = 0, b = 1;
    printf("Fibonacci series up to %d terms: ", n);
    for (int i = 1; i <= n; ++i) {
        printf("%llu ", a);
        unsigned long long temp = a + b;
        a = b;
        b = temp;
    }
    printf("\n");
}

// Function to check if a number is prime
bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Function to display prime numbers up to a specified limit
void display_primes(int limit) {
    printf("Prime numbers up to %d: ", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int choice, number, terms, limit;

    printf("Welcome to the Math Utility Program inspired by Ada Lovelace!\n");
    do {
        printf("\nMenu:\n");
        printf("1. Calculate Factorial\n");
        printf("2. Generate Fibonacci Series\n");
        printf("3. Display Prime Numbers\n");
        printf("4. Exit\n");
        printf("Please choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a non-negative integer for factorial calculation: ");
                scanf("%d", &number);
                if (number < 0) {
                    printf("Factorial is not defined for negative numbers.\n");
                } else {
                    printf("Factorial of %d is %llu\n", number, factorial(number));
                }
                break;

            case 2:
                printf("Enter the number of terms for Fibonacci series: ");
                scanf("%d", &terms);
                if (terms < 1) {
                    printf("Please enter a positive integer.\n");
                } else {
                    fibonacci(terms);
                }
                break;

            case 3:
                printf("Enter a limit to display prime numbers: ");
                scanf("%d", &limit);
                if (limit < 2) {
                    printf("There are no prime numbers less than 2.\n");
                } else {
                    display_primes(limit);
                }
                break;

            case 4:
                printf("Exiting the program. Thank you!\n");
                break;

            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}