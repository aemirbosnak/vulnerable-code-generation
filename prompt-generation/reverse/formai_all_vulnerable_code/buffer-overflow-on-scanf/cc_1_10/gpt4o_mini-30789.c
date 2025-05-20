//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void displayMenu() {
    printf("\n-----------------------------------------\n");
    printf("         Prime Number Generator         \n");
    printf("-----------------------------------------\n");
    printf("1. Generate Primes up to a Limit\n");
    printf("2. Exit\n");
    printf("-----------------------------------------\n");
    printf("Please choose an option: ");
}

int isPrime(int number) {
    if (number <= 1) {
        return 0;
    }
    if (number <= 3) {
        return 1;
    }
    if (number % 2 == 0 || number % 3 == 0) {
        return 0;
    }
    for (int i = 5; i <= sqrt(number); i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return 0;
        }
    }
    return 1;
}

void generatePrimes(int limit) {
    if (limit < 2) {
        printf("There are no prime numbers below %d.\n", limit);
        return;
    }

    printf("\nPrime numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int choice, limit;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the limit up to which you want to generate prime numbers: ");
                scanf("%d", &limit);
                generatePrimes(limit);
                break;
            case 2:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}