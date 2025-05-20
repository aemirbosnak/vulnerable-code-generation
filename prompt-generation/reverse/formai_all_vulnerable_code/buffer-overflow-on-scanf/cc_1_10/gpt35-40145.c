//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare the function prototypes
int selectDifficulty();
void playGame(int difficulty);

int main() {
    printf("Welcome to the Happy Guessing Game!\n");
    printf("---------------------------------\n\n");

    srand(time(0)); // Set the random seed

    int difficulty = selectDifficulty(); // Allow the user to select the difficulty

    playGame(difficulty); // Play the game

    printf("\nYou won the game! Congrats!\n");

    return 0;
}

// Function to select the difficulty level
int selectDifficulty() {
    int difficulty;
    printf("Please select the difficulty level (1-3):\n");
    scanf("%d", &difficulty);

    // Validate the user's input
    while (difficulty < 1 || difficulty > 3) {
        printf("Invalid input. Please select the difficulty level (1-3):\n");
        scanf("%d", &difficulty);
    }

    return difficulty;
}

// Function to play the game with the specified difficulty level
void playGame(int difficulty) {
    printf("\nLet's start the game with difficulty level %d!\n\n", difficulty);

    int maxNumber, numberOfGuesses;
    switch(difficulty) {
        case 1:
            maxNumber = 10;
            numberOfGuesses = 3;
            break;
        case 2:
            maxNumber = 20;
            numberOfGuesses = 5;
            break;
        case 3:
            maxNumber = 30;
            numberOfGuesses = 7;
            break;
    }

    int randomNumber = rand() % maxNumber + 1;

    int guess;
    int guessesLeft = numberOfGuesses;

    // Allow the user to guess until they run out of guesses or guess the correct number
    while(guessesLeft > 0) {
        printf("You have %d guesses left.\n", guessesLeft);
        printf("Guess a number between 1 and %d:\n", maxNumber);
        scanf("%d", &guess);

        if(guess == randomNumber) {
            printf("Congratulations! You guessed the correct number!\n");
            return;
        }
        else if(guess > randomNumber) {
            printf("Sorry, your guess is too high. ");
        }
        else if(guess < randomNumber) {
            printf("Sorry, your guess is too low. ");
        }

        printf("Please try again.\n\n");
        --guessesLeft;
    }

    printf("\nSorry, you ran out of guesses. The correct number was %d.\n", randomNumber);
}