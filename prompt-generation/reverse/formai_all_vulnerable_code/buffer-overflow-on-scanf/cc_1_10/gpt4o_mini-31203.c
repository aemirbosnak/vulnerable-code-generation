//GPT-4o-mini DATASET v1.0 Category: Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROUNDS 10
#define MAX_NUM 100

void printInstructions() {
    printf("Welcome to the Number Guessing Game!\n");
    printf("Try to guess the random number between 1 and %d.\n", MAX_NUM);
    printf("You have %d rounds to guess the number correctly.\n", MAX_ROUNDS);
    printf("If you guess the number incorrectly, you'll get a hint.\n");
    printf("Let's see how many attempts it takes you to guess the number!\n");
    printf("Good luck!\n");
}

int getRandomNumber() {
    return (rand() % MAX_NUM) + 1; // Generate a number between 1 and MAX_NUM
}

void playRound(int round) {
    int numberToGuess = getRandomNumber();
    int guess = 0;
    int attempts = 0;
    int gameWon = 0;

    printf("\nRound %d: Guess the number!\n", round + 1);

    while (attempts < 5 && !gameWon) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess < 1 || guess > MAX_NUM) {
            printf("Invalid input! Please guess a number between 1 and %d.\n", MAX_NUM);
            attempts--; // Do not count invalid input as an attempt
            continue;
        }

        if (guess == numberToGuess) {
            printf("Congratulations! You've guessed the number %d correctly in %d attempts!\n", numberToGuess, attempts);
            gameWon = 1; // The player has guessed correctly
        } else {
            if (guess < numberToGuess) {
                printf("Too low! Try again.\n");
            } else {
                printf("Too high! Try again.\n");
            }
            if (attempts < 5) {
                printf("You have %d attempts left.\n", 5 - attempts);
            } else {
                printf("You've used all your attempts! The correct number was %d.\n", numberToGuess);
            }
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    printInstructions();
    
    for (int round = 0; round < MAX_ROUNDS; round++) {
        playRound(round);
    }

    printf("Thank you for playing the Number Guessing Game! Goodbye!\n");
    
    return 0;
}