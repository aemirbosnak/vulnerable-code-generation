//FormAI DATASET v1.0 Category: Table Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random number between 1 and 6
int rollDice() {
    return (rand() % 6) + 1;
}

int main() {
    srand(time(0)); // seeding the random number generator with current time

    int players[2] = {0}; // array to keep track of each player's score
    int currentPlayer = 0; // variable to keep track of current player turn

    printf("Welcome to the C Table Game!\n");

    // loop until one of the players reaches a score of 100 or more
    while (players[0] < 100 && players[1] < 100) {

        int roll = rollDice();
        printf("Player %d rolled a %d\n", currentPlayer+1, roll);

        // if player rolls a 1, they lose their turn and their score is reset to 0
        if (roll == 1) {
            printf("Player %d rolled a 1 and loses their turn\n", currentPlayer+1);
            players[currentPlayer] = 0;
            currentPlayer = (currentPlayer + 1) % 2; // switch to the other player
        }
        else {
            players[currentPlayer] += roll; // add the roll to the player's score
            printf("Player %d's current score is %d\n", currentPlayer+1, players[currentPlayer]);

            // if player's score reaches 100 or more, they win
            if (players[currentPlayer] >= 100) {
                printf("Player %d wins!\n", currentPlayer+1);
                break;
            }

            // give the player the option to roll again or hold
            printf("Would you like to (1) roll again or (2) hold? ");
            int choice;
            scanf("%d", &choice);

            if (choice == 1) {
                continue; // continue the loop to the next iteration, allowing player to roll again
            }
            else {
                currentPlayer = (currentPlayer + 1) % 2; // switch to the other player
            }
        }
    }

    return 0;
}