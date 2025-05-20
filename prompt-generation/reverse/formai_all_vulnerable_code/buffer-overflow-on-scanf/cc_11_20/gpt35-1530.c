//FormAI DATASET v1.0 Category: Table Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerScore = 0;
    int computerScore = 0;
    char playerOption = ' ';
    srand(time(NULL));

    printf("Welcome to the ultimate C Table Game!\n");
    printf("You are playing against a computer. Good luck!\n");

    while (playerScore < 5 && computerScore < 5) {
        printf("Current score: Player: %d | Computer: %d\n", playerScore, computerScore);
        printf("Choose your move (Rock [R], Paper [P], Scissors [S]): ");
        scanf(" %c", &playerOption);

        if (playerOption != 'R' && playerOption != 'P' && playerOption != 'S') {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        printf("You chose: %c!\n", playerOption);

        // Computer generates random option
        int computerOptionIndex = rand() % 3; 
        char computerOption;

        if (computerOptionIndex == 0) {
            computerOption = 'R';
            printf("Computer chose: ROCK!\n");
        } else if (computerOptionIndex == 1) {
            computerOption = 'P';
            printf("Computer chose: PAPER!\n");
        } else {
            computerOption = 'S';
            printf("Computer chose: SCISSORS!\n");
        }

        // Determines who wins
        if (playerOption == computerOption) {
            printf("It's a tie! No points awarded.\n");
        } else if (playerOption == 'R' && computerOption == 'S' ||
                   playerOption == 'P' && computerOption == 'R' ||
                   playerOption == 'S' && computerOption == 'P') {
            printf("Congratulations, you won this round!\n");
            playerScore++;
        } else {
            printf("Sorry, you lost this round.\n");
            computerScore++;
        }
    }

    // Determines final winner
    if (playerScore > computerScore) {
        printf("Congratulations! You won the game with a final score of %d to %d!\n", playerScore, computerScore);
    } else {
        printf("Sorry, the computer won the game with a final score of %d to %d. Better luck next time!\n", computerScore, playerScore);
    }

    return 0;
}