//Falcon-180B DATASET v1.0 Category: Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int playerScore = 0;
    int computerScore = 0;
    int choice;
    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        printf("Welcome to the game!\n");
        printf("You will play against the computer.\n");
        printf("Choose an option:\n");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");

        scanf("%d", &choice);

        int computerChoice = rand() % 3;

        if (choice == computerChoice) {
            printf("It's a tie!\n");
        } else if ((choice == 1 && computerChoice == 2) ||
                   (choice == 2 && computerChoice == 1) ||
                   (choice == 3 && computerChoice == 2) ||
                   (choice == 2 && computerChoice == 3)) {
            printf("You win!\n");
            playerScore++;
        } else {
            printf("You lose!\n");
            computerScore++;
        }

        printf("Score: You - %d, Computer - %d\n", playerScore, computerScore);
        printf("Play again? (y/n): ");
        scanf(" %c", &playAgain);
    }

    if (playerScore > computerScore) {
        printf("Congratulations! You won the game.\n");
    } else if (computerScore > playerScore) {
        printf("Sorry, you lost the game.\n");
    } else {
        printf("It's a tie game.\n");
    }

    return 0;
}