//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void printBanner() {
    printf("=====================================\n");
    printf("    Sherlock Holmes' Prime Number    \n");
    printf("           Generator Program         \n");
    printf("=====================================\n");
    printf("        By: Your Imaginative Name     \n");
    printf("=====================================\n\n");
}

bool isPrime(int number) {
    if (number <= 1) return false;
    if (number <= 3) return true;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

void generatePrimes(int limit) {
    printf("Assemble your wits, dear Watson! We shall uncover prime numbers up to %d.\n", limit);
    printf("Here are the findings of our mathematical investigation:\n");

    for (int num = 2; num <= limit; num++) {
        if (isPrime(num)) {
            printf("%d is a prime number!\n", num);
        }
    }
}

int main() {
    int limit;

    printBanner();

    printf("Watson, I need your assistance.\n");
    printf("Please enter the upper limit for our prime number investigation: ");
    scanf("%d", &limit);

    if (limit < 2) {
        printf("Alas! There are no prime numbers below 2, I fear.\n");
        return 1;
    }

    generatePrimes(limit);

    printf("\nThe investigation is over, Watson. Until we meet again!\n");

    return 0;
}