//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

void displayIntro() {
    printf("******************************************\n");
    printf("*         Welcome to the Prime          *\n");
    printf("*         Number Generator Program      *\n");
    printf("******************************************\n");
}

void displayInstructions() {
    printf("Instructions:\n");
    printf("1. Enter the upper limit up to which prime numbers will be generated.\n");
    printf("2. The program will then display all the prime numbers up to that limit.\n");
    printf("3. Enjoy the magic of prime numbers!\n");
}

int isPrime(int number) {
    if (number <= 1) return 0;
    if (number <= 3) return 1;

    if (number % 2 == 0 || number % 3 == 0) return 0;

    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return 0;
        }
    }
    return 1;
}

void generatePrimes(int limit) {
    printf("Generating prime numbers up to %d...\n", limit);
    printf("Prime Numbers: ");
    
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    
    printf("\n");
}

void displayGoodbye() {
    printf("******************************************\n");
    printf("*            Thank you for using        *\n");
    printf("*      the Prime Number Generator!       *\n");
    printf("******************************************\n");
}

int main() {
    int upperLimit;

    displayIntro();
    displayInstructions();

    printf("Enter the upper limit for prime generation: ");
    
    while (scanf("%d", &upperLimit) != 1 || upperLimit < 1) {
        printf("Invalid input. Please enter a positive integer: ");
        while(getchar() != '\n'); // Clear invalid input
    }

    generatePrimes(upperLimit);
    displayGoodbye();

    return 0;
}