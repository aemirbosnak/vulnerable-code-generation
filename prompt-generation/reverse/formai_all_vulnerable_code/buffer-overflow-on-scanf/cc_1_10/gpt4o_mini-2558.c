//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: excited
#include <stdio.h>
#include <stdbool.h>

void printWelcomeMessage() {
    printf("***************************************\n");
    printf("   Welcome to the Prime Number Generator!\n");
    printf("***************************************\n");
    printf("Get ready to embark on a thrilling journey to discover prime numbers!\n");
}

bool isPrime(int number) {
    if (number <= 1) return false; // 1 and below are not prime
    if (number <= 3) return true;  // 2 and 3 are prime numbers

    // Eliminate multiples of 2 and 3
    if (number % 2 == 0 || number % 3 == 0) return false;

    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return false;  // Number is divisible, hence not prime
        }
    }
    return true; // Number is prime!
}

void generatePrimes(int limit) {
    printf("\nGenerating prime numbers up to %d:\n", limit);
    printf("*****************************************\n");
    
    for (int num = 2; num <= limit; num++) {
        if (isPrime(num)) {
            printf("🚀 Prime Found: %d!\n", num);
        }
    }

    printf("*****************************************\n");
    printf("All prime numbers up to %d have been generated! 🎉\n", limit);
}

int main() {
    printWelcomeMessage();

    int upperLimit;
    printf("\nEnter the upper limit to find prime numbers: ");
    scanf("%d", &upperLimit);

    if (upperLimit < 2) {
        printf("Oops! The limit must be at least 2 to generate primes. 😢\n");
        return 1; // Exit the program with an error code
    }

    generatePrimes(upperLimit);
    
    printf("\nThank you for using the Prime Number Generator! 🌟\n");
    printf("Keep exploring the amazing world of numbers!\n");

    return 0; // Successfully completed
}