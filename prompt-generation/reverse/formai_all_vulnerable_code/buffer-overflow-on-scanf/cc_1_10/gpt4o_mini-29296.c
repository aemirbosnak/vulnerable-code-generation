//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int num) {
    if (num <= 1) {
        return 0; // Numbers less than or equal to 1 are not prime.
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0; // Found a divisor, so it's not prime.
        }
    }
    return 1; // It's a prime number.
}

void generate_primes(int limit) {
    printf("Generating prime numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void menu() {
    printf("------------------------------------------------\n");
    printf("          Prime Number Generator Menu           \n");
    printf("------------------------------------------------\n");
    printf("1. Generate primes up to a certain number\n");
    printf("2. Exit\n");
    printf("------------------------------------------------\n");
    printf("Please enter your choice: ");
}

int main() {
    int choice, limit;

    do {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the upper limit: ");
                scanf("%d", &limit);
                if (limit < 0) {
                    printf("Please enter a positive integer.\n");
                } else {
                    generate_primes(limit);
                }
                break;
            case 2:
                printf("Thank you for using the Prime Number Generator. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}