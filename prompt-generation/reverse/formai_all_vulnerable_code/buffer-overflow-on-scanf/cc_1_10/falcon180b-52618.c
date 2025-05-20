//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DICE_NUM 6
#define DICE_SIDES 6

// Function to roll a dice
int rollDice() {
    return rand() % DICE_SIDES + 1;
}

// Function to display the result of a dice roll
void displayDice(int dice) {
    printf("You rolled a %d!\n", dice);
}

// Function to play a game of dice
void playGame() {
    int playerScore = 0, computerScore = 0;
    int playerRoll, computerRoll;
    char playAgain;

    do {
        // Player's turn
        printf("Rolling for player...\n");
        playerRoll = rollDice();
        printf("You rolled a %d!\n", playerRoll);
        playerScore += playerRoll;
        printf("Your score is now %d.\n\n", playerScore);

        // Computer's turn
        printf("Rolling for computer...\n");
        computerRoll = rollDice();
        printf("Computer rolled a %d!\n", computerRoll);
        computerScore += computerRoll;
        printf("Computer's score is now %d.\n\n", computerScore);

        // Determine winner
        if (playerScore > computerScore) {
            printf("You win this round!\n");
        } else if (computerScore > playerScore) {
            printf("Computer wins this round!\n");
        } else {
            printf("It's a tie!\n");
        }

        // Ask if player wants to play again
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to the Dice Game!\n");
    playGame();

    return 0;
}