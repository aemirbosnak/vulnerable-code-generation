//FormAI DATASET v1.0 Category: Dice Roller ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

bool playerTurn = true; // flag to keep track of whose turn it is
bool gameOn = true; // game is on flag 

// function to roll the dice and return the result
int rollDice() {
    return (rand() % 6) + 1; // generate a random number between 1 to 6
}

// function to handle player turn
void playerChance(char* playerName, int* playerScore, int currentScore) {
    printf("\n%s's turn\n", playerName);

    int diceNum = rollDice(); // roll the dice

    printf("You rolled %d\n", diceNum);

    if (diceNum == 1) {
        printf("You rolled a 1, turn over\n");
        currentScore = 0;
        playerTurn = !playerTurn; // change turn to other player
    }
    else {
        currentScore += diceNum; // add the dice result to current score
        printf("Your current score is %d\n", *playerScore + currentScore);

        char choice;
        printf("Do you want to hold or roll again [h/r]: ");
        scanf(" %c", &choice);

        if (choice == 'h') {
            *playerScore += currentScore; // add the current score to main score
            printf("Your score is now %d\n", *playerScore);
            playerTurn = !playerTurn; // change turn to other player
        }
        else {
            playerChance(playerName, playerScore, currentScore); // call the function recursively
        }
    }
}

// main function
int main() {
    srand(time(NULL)); // seed the random number generator with system time

    int player1Score = 0, player2Score = 0, currentScore = 0;

    printf("Welcome to Dice Roller Game\n");
    printf("===========================\n");

    while (gameOn) {
        if (playerTurn) {
            playerChance("Player 1", &player1Score, currentScore); // player 1 turn
        }
        else {
            playerChance("Player 2", &player2Score, currentScore); // player 2 turn
        }

        // check if any player crosses winning score of 100
        if (player1Score >= 100) {
            printf("Player 1 wins!!\n");
            gameOn = false;
        }
        else if (player2Score >= 100) {
            printf("Player 2 wins!!\n");
            gameOn = false;
        }
    }

    return 0;
}