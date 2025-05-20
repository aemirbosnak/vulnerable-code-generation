//FormAI DATASET v1.0 Category: Table Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerScore = 0, computerScore = 0, roll;
    char choice;

    srand(time(NULL)); // Initialize the random number generator

    printf("Welcome to the C Table Game!\n");

    do {
        printf("\nYour turn!\n");
        roll = rand() % 6 + 1; // Generate a random number between 1 and 6

        if (roll == 1) {
            playerScore = 0; // Reset the player's score to 0
            printf("You rolled a 1 and lost all your points.\n");
        } else {
            playerScore += roll; // Add the roll to the player's score
            printf("You rolled a %d and your score is now %d.\n", roll, playerScore);
            printf("Do you want to keep rolling? (y/n): ");
            scanf(" %c", &choice);
        }
    } while (choice == 'y' && playerScore < 100);

    if (playerScore >= 100) {
        printf("You reached 100 points and won the game!\n");
        return 0;
    }

    printf("\nIt's the computer's turn!\n");

    do {
        roll = rand() % 6 + 1; // Generate a random number between 1 and 6

        if (roll == 1) {
            computerScore = 0; // Reset the computer's score to 0
            printf("The computer rolled a 1 and lost all its points.\n");
        } else {
            computerScore += roll; // Add the roll to the computer's score
            printf("The computer rolled a %d and its score is now %d.\n", roll, computerScore);
        }
    } while (computerScore < playerScore && computerScore < 100);

    if (computerScore >= 100) {
        printf("The computer reached 100 points and won the game!\n");
        return 0;
    }

    if (playerScore > computerScore) {
        printf("You won the game with a score of %d to %d!\n", playerScore, computerScore);
    } else {
        printf("The computer won the game with a score of %d to %d.\n", computerScore, playerScore);
    }

    return 0;
}