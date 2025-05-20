//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printWelcomeMessage() {
    printf("Welcome to the Prime Number Generator!\n");
    printf("This program will generate all prime numbers up to a specified limit.\n");
}

int getLimitFromUser() {
    int limit;
    while (true) {
        printf("Please enter a positive integer limit: ");
        if (scanf("%d", &limit) != 1 || limit < 2) {
            printf("Invalid input! Please enter a valid positive integer greater than 1.\n");
            while (getchar() != '\n'); // Clear the buffer
        } else {
            break;
        }
    }
    return limit;
}

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void generatePrimes(int limit) {
    printf("Generating prime numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    printWelcomeMessage();

    int limit = getLimitFromUser();
    
    generatePrimes(limit);

    printf("Thank you for using the Prime Number Generator! Goodbye!\n");
    return 0;
}