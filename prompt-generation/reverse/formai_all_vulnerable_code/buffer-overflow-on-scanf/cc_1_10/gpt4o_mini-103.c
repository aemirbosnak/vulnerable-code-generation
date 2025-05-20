//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

// Fun function to check the primality of a number
bool is_prime(int number) {
    if (number <= 1) return false; // No primes below 2
    if (number <= 3) return true; // 2 and 3 are primes
    if (number % 2 == 0 || number % 3 == 0) return false;

    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) return false;
    }
    return true;
}

// Cosmic countdown to prime discovery
void cosmic_countdown() {
    printf("==== Cosmic Countdown to Guided Discovery of Prime Numbers ====\n");
    printf("3... 2... 1... \n");
    printf("Here we go! Searching for prime numbers...\n");
}

// This is a puzzle piece that collects every glorious prime found
void collect_primes(int limit) {
    printf("Collecting primes up to %d:\n", limit);
    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            printf("Found a prime: %d\n", num);
        }
    }
}

// The main orchestration of choices and actions
int main() {
    int limit;
    cosmic_countdown();
    
    // A loop that puzzles out the user for input
    while (true) {
        printf("Enter an upper limit to discover primes (or a negative number to exit): ");
        scanf("%d", &limit);
        
        if (limit < 0) {
            printf("Exiting the puzzle. Seek wisdom elsewhere!\n");
            break;
        }
        
        if (limit > MAX) {
            printf("That's a bit too high! Let’s keep it within 0 to %d.\n", MAX);
            continue;
        } else if (limit == 0) {
            printf("Hmm, no numbers to check! Let's try that again.\n");
            continue;
        }

        collect_primes(limit);
        printf("Would you like to try again? (1 for YES, 0 for NO): ");
        int choice;
        scanf("%d", &choice);

        if (choice != 1) {
            printf("A wise choice! Farewell, and may primes be ever in your favor!\n");
            break;
        }
    }
    
    return 0;
}