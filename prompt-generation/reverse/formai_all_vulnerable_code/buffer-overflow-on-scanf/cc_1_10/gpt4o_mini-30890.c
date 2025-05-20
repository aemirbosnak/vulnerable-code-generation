//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printPrimeNumbers(int limit) {
    printf("Prime numbers up to %d are:\n", limit);
    for (int num = 2; num <= limit; num++) {
        bool isPrime = true;
        
        // Check for factors from 2 to the square root of num
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            printf("%d ", num);
        }
    }
    printf("\n");
}

void generatePrimesInRange(int start, int end) {
    if (start < 2) {
        start = 2;  // No primes less than 2
    }

    printf("Generating prime numbers in the range from %d to %d...\n", start, end);
    for (int num = start; num <= end; num++) {
        bool isPrime = true;

        // Check for factors from 2 to the square root of num
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            printf("%d ", num);
        }
    }
    printf("\n");
}

int main() {
    int choice;
    int limit;
    int start, end;

    while (true) {
        printf("\n** Prime Number Generator **\n");
        printf("1. Generate prime numbers up to a certain limit\n");
        printf("2. Generate prime numbers in a specific range\n");
        printf("3. Exit\n");
        printf("Please enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the limit: ");
                scanf("%d", &limit);
                printPrimeNumbers(limit);
                break;
            case 2:
                printf("Enter the start of the range: ");
                scanf("%d", &start);
                printf("Enter the end of the range: ");
                scanf("%d", &end);
                generatePrimesInRange(start, end);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}