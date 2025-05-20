//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int playerChoice;
    int computerChoice;
    int playerScore = 0;
    int computerScore = 0;

    printf("------------------------------------------------\n");
    printf("Welcome to Rock Paper Scissors Terminal Game\n");
    printf("------------------------------------------------\n\n");

    printf("Instructions:\n\n");
    printf("1. Enter 1 for Rock, 2 for Paper, or 3 for Scissors.\n");
    printf("2. Rock beats Scissors, Scissors beat Paper, and Paper beats Rock.\n\n");

    //loop for game rounds
    int i;
    for (i = 1; i <= 5; i++) {
        printf("------------------------------------------------\n");
        printf("Round %d: \n", i);

        //player move
        printf("Enter your move (1 = Rock, 2 = Paper, 3 = Scissors): ");
        scanf("%d", &playerChoice);

        //computer move
        srand(time(NULL));
        computerChoice = rand() % 3 + 1;

        //determining winner
        if (playerChoice == 1 && computerChoice == 3) {
            printf("Rock beats Scissors! You win round %d.\n", i);
            playerScore++;
        }
        else if (playerChoice == 2 && computerChoice == 1) {
            printf("Paper beats Rock! You win round %d.\n", i);
            playerScore++;
        }
        else if (playerChoice == 3 && computerChoice == 2) {
            printf("Scissors beats Paper! You win round %d.\n", i);
            playerScore++;
        }
        else if (computerChoice == 1 && playerChoice == 3) {
            printf("Rock beats Scissors! Computer wins round %d.\n", i);
            computerScore++;
        }
        else if (computerChoice == 2 && playerChoice == 1) {
            printf("Paper beats Rock! Computer wins round %d.\n", i);
            computerScore++;
        }
        else if (computerChoice == 3 && playerChoice == 2) {
            printf("Scissors beats Paper! Computer wins round %d.\n", i);
            computerScore++;
        }
        else {
            printf("It's a tie! No one wins round %d.\n", i);
        }

        //display current score
        printf("Current Score: You %d - %d Computer\n", playerScore, computerScore);
    }

    //determining the game winner
    printf("\n------------------------------------------------\n");
    if (playerScore > computerScore) {
        printf("Congratulations! You win the game. Final Score: You %d - %d Computer\n", playerScore, computerScore);
    }
    else if (computerScore > playerScore) {
        printf("Sorry, you lost the game. Final Score: You %d - %d Computer\n", playerScore, computerScore);
    }
    else {
        printf("It's a tie! Final Score: You %d - %d Computer\n", playerScore, computerScore);
    }

    return 0;
}