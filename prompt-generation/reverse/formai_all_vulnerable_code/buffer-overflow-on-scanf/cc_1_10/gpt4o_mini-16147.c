//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printLine(char character, int times) {
    for (int i = 0; i < times; i++) {
        putchar(character);
    }
    putchar('\n');
}

bool isPrime(int number) {
    if (number <= 1) return false; // 0 and 1 are not prime numbers
    if (number <= 3) return true;  // 2 and 3 are prime numbers
    
    // Eliminate multiples of 2 and 3
    if (number % 2 == 0 || number % 3 == 0) return false;

    // Check for factors from 5 to the square root of number
    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

void generatePrimes(int limit) {
    printf("Generating prime numbers up to %d:\n", limit);
    printLine('-', 50);
    
    for (int i = 0; i <= limit; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    
    putchar('\n');
    printLine('-', 50);
}

int main() {
    int limit;

    printf("Welcome to the Prime Number Generator!\n");
    printLine('=', 50);
    
    printf("Please enter a positive integer as the upper limit: ");
    
    if (scanf("%d", &limit) != 1 || limit < 0) {
        fprintf(stderr, "Invalid input. Please enter a positive integer.\n");
        exit(EXIT_FAILURE);
    }
    
    generatePrimes(limit);
    
    printf("Prime generation complete. Goodbye!\n");
    printLine('=', 50);
    
    return 0;
}