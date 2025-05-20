//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void displayMenu();
int getLimitFromUser();
bool isPrime(int number);
void generatePrimes(int limit);
void printPrimes(int* primes, int count);

int main() {
    displayMenu();
    int limit = getLimitFromUser();
    generatePrimes(limit);
    return 0;
}

void displayMenu() {
    printf("Welcome to the Prime Number Generator!\n");
    printf("This program will generate prime numbers up to a specified limit.\n");
    printf("Please follow the instructions to continue.\n\n");
}

int getLimitFromUser() {
    int limit;
    printf("Enter the upper limit to generate prime numbers: ");
    while (scanf("%d", &limit) != 1 || limit < 2) {
        printf("Invalid input. Please enter an integer greater than 1: ");
        while (getchar() != '\n'); // clear the input buffer
    }
    return limit;
}

bool isPrime(int number) {
    if (number <= 1) return false;
    if (number <= 3) return true;

    if (number % 2 == 0 || number % 3 == 0) return false;

    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

void generatePrimes(int limit) {
    int* primes = (int*)malloc(sizeof(int) * limit);
    if (primes == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    int count = 0;
    for (int num = 2; num < limit; num++) {
        if (isPrime(num)) {
            primes[count++] = num;
        }
    }

    printPrimes(primes, count);
    free(primes);
}

void printPrimes(int* primes, int count) {
    printf("Prime numbers up to the specified limit are:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}