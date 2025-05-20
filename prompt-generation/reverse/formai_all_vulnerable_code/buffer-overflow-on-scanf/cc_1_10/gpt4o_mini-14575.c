//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void find_primes(int limit);
void find_factors(int number);
void generate_fibonacci(int terms);
void display_menu();

int main() {
    int choice, number, limit, terms;

    while (1) {
        display_menu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the limit for prime numbers: ");
                scanf("%d", &limit);
                find_primes(limit);
                break;
            case 2:
                printf("Enter the number to find its factors: ");
                scanf("%d", &number);
                find_factors(number);
                break;
            case 3:
                printf("Enter the number of terms for Fibonacci series: ");
                scanf("%d", &terms);
                generate_fibonacci(terms);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void display_menu() {
    printf("\n--- Math Exercise Menu ---\n");
    printf("1. Find Prime Numbers up to a Limit\n");
    printf("2. Find Factors of a Number\n");
    printf("3. Generate Fibonacci Series\n");
    printf("4. Exit\n");
}

void find_primes(int limit) {
    printf("Prime numbers up to %d are:\n", limit);
    for (int num = 2; num <= limit; num++) {
        int is_prime = 1;
        for (int i = 2; i*i <= num; i++) {
            if (num % i == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            printf("%d ", num);
        }
    }
    printf("\n");
}

void find_factors(int number) {
    printf("Factors of %d are:\n", number);
    for (int i = 1; i <= number; i++) {
        if (number % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void generate_fibonacci(int terms) {
    printf("Fibonacci series with %d terms:\n", terms);
    int a = 0, b = 1, next;
    for (int i = 1; i <= terms; i++) {
        if (i == 1) {
            printf("%d ", a);
            continue;
        }
        if (i == 2) {
            printf("%d ", b);
            continue;
        }
        next = a + b;
        a = b;
        b = next;
        printf("%d ", next);
    }
    printf("\n");
}