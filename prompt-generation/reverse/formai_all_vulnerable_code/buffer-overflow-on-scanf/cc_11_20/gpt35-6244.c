//FormAI DATASET v1.0 Category: Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main() {
    int playerScore = 0;
    int computerScore = 0;
    int playerOption, computerOption;
    srand(time(NULL));
 
    printf("Welcome to the C Game! Let's play rock-paper-scissors.\n\n");
 
    while (1) {
        printf("Enter your choice...\n");
        printf("1 - Rock\n2 - Paper\n3 - Scissors\n");
        scanf("%d", &playerOption);
 
        computerOption = rand() % 3 + 1;
 
        if (playerOption == 1) {
            printf("\nYou chose Rock.\n");
            if (computerOption == 1) {
                printf("Computer chose Rock.\n");
                printf("Tie!\n");
            } else if (computerOption == 2) {
                printf("Computer chose Paper.\n");
                printf("Computer wins!\n");
                computerScore++;
            } else {
                printf("Computer chose Scissors.\n");
                printf("You win!\n");
                playerScore++;
            }
        } else if (playerOption == 2) {
            printf("\nYou chose Paper.\n");
            if (computerOption == 1) {
                printf("Computer chose Rock.\n");
                printf("You win!\n");
                playerScore++;
            } else if (computerOption == 2) {
                printf("Computer chose Paper.\n");
                printf("Tie!\n");
            } else {
                printf("Computer chose Scissors.\n");
                printf("Computer wins!\n");
                computerScore++;
            }
        } else if (playerOption == 3) {
            printf("\nYou chose Scissors.\n");
            if (computerOption == 1) {
                printf("Computer chose Rock.\n");
                printf("Computer wins!\n");
                computerScore++;
            } else if (computerOption == 2) {
                printf("Computer chose Paper.\n");
                printf("You win!\n");
                playerScore++;
            } else {
                printf("Computer chose Scissors.\n");
                printf("Tie!\n");
            }
        } else {
            printf("Invalid option. Please choose again.\n");
        }
 
        printf("\nScoreboard:\nPlayer - %d | Computer - %d\n\n", playerScore, computerScore);
 
        if (playerScore == 5) {
            printf("Congratulations! You win the game.\n");
            break;
        } else if (computerScore == 5) {
            printf("Game over. Better luck next time!\n");
            break;
        }
    }
 
    return 0;
}