//FormAI DATASET v1.0 Category: Table Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerScore = 0, computerScore = 0, rollDice, turnScore;

    srand(time(NULL));
    printf("=============\n");
    printf("C TABLE GAME\n");
    printf("=============\n");
    printf("\n");

    while ((playerScore < 100) && (computerScore < 100)) {
        printf("Player score: %d\n", playerScore);
        printf("Computer score: %d\n", computerScore);
        printf("\n");
        printf(">>> Player Turn <<<\n");
        printf("\n");

        turnScore = 0;
        do {
            rollDice = rand() % 6 + 1;
            printf("You rolled: %d\n", rollDice);
            if (rollDice == 1) {
                printf("Turn ended.\n");
                printf("\n");
                turnScore = 0;
                break;
            } else {
                turnScore += rollDice;
                printf("Turn score: %d\n", turnScore);
                printf("\n");
                printf("Do you want to roll again? (y/n): ");
                char input[2];
                scanf("%s", input);
                if (input[0] == 'n') {
                    playerScore += turnScore;
                    printf("Turn ended.\n");
                    printf("\n");
                    turnScore = 0;
                    break;
                }
            }
        } while (1);

        printf(">>> Computer Turn <<<\n");
        printf("\n");

        turnScore = 0;
        do {
            rollDice = rand() % 6 + 1;
            printf("Computer rolled: %d\n", rollDice);
            if (rollDice == 1) {
                printf("Turn ended.\n");
                printf("\n");
                turnScore = 0;
                break;
            } else {
                turnScore += rollDice;
                printf("Turn score: %d\n", turnScore);
                printf("\n");
                if (turnScore >= 10) {
                    computerScore += turnScore;
                    printf("Turn ended.\n");
                    printf("\n");
                    turnScore = 0;
                    break;
                }
            }
        } while (1);
    }

    if (playerScore >= 100) {
        printf("You won the game!\n");
    } else {
        printf("Computer won the game!\n");
    }

    return 0;
}