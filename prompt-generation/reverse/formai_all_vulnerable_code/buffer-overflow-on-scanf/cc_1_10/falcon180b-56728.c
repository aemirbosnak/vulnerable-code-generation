//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number
int generateRandomNumber() {
    return rand() % 100 + 1;
}

// Function to play the game
void playGame() {
    int userGuess, randomNumber;
    char playAgain = 'y';

    // Seed the random number generator
    srand(time(NULL));

    // Generate a random number
    randomNumber = generateRandomNumber();

    // Prompt the user to enter a guess
    printf("Guess a number between 1 and 100: ");
    scanf("%d", &userGuess);

    while (playAgain == 'y') {
        if (userGuess == randomNumber) {
            printf("Congratulations! You guessed the correct number: %d\n", randomNumber);
            break;
        } else if (userGuess < randomNumber) {
            printf("Too low. Guess again: ");
        } else {
            printf("Too high. Guess again: ");
        }

        scanf("%d", &userGuess);
    }

    if (playAgain == 'y') {
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    }
}

int main() {
    char playAgain = 'y';

    while (playAgain == 'y') {
        playGame();

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    }

    return 0;
}