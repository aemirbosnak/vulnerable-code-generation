//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h> // For sleep()

void printSurprise() {
    printf("🎉 Surprise! Welcome to the Prime Number Generator! 🎉\n");
    sleep(1);
    printf("Let's find some prime numbers together...\n\n");
}

bool isPrime(int number) {
    if (number <= 1) return false;
    if (number <= 3) return true;

    if (number % 2 == 0 || number % 3 == 0) return false;

    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) return false;
    }
    return true;
}

void generatePrimes(int limit) {
    printf("Generating prime numbers up to %d!\n\n", limit);
    sleep(1);

    printf("+------------------+\n");
    printf("| Prime Numbers    |\n");
    printf("+------------------+\n");
    
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            printf("| %16d |\n", i);
            fflush(stdout); // Ensure it prints out immediately without buffering
            sleep(1);        // Delay to create suspense
        }
    }
    
    printf("+------------------+\n");
    printf("Finished generating primes! 🎈\n");
}

int main() {
    printSurprise();
    
    int limit;
    printf("Enter the upper limit for prime number generation: ");
    scanf("%d", &limit);
    
    if (limit < 2) {
        printf("Limit must be 2 or greater! Please provide a valid number.\n");
        return 1;
    }

    generatePrimes(limit);
    
    return 0;
}