//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int playerScore = 0;
    int computerScore = 0;
    int round = 1;
    srand(time(NULL));

    printf("Welcome to Rock, Paper, Scissors!\n");

    do {
        printf("\nROUND %d\n", round);
        printf("Player Score: %d\n", playerScore);
        printf("Computer Score: %d\n", computerScore);
        printf("Select your weapon:\n");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        printf("4. Quit Game\n");
        scanf("%d", &choice);

        int computerChoice = rand() % 3 + 1;

        if (choice == 1) {
            printf("\n\nYou chose Rock.\n");
            if (computerChoice == 1) {
                printf("Computer also chose Rock.\n");
                printf("It's a tie!\n");
            } else if (computerChoice == 2) {
                printf("Computer chose Paper.\n");
                printf("Computer wins this round!\n");
                computerScore++;
            } else {
                printf("Computer chose Scissors.\n");
                printf("You win this round!\n");
                playerScore++;
            }
        } else if (choice == 2) {
            printf("\n\nYou chose Paper.\n");
            if (computerChoice == 1) {
                printf("Computer chose Rock.\n");
                printf("You win this round!\n");
                playerScore++;
            } else if (computerChoice == 2) {
                printf("Computer also chose Paper.\n");
                printf("It's a tie!\n");
            } else {
                printf("Computer chose Scissors.\n");
                printf("Computer wins this round!\n");
                computerScore++;
            }
        } else if (choice == 3) {
            printf("\n\nYou chose Scissors.\n");
            if (computerChoice == 1) {
                printf("Computer chose Rock.\n");
                printf("Computer wins this round!\n");
                computerScore++;
            } else if (computerChoice == 2) {
                printf("Computer chose Paper.\n");
                printf("You win this round!\n");
                playerScore++;
            } else {
                printf("Computer also chose Scissors.\n");
                printf("It's a tie!\n");
            }
        } else if (choice == 4) {
            printf("\n\nThanks for playing!\n");
            break;
        } else {
            printf("\n\nInvalid choice. Please select 1, 2, 3, or 4.\n");
        }

        round++;

    } while (playerScore < 3 && computerScore < 3 && choice != 4);

    if (playerScore > computerScore) {
        printf("You won the game!\n");
    } else if (computerScore > playerScore) {
        printf("Computer won the game!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}