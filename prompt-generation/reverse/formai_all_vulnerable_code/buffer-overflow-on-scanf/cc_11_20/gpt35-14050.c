//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: active
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int playerScore = 0;
    int computerScore = 0;

    srand(time(NULL));

    printf("Welcome to the Rock, Paper, Scissors game! \n\n");

    while (1) {
        printf("What is your choice? Type 1 for Rock, 2 for Paper, or 3 for Scissors. \n");
        int playerChoice;
        scanf("%d", &playerChoice);

        int computerChoice = rand() % 3 + 1;

        if (playerChoice == 1) {
            printf("You chose Rock! \n");
            if (computerChoice == 1) {
                printf("The computer chose Rock! Tie! \n");
            } else if (computerChoice == 2) {
                printf("The computer chose Paper! You lose! \n");
                computerScore++;
            } else {
                printf("The computer chose Scissors! You win! \n");
                playerScore++;
            }
        } else if (playerChoice == 2) {
            printf("You chose Paper! \n");
            if (computerChoice == 1) {
                printf("The computer chose Rock! You win! \n");
                playerScore++;
            } else if (computerChoice == 2) {
                printf("The computer chose Paper! Tie! \n");
            } else {
                printf("The computer chose Scissors! You lose! \n");
                computerScore++;
            }
        } else if (playerChoice == 3) {
            printf("You chose Scissors! \n");
            if (computerChoice == 1) {
                printf("The computer chose Rock! You lose! \n");
                computerScore++;
            } else if (computerChoice == 2) {
                printf("The computer chose Paper! You win! \n");
                playerScore++;
            } else {
                printf("The computer chose Scissors! Tie! \n");
            }
        } else {
            printf("Invalid choice. Please try again. \n");
        }

        printf("Player: %d | Computer: %d \n", playerScore, computerScore);

        if (playerScore >= 3) {
            printf("Player wins! \n");
            break;
        }
        if (computerScore >= 3) {
            printf("Computer wins! \n");
            break;
        }

        printf("-----------------------------\n\n");
    }

    return 0;
}