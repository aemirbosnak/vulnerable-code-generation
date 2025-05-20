//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void sieveOfEratosthenes(int limit) {
    bool *isPrime = (bool *)malloc((limit + 1) * sizeof(bool));
    if (isPrime == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i <= limit; i++) {
        isPrime[i] = true;  // Initialize all numbers as prime
    }
    isPrime[0] = isPrime[1] = false;  // 0 and 1 are not prime

    for (int p = 2; p * p <= limit; p++) {
        if (isPrime[p]) {
            for (int multiple = p * p; multiple <= limit; multiple += p) {
                isPrime[multiple] = false;  // Set the non-prime numbers
            }
        }
    }

    printf("Prime numbers up to %d are:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    free(isPrime);  // Release allocated memory
}

int main() {
    int choice, limit;

    printf("Welcome to the Prime Number Generator!\n");
    printf("Choose an option:\n");
    printf("1. Generate prime numbers up to a specific limit\n");
    printf("2. Exit\n");

    while (1) {
        printf("Enter your choice (1 or 2): ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear invalid input
            continue;
        }
        
        switch (choice) {
            case 1:
                printf("Enter the upper limit for prime numbers: ");
                if (scanf("%d", &limit) != 1 || limit < 2) {
                    fprintf(stderr, "Please enter a valid limit (must be >= 2).\n");
                    while (getchar() != '\n'); // Clear invalid input
                    continue;
                }
                sieveOfEratosthenes(limit);
                break;
            case 2:
                printf("Exiting the program. Goodbye!\n");
                exit(EXIT_SUCCESS);
            default:
                fprintf(stderr, "Invalid choice! Please select 1 or 2.\n");
                break;
        }
    }

    return 0;
}