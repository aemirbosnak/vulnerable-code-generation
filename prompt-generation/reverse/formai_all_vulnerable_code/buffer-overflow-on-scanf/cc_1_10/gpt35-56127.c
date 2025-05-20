//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to clear terminal screen */
void clearScreen() {
    system("clear||cls");
}

int main() {

    /* Set random seed */
    srand(time(NULL));

    /* Initialize variables */
    int playerScore = 0, computerScore = 0;
    char choice;
    int computerChoice, playerChoice;

    printf("Welcome to Rock-Paper-Scissors Game!\n");

    do {
        printf("\nPlease choose:\n1) Rock\n2) Paper\n3) Scissors\nEnter your choice: ");
        scanf("%d", &playerChoice);

        /* Generate computer choice randomly */
        computerChoice = rand() % 3 + 1;

        /* Determine winner */
        if (playerChoice == computerChoice) {
            printf("\nTie!\n");
        } else if (playerChoice == 1 && computerChoice == 3) {
            printf("\nYou win!\n");
            playerScore++;
        } else if (playerChoice == 2 && computerChoice == 1) {
            printf("\nYou win!\n");
            playerScore++;
        } else if (playerChoice == 3 && computerChoice == 2) {
            printf("\nYou win!\n");
            playerScore++;
        } else {
            printf("\nComputer wins!\n");
            computerScore++;
        }

        /* Display scores */
        printf("\nPlayer Score: %d\nComputer Score: %d\n", playerScore, computerScore);

        /* Ask user if they want to play again */
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &choice);

        /* Clear screen */
        clearScreen();

    } while (choice == 'y' || choice == 'Y');

    printf("\nThanks for playing!\n");

    return 0;
}