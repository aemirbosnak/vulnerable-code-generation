//Falcon-180B DATASET v1.0 Category: Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerScore = 0, computerScore = 0;
    int choice;
    char playAgain = 'y';

    srand(time(NULL));

    while (playAgain == 'y' || playAgain == 'Y') {
        printf("Welcome to the game of Rock, Paper, Scissors!\n");
        printf("You will play against the computer.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 3) {
            printf("Invalid choice. Please enter a number between 1 and 3.\n");
            continue;
        }

        int computerChoice = rand() % 3 + 1;

        if (choice == computerChoice) {
            printf("It's a tie!\n");
        } else if ((choice == 1 && computerChoice == 2) ||
                   (choice == 2 && computerChoice == 1) ||
                   (choice == 3 && computerChoice == 2)) {
            printf("You win!\n");
            playerScore++;
        } else {
            printf("You lose!\n");
            computerScore++;
        }

        printf("Score: You - %d, Computer - %d\n", playerScore, computerScore);
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    }

    if (playerScore > computerScore) {
        printf("Congratulations! You won the game!\n");
    } else if (computerScore > playerScore) {
        printf("Sorry, you lost the game.\n");
    } else {
        printf("It's a tie game!\n");
    }

    return 0;
}