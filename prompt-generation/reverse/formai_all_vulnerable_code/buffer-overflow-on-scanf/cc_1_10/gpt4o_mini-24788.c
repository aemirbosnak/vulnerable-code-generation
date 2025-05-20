//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

void clearBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}

bool isPrime(int num) {
    if (num <= 1)
        return false;
    if (num <= 3)
        return true;
    if (num % 2 == 0 || num % 3 == 0)
        return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}

void generatePrimes(int limit) {
    for (int num = 2; num <= limit; num++) {
        if (isPrime(num)) {
            printf("%d ", num);
        }
    }
    printf("\n");
}

void generateNPrimes(int n) {
    int count = 0;
    int num = 2; // Starting from the first prime
    while (count < n) {
        if (isPrime(num)) {
            printf("%d ", num);
            count++;
        }
        num++;
    }
    printf("\n");
}

void displayMenu() {
    printf("Prime Number Generator\n");
    printf("======================\n");
    printf("1. Generate primes up to a certain number\n");
    printf("2. Generate the first N primes\n");
    printf("3. Exit\n");
    printf("======================\n");
    printf("Choose an option: ");
}

int getPositiveInteger() {
    int num;
    while (true) {
        printf("Enter a positive integer: ");
        if (scanf("%d", &num) != 1 || num <= 0) {
            printf("Invalid input. Please try again.\n");
            clearBuffer(); // Clear any wrong input
        } else {
            clearBuffer(); // Clear the newline character
            return num;
        }
    }
}

int main() {
    int option;
    
    while (1) {
        displayMenu();
        scanf("%d", &option);
        clearBuffer(); // Clear the newline character

        switch (option) {
            case 1: {
                int limit = getPositiveInteger();
                printf("Primes up to %d:\n", limit);
                generatePrimes(limit);
                break;
            }
            case 2: {
                int n = getPositiveInteger();
                printf("The first %d primes:\n", n);
                generateNPrimes(n);
                break;
            }
            case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}