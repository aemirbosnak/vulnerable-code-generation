//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerScore = 0; // initialize the player's score to 0
    int computerScore = 0; // initialize the computer's score to 0
    int playerChoice; // initialize the player's choice
    srand(time(NULL)); // set the seed for the random number generator with the current time

    printf("Welcome to the Rock-Paper-Scissors game! You will be playing against the computer.\n");

    while (1) { // keep playing until the player wants to quit
        printf("Enter 1 for Rock, 2 for Paper, 3 for Scissors, or 0 to quit: ");
        scanf("%d", &playerChoice);

        if (playerChoice == 0) {
            break; // player wants to quit, so exit the game loop
        } else if (playerChoice < 1 || playerChoice > 3) {
            printf("Invalid input. Please enter 1, 2, 3, or 0.\n");
            continue; // continue the game loop without updating the scores
        }

        int computerChoice = rand() % 3 + 1; // computer randomly chooses between 1, 2, and 3

        printf("You chose ");
        switch (playerChoice) {
            case 1:
                printf("Rock.\n");
                break;
            case 2:
                printf("Paper.\n");
                break;
            case 3:
                printf("Scissors.\n");
                break;
        }

        printf("The computer chose ");
        switch (computerChoice) {
            case 1:
                printf("Rock.\n");
                break;
            case 2:
                printf("Paper.\n");
                break;
            case 3:
                printf("Scissors.\n");
                break;
        }

        if (playerChoice == computerChoice) {
            printf("It's a tie!\n");
        } else if ((playerChoice == 1 && computerChoice == 3) || (playerChoice == 2 && computerChoice == 1) || (playerChoice == 3 && computerChoice == 2)) {
            printf("You won!\n");
            playerScore++; // update the player's score
        } else {
            printf("The computer won!\n");
            computerScore++; // update the computer's score
        }

        printf("Score: You %d, Computer %d.\n", playerScore, computerScore);
    }

    printf("Thanks for playing! Final score: You %d, Computer %d.\n", playerScore, computerScore);

    return 0;
}