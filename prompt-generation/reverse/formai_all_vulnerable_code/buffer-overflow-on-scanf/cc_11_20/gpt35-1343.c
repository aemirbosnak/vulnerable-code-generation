//FormAI DATASET v1.0 Category: Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerScore = 0;
    int computerScore = 0;

    srand(time(NULL));

    while (playerScore < 100 && computerScore < 100) {
        // Player's turn
        printf("Your turn to roll the dice! Press enter to continue.");
        getchar();
        int playerRoll = rand() % 6 + 1;
        printf("You rolled a %d.\n", playerRoll);
        if (playerRoll == 1) {
            printf("You rolled a 1! Your turn is over.\n");
        } else {
            playerScore += playerRoll;
            printf("Your score is now %d.\n", playerScore);
            if (playerScore >= 100) {
                break;
            }
            printf("Do you want to roll again? (y/n) ");
            char choice;
            scanf(" %c", &choice);
            if (choice == 'n') {
                printf("Your turn is over.\n");
            } else if (choice == 'y') {
                continue;
            }
        }

        // Computer's turn
        printf("Computer's turn to roll the dice! Press enter to continue.");
        getchar();
        int computerRoll = rand() % 6 + 1;
        printf("Computer rolled a %d.\n", computerRoll);
        if (computerRoll == 1) {
            printf("Computer rolled a 1! Computer's turn is over.\n");
        } else {
            computerScore += computerRoll;
            printf("Computer's score is now %d.\n", computerScore);
            if (computerScore >= 100) {
                break;
            }
            if (computerScore >= playerScore + 25) {
                printf("Computer ends its turn.\n");
            } else {
                continue;
            }
        }
    }

    if (playerScore >= 100) {
        printf("Congratulations! You won with a score of %d.\n", playerScore);
    } else if (computerScore >= 100) {
        printf("Sorry, the computer won with a score of %d.\n", computerScore);
    }

    return 0;
}