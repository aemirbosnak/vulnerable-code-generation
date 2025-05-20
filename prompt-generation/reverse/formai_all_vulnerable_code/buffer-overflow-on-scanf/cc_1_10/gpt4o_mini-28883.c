//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

#define MAX_NUMBER 10000
#define SCREEN_WIDTH 80

void glowingText(const char *text) {
    printf("\033[1;32m%s\033[0m", text); // Bright green text
}

void printWelcome() {
    printf("\n");
    glowingText("==============================================\n");
    glowingText("         CYBERPUNK PRIME NUMBER GENERATOR     \n");
    glowingText("==============================================\n");
    printf(" In a city where tech meets treachery,\n");
    printf(" your mission is to uncover the hidden primes.\n\n");
}

void delay(int seconds) {
    for (int i = 0; i < seconds; i++) {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    printf("\n\n");
}

int isPrime(int num) {
    if (num <= 1) return 0;
    if (num <= 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;
    
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }
    return 1;
}

void generatePrimes(int limit) {
    printf("Searching through rows of data in the neon alleys...\n");
    printf("Digging out primes from shadows...\n");
    delay(3);
    
    printf("Prime numbers found:\n");
    for (int i = 2; i < limit; i++) {
        if (isPrime(i)) {
            printf("\033[1;34m - \033[0m%d\n", i); // Bright blue primes
        }
    }
}

void clearScreen() {
    printf("\033[H\033[J"); // Terminal command to clear screen
}

void displayExit() {
    glowingText("==============================================\n");
    glowingText("    THANK YOU FOR USING THE PRIME GENERATOR   \n");
    glowingText("==============================================\n");
}

int main() {
    int limit;

    clearScreen();
    printWelcome();
    
    printf("Enter a limit for the prime number generator (up to %d): ", MAX_NUMBER);
    scanf("%d", &limit);
    
    if (limit > MAX_NUMBER) {
        printf("Limit exceeded! Please enter a number less than %d.\n", MAX_NUMBER);
        return 1;
    }

    generatePrimes(limit);
    
    displayExit();
    return 0;
}