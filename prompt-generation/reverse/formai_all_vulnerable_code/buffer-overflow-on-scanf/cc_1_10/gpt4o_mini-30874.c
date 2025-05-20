//GPT-4o-mini DATASET v1.0 Category: Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printIntroduction(int maxNumber) {
    printf("Welcome to the Number Guessing Game!\n");
    printf("I have selected a random number between 1 and %d.\n", maxNumber);
    printf("Try to guess the number, and I'll tell you if you're too high, too low, or correct!\n");
}

void playGame(int maxNumber) {
    int numberToGuess = (rand() % maxNumber) + 1;
    int playerGuess = 0;
    int attempts = 0;
    
    while (1) {
        printf("Enter your guess (1 to %d) or 0 to quit: ", maxNumber);
        scanf("%d", &playerGuess);

        if (playerGuess == 0) {
            printf("Thanks for playing! The number was %d.\n", numberToGuess);
            break;
        }
        
        attempts++;
        
        if (playerGuess < 1 || playerGuess > maxNumber) {
            printf("Please guess a number within the valid range!\n");
            continue;
        }

        if (playerGuess < numberToGuess) {
            printf("Too low! Try again.\n");
        } else if (playerGuess > numberToGuess) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number %d in %d attempts!\n", numberToGuess, attempts);
            break;
        }
    }
}

int main() {
    srand(time(NULL));
    int maxNumber = 100;
    char playAgain;

    do {
        printIntroduction(maxNumber);
        playGame(maxNumber);
        
        printf("Would you like to play again? (y/n): ");
        scanf(" %c", &playAgain);
        
    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thank you for playing! Goodbye!\n");
    return 0;
}