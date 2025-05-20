//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 10
int randNum() {
    srand(time(NULL));
    return (rand() % 10) + 1;
}

// Function to initialize the game and handle the player's guesses
void playGame() {
    int numGuesses = 5;
    int guess;

    printf("Welcome to the Guessing Game!\n");
    printf("I have chosen a number between 1 and 10. Try to guess it!\n");

    // Generate a random number for the player to guess
    int num = randNum();

    // Ask the player to make a guess
    do {
        printf("Guess: ");
        scanf("%d", &guess);

        // Check if the guess is correct
        if (guess == num) {
            printf("You guessed correctly!\n");
            break;
        }

        // Tell the player how many guesses they have left
        if (numGuesses > 0) {
            printf("Sorry, that's not right. You have %d guess(s) left.\n", numGuesses);
        }

        // Reduce the number of guesses left
        numGuesses--;
    } while (numGuesses > 0);

    // If the player ran out of guesses
    if (numGuesses == 0) {
        printf("Sorry, you ran out of guesses. The correct answer was %d.\n", num);
    }
}

// Function to start the game
int main() {
    playGame();
    return 0;
}