//Falcon-180B DATASET v1.0 Category: Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int playerScore = 0;
int computerScore = 0;
int choice;
int computerChoice;
int numRounds = 0;

void playRound() {
    int playerChoice;
    int computerChoice;

    // Player's turn
    printf("Round %d\n", ++numRounds);
    printf("Choose rock, paper or scissors: ");
    scanf("%d", &playerChoice);

    // Computer's turn
    srand(time(NULL));
    computerChoice = rand() % 3;

    if (computerChoice == 0) {
        printf("Computer chose rock.\n");
    } else if (computerChoice == 1) {
        printf("Computer chose paper.\n");
    } else {
        printf("Computer chose scissors.\n");
    }

    // Determine winner
    if (playerChoice == computerChoice) {
        printf("It's a tie!\n");
    } else if ((playerChoice == 0 && computerChoice == 2) ||
               (playerChoice == 1 && computerChoice == 0) ||
               (playerChoice == 2 && computerChoice == 1)) {
        printf("You win!\n");
        playerScore++;
    } else {
        printf("You lose.\n");
        computerScore++;
    }
}

int main() {
    printf("Welcome to Rock Paper Scissors!\n");
    printf("You will play against the computer.\n");
    printf("Press 1 to start the game or 0 to quit: ");
    scanf("%d", &choice);

    if (choice == 1) {
        while (playerScore!= 5 && computerScore!= 5 && numRounds!= 10) {
            playRound();
        }

        if (playerScore == 5) {
            printf("You win the game!\n");
        } else if (computerScore == 5) {
            printf("You lose the game.\n");
        } else {
            printf("It's a tie.\n");
        }
    } else {
        printf("Thanks for playing!\n");
    }

    return 0;
}