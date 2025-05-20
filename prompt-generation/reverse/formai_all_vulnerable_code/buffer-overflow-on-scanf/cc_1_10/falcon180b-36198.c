//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a dice
int rollDice() {
    return rand() % 6 + 1;
}

// Function to display the result of the roll
void displayResult(int result) {
    if (result == 1) {
        printf("You rolled a 1!\n");
    } else if (result == 2) {
        printf("You rolled a 2!\n");
    } else if (result == 3) {
        printf("You rolled a 3!\n");
    } else if (result == 4) {
        printf("You rolled a 4!\n");
    } else if (result == 5) {
        printf("You rolled a 5!\n");
    } else {
        printf("You rolled a 6!\n");
    }
}

// Function to play the game
void playGame() {
    int playerScore = 0;
    int computerScore = 0;
    char playAgain;

    do {
        // Roll dice for player and computer
        int playerRoll = rollDice();
        int computerRoll = rollDice();

        // Display result of the roll
        printf("Player rolled a %d\n", playerRoll);
        printf("Computer rolled a %d\n\n", computerRoll);

        // Determine winner
        if (playerRoll > computerRoll) {
            printf("You win this round!\n");
            playerScore++;
        } else if (computerRoll > playerRoll) {
            printf("Computer wins this round!\n");
            computerScore++;
        } else {
            printf("It's a tie!\n");
        }

        // Display scores
        printf("\nPlayer score: %d\n", playerScore);
        printf("Computer score: %d\n\n", computerScore);

        // Ask if player wants to play again
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thanks for playing!\n");
}

int main() {
    srand(time(NULL));
    playGame();
    return 0;
}