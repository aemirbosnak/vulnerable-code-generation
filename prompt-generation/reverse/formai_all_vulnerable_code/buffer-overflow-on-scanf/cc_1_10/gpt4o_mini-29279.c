//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printPrimes(int limit);
bool isPrime(int number);
void handleInput();
void printMenu();

int main() {
    printMenu();
    handleInput();
    return 0;
}

void printMenu() {
    printf("=== Prime Number Generator ===\n");
    printf("This program will generate all prime numbers up to a given limit.\n");
    printf("==============================================\n");
}

void handleInput() {
    int limit = 0;

    while (true) {
        printf("Enter the upper limit for prime number generation (greater than 1): ");
        if (scanf("%d", &limit) != 1 || limit <= 1) {
            printf("Invalid input. Please enter an integer greater than 1.\n");
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }
        break;
    }

    printPrimes(limit);
}

void printPrimes(int limit) {
    printf("Prime numbers up to %d are:\n", limit);
    
    for (int num = 2; num <= limit; num++) {
        if (isPrime(num)) {
            printf("%d ", num);
        }
    }
    
    printf("\n");
}

bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }
    if (number <= 3) {
        return true;
    }
    if (number % 2 == 0 || number % 3 == 0) {
        return false;
    }
    
    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return false;
        }
    }
    
    return true;
}