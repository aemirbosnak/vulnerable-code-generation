//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void splashScreen() {
    printf("****************************************\n");
    printf("*           Welcome to the Prime       *\n");
    printf("*            Number Generator!         *\n");
    printf("****************************************\n");
    printf("Are you ready to discover the secrets of prime numbers?\n");
    printf("Let the numbers tickle your curiosity...\n\n");
}

bool isPrime(int num) {
    if (num <= 1) return false; // 0 and 1 are not prime numbers
    if (num == 2) return true;  // 2 is the only even prime number
    if (num % 2 == 0) return false; // exclude all other even numbers

    int sqrtNum = (int)sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2) {
        if (num % i == 0) {
            return false; // if divisible, it’s not prime
        }
    }
    return true; // if not divisible, it’s prime!
}

void generatePrimes(int limit) {
    printf("Generating primes up to %d...\n", limit);
    printf("Here they come! Hold on tight!\n");
    
    for (int num = 2; num <= limit; num++) {
        if (isPrime(num)) {
            printf("✨ Found Prime: %d ✨\n", num);
        }
    }
    printf("Whew! Finished generating primes up to %d!\n", limit);
}

void userPrompt() {
    printf("Enter the limit for prime number generation (e.g. 100): ");
}

int main() {
    int limit;

    splashScreen();

    userPrompt();
    scanf("%d", &limit);
    
    if (limit < 2) {
        printf("Whoa! That's a bit too low! Please enter a number greater than or equal to 2.\n");
        exit(EXIT_FAILURE);
    }

    generatePrimes(limit);
    
    printf("Thank you for using the Prime Number Generator!\n");
    printf("Keep exploring the world of numbers! 📊✨\n");
    
    return 0;
}