//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    srand(time(NULL));

    int tableSize = 7;
    int playerScore = 0;
    int computerScore = 0;

    int playerGuess;
    int computerGuess;

    printf("Welcome to the C Table Game!\n");
    printf("The game is played between two players, you and the computer.\n");
    printf("Each player will choose a number from 1 to %d, the computer will\n", tableSize);
    printf("choose a number from 1 to %d.\n", tableSize);
    printf("You will have to guess the computer's number.\n");
    printf("If you guess correctly, you will win a point.\n");
    printf("If the computer guesses correctly, it will win a point.\n");
    printf("The game will continue until one of the players has %d points.\n", tableSize);

    while (playerScore < tableSize && computerScore < tableSize) {
        printf("Player: Choose a number between 1 and %d: ", tableSize);
        scanf("%d", &playerGuess);

        printf("Computer: Choose a number between 1 and %d: ", tableSize);
        computerGuess = rand() % tableSize + 1;

        printf("Player's guess: %d\n", playerGuess);
        printf("Computer's guess: %d\n", computerGuess);

        if (playerGuess == computerGuess) {
            printf("It's a tie!\n");
        } else if (playerGuess > computerGuess) {
            printf("Computer wins!\n");
            computerScore++;
        } else {
            printf("Player wins!\n");
            playerScore++;
        }

        printf("Player's score: %d\n", playerScore);
        printf("Computer's score: %d\n", computerScore);

        printf("\n");
    }

    if (playerScore == tableSize) {
        printf("Player wins!\n");
    } else if (computerScore == tableSize) {
        printf("Computer wins!\n");
    } else {
        printf("Game ended in a draw.\n");
    }

    return 0;
}