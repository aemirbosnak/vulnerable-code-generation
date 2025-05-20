//Falcon-180B DATASET v1.0 Category: Educational ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers
int randnum(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print a retro-style banner
void banner(char* msg) {
    int i, j;
    for (i = 0; i < 80; i++) {
        printf("\n");
    }
    for (i = 0; i < 20; i++) {
        printf("*");
    }
    printf("\n");
    printf("* %s *\n", msg);
    for (i = 0; i < 20; i++) {
        printf("*");
    }
    printf("\n");
}

// Main function
int main() {
    int num1, num2, guess, attempts = 0;
    srand(time(NULL));

    // Generate random numbers
    num1 = randnum(1, 100);
    num2 = randnum(1, 100);

    // Print retro-style banner
    banner("GUESS THE NUMBER!");

    // Game loop
    while (1) {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);
        attempts++;

        // Check if the guess is correct
        if (guess == num1 || guess == num2) {
            printf("\nCongratulations! You guessed the number in %d attempts.\n", attempts);
            break;
        }

        // Check if the guess is too high or too low
        if (guess < num1 && guess < num2) {
            printf("\nToo low!\n");
        } else if (guess > num1 && guess > num2) {
            printf("\nToo high!\n");
        }
    }

    return 0;
}