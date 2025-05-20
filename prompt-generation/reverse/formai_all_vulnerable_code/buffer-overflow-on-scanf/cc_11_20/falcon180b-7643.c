//Falcon-180B DATASET v1.0 Category: Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //initialize random number generator
    int choice;
    int playerScore = 0;
    int computerScore = 0;
    char playAgain;

    do {
        printf("Welcome to Rock Paper Scissors!\n");
        printf("Please choose your move:\n");
        printf("1. Rock\n2. Paper\n3. Scissors\n");
        scanf("%d", &choice);

        if (choice < 1 || choice > 3) {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        int computerMove = rand() % 3 + 1; //computer chooses a random move

        if (choice == computerMove) {
            printf("It's a tie!\n");
        } else if ((choice == 1 && computerMove == 3) ||
                   (choice == 2 && computerMove == 1) ||
                   (choice == 3 && computerMove == 2)) {
            printf("You win this round!\n");
            playerScore++;
        } else {
            printf("Computer wins this round!\n");
            computerScore++;
        }

        printf("Score: You - %d, Computer - %d\n", playerScore, computerScore);
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y' || playAgain == 'Y');

    if (playerScore > computerScore) {
        printf("You win the game!\n");
    } else if (computerScore > playerScore) {
        printf("Computer wins the game!\n");
    } else {
        printf("It's a tie game!\n");
    }

    return 0;
}