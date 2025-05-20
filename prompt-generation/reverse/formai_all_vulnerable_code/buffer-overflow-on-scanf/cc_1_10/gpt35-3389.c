//FormAI DATASET v1.0 Category: Table Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll the dice
int rollDice() {
    return rand() % 6 + 1;
}

int main() {
    // Initializing variables
    int player1Score = 0, player2Score = 0, round = 1, player1Turn = 1, numRolls = 0, choice;
    char playerName[20];

    // Initializing random number generator
    srand(time(NULL));

    // Getting player names
    printf("Welcome to the Table Game! \n\n");
    printf("Player 1, please enter your name: ");
    scanf("%s", playerName);

    printf("Player 2, please enter your name: ");
    scanf("%s", playerName);

    // Starting the game
    printf("\n\nLet's start the game! \n\n");

    while(round <= 6) { // 6 rounds in total
        printf("Round %d \n", round);

        while(numRolls < 3) { // 3 rolls per turn
            printf("It's %s's turn. Press 1 to roll the dice or 2 to hold: ", player1Turn ? "Player 1" : "Player 2");
            scanf("%d", &choice);

            if(choice == 1) { // If player chooses to roll the dice
                int roll = rollDice();
                numRolls++;

                if(roll == 1) { // If player rolls a one
                    printf("%s rolled a 1. Turn over. \n\n", player1Turn ? "Player 1" : "Player 2");
                    break;
                } else { // If player rolls a number other than one
                    printf("%s rolled a %d. \n", player1Turn ? "Player 1" : "Player 2", roll);
                    player1Turn ? (player1Score += roll) : (player2Score += roll);
                    printf("Score: Player 1 - %d, Player 2 - %d\n\n", player1Score, player2Score);
                }
            } else if(choice == 2) { // If player chooses to hold
                printf("%s holds. \n\n", player1Turn ? "Player 1" : "Player 2");
                player1Turn ? (player1Turn = 0) : (player1Turn = 1); // Switching player turns
                numRolls = 0;
                break;
            } else {
                printf("Invalid input. Please try again. \n\n");
            }
        }

        player1Turn ? (player1Turn = 0) : (player1Turn = 1); // Switching player turns
        numRolls = 0;
        round++;
    }

    // Determining the winner
    if(player1Score > player2Score) {
        printf("Congratulations %s, you win! \n", playerName);
    } else if(player2Score > player1Score) {
        printf("Congratulations %s, you win! \n", playerName);
    } else {
        printf("It's a tie! \n");
    }

    return 0;
}