//Falcon-180B DATASET v1.0 Category: Table Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // Initialize random seed with current time
    int playerScore = 0, computerScore = 0;
    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        printf("Welcome to the game of Rock Paper Scissors!\n");
        printf("You will be playing against the computer.\n");
        printf("Enter your choice (rock, paper, scissors): ");
        char playerChoice;
        scanf("%c", &playerChoice);

        int computerInt;
        computerInt = rand() % 3;

        if (computerInt == 0) {
            printf("The computer chose rock.\n");
        } else if (computerInt == 1) {
            printf("The computer chose paper.\n");
        } else {
            printf("The computer chose scissors.\n");
        }

        if (playerChoice == 'r' && computerInt == 0) {
            printf("It's a tie!\n");
        } else if (playerChoice == 'p' && computerInt == 1) {
            printf("It's a tie!\n");
        } else if (playerChoice =='s' && computerInt == 2) {
            printf("It's a tie!\n");
        } else if (playerChoice == 'r' && computerInt == 2) {
            printf("You win!\n");
            playerScore++;
        } else if (playerChoice == 'p' && computerInt == 0) {
            printf("You win!\n");
            playerScore++;
        } else if (playerChoice =='s' && computerInt == 1) {
            printf("You win!\n");
            playerScore++;
        } else {
            printf("You lose.\n");
            computerScore++;
        }

        printf("Your score: %d\n", playerScore);
        printf("Computer score: %d\n", computerScore);

        printf("Do you want to play again? (y/n): ");
        scanf("%c", &playAgain);
    }

    return 0;
}