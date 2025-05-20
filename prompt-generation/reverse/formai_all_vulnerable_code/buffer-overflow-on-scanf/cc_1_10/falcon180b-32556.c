//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h> // for tolower()

// function to roll a dice
int rollDice() {
    int dice = rand() % 6 + 1; // generate a random number between 1 and 6
    return dice; // return the value of the dice
}

// function to play the game
void playGame() {
    int playerScore = 0; // initialize player score to 0
    int computerScore = 0; // initialize computer score to 0
    char playAgain = 'y'; // initialize playAgain to 'y' to start the game

    // play until the user decides to quit
    while (tolower(playAgain) == 'y') {
        // roll dice for player and computer
        int playerDice = rollDice();
        int computerDice = rollDice();

        // display the result of the roll
        printf("Player rolled: %d\n", playerDice);
        printf("Computer rolled: %d\n", computerDice);

        // determine the winner
        if (playerDice > computerDice) {
            printf("Player wins!\n");
            playerScore++;
        } else if (computerDice > playerDice) {
            printf("Computer wins!\n");
            computerScore++;
        } else {
            printf("It's a tie!\n");
        }

        // ask if the user wants to play again
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    }

    // display the final scores
    printf("\nFinal scores:\n");
    printf("Player: %d\n", playerScore);
    printf("Computer: %d\n", computerScore);
}

// main function
int main() {
    srand(time(NULL)); // seed the random number generator with the current time
    playGame(); // play the game
    return 0;
}