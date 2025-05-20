//FormAI DATASET v1.0 Category: Table Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int playerScore = 0;
int computerScore = 0;

void rollDice(int playerChoice, int computerChoice) {
    printf("Rolling dice...\n");
    srand(time(0));
    int playerDice = rand() % 6 + 1;
    printf("You rolled a %d!\n", playerDice);
    int computerDice = rand() % 6 + 1;
    printf("Computer rolled a %d!\n", computerDice);

    if (playerChoice == 1 && computerChoice == 2) {
        printf("You lose!\n");
        computerScore++;
    } else if (playerChoice == 2 && computerChoice == 1) {
        printf("You win!\n");
        playerScore++;
    } else if (playerChoice == 2 && computerChoice == 3) {
        printf("You lose!\n");
        computerScore++;
    } else if (playerChoice == 3 && computerChoice == 2) {
        printf("You win!\n");
        playerScore++;
    } else if (playerChoice == 3 && computerChoice == 1) {
        printf("You lose!\n");
        computerScore++;
    } else if (playerChoice == 1 && computerChoice == 3) {
        printf("You win!\n");
        playerScore++;
    }

    printf("Current score: You-%d Computer-%d\n", playerScore, computerScore);
}

int main() {
    printf("Welcome to C Table Game!\n");

    while (1) {
        printf("Select your move (1-Rock, 2-Paper, 3-Scissors): ");
        int playerChoice;
        scanf("%d", &playerChoice);

        if (playerChoice != 1 && playerChoice != 2 && playerChoice != 3) {
            printf("Invalid input. Please choose between 1-3.\n");
            continue;
        }

        int computerChoice = rand() % 3 + 1;
        printf("Computer chooses %d.\n", computerChoice);

        rollDice(playerChoice, computerChoice);

        if (playerScore == 5) {
            printf("You win the game!\n");
            break;
        } else if (computerScore == 5) {
            printf("Computer wins the game!\n");
            break;
        }
    }

    return 0;
}