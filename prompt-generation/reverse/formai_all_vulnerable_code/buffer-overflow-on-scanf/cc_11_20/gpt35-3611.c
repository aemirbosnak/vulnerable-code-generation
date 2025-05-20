//FormAI DATASET v1.0 Category: Table Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerScore = 0;
    int computerScore = 0;
    int turnScore = 0;
    char choice = ' ';
    srand(time(NULL));

    printf("Welcome to the Dice Game!\n\n");

    do {
        printf("Your score: %d   Computer score: %d   Turn score: %d\n", playerScore, computerScore, turnScore);
        printf("Roll or hold? (r/h) ");
        scanf(" %c", &choice);
        if (choice == 'r') {
            int roll = (rand() % 6) + 1;
            printf("You rolled a %d!\n", roll);
            if (roll == 1) {
                printf("Bummer! You rolled a 1 and your turn is over.\n\n");
                turnScore = 0;
                continue;
            }
            turnScore += roll;
        }
        else if (choice == 'h') {
            playerScore += turnScore;
            printf("You held!\n\n");
            turnScore = 0;
            if (playerScore >= 100) {
                printf("You win!\n\n");
                break;
            }
            int computerTurn = 1;
            while (computerTurn == 1) {
                printf("The computer is rolling...\n");
                int computerRoll = (rand() % 6) + 1;
                printf("The computer rolled a %d!\n", computerRoll);
                if (computerRoll == 1) {
                    printf("The computer rolled a 1 and its turn is over.\n\n");
                    computerScore += turnScore;
                    turnScore = 0;
                    computerTurn = 0;
                    continue;
                }
                if (computerScore + turnScore + computerRoll >= 100) {
                    printf("The computer wins!\n\n");
                    computerScore += turnScore + computerRoll;
                    turnScore = 0;
                    computerTurn = 0;
                    break;
                }
                if ((computerScore + turnScore + computerRoll) % 10 == 0) {
                    printf("The computer decides to hold!\n\n");
                    computerScore += turnScore + computerRoll;
                    turnScore = 0;
                    computerTurn = 0;
                    break;
                }
                turnScore += computerRoll;
                printf("The computer decides to roll again...\n");
            }
        }
    } while (playerScore < 100 && computerScore < 100);

    return 0;
}