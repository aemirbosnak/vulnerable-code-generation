//FormAI DATASET v1.0 Category: Table Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// A struct to define a player
typedef struct {
    char name[20];
    int totalScore;
    int currentScore;
} Player;

// Global variables
Player player1, player2;
int currentTurn = 1;
int dice[6] = {1, 2, 3, 4, 5, 6};

// Function to roll the dice and return a random number between 1 and 6
int rollDice() {
    int randomIndex = rand() % 6;
    return dice[randomIndex];
}

// Function to update the score of the current player and check if they won the game
int updateScore(int score) {
    if (currentTurn == 1) {
        player1.currentScore += score;
        if (player1.currentScore == 21) {
            player1.totalScore++;
            printf("%s won the game!\n", player1.name);
            return 1;
        }
    } else {
        player2.currentScore += score;
        if (player2.currentScore == 21) {
            player2.totalScore++;
            printf("%s won the game!\n", player2.name);
            return 1;
        }
    }
    return 0;
}

// Function to switch the turn to the other player
void switchTurn() {
    if (currentTurn == 1) {
        printf("End of %s's turn\n\n", player1.name);
        currentTurn = 2;
    } else {
        printf("End of %s's turn\n\n", player2.name);
        currentTurn = 1;
    }
}

// Function to start the game
void startGame() {
    printf("Game started!\n\n");
    while (1) {
        printf("%s's turn, press enter to roll the dice\n", currentTurn==1?player1.name:player2.name);
        getchar();
        int score = rollDice();
        printf("You rolled a %d\n", score);
        int won = updateScore(score);
        if (won) {
            break;
        }
        switchTurn();
    }
    printf("Final Score:\n%s:\t%d\n%s:\t%d\n", player1.name, player1.totalScore, player2.name, player2.totalScore);
}

// Main function to get player names and start the game
int main() {
    printf("Welcome to the 21 game!\n\n");
    printf("Enter player 1 name: ");
    scanf("%s", player1.name);
    printf("Enter player 2 name: ");
    scanf("%s", player2.name);

    player1.totalScore = player2.totalScore = player1.currentScore = player2.currentScore = 0;

    srand(time(NULL));
    startGame();

    return 0;
}