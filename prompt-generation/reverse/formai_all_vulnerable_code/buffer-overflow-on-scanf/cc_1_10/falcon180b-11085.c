//Falcon-180B DATASET v1.0 Category: Educational ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerScore = 0, computerScore = 0, choice;
    char playAgain;

    srand(time(NULL));

    do {
        printf("Welcome to the Retro Rock-Paper-Scissors Game!\n");
        printf("Please choose your move:\n");
        printf("1. Rock\n2. Paper\n3. Scissors\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You chose Rock.\n");
                if (rand() % 2 == 0) {
                    printf("Computer chose Scissors.\n");
                    computerScore++;
                } else {
                    printf("Computer chose Paper.\n");
                    playerScore++;
                }
                break;
            case 2:
                printf("You chose Paper.\n");
                if (rand() % 2 == 0) {
                    printf("Computer chose Rock.\n");
                    computerScore++;
                } else {
                    printf("Computer chose Scissors.\n");
                    playerScore++;
                }
                break;
            case 3:
                printf("You chose Scissors.\n");
                if (rand() % 2 == 0) {
                    printf("Computer chose Rock.\n");
                    computerScore++;
                } else {
                    printf("Computer chose Paper.\n");
                    playerScore++;
                }
                break;
            default:
                printf("Invalid move. Please try again.\n");
        }

        printf("\nScore: You - %d, Computer - %d\n", playerScore, computerScore);

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}