//FormAI DATASET v1.0 Category: Table Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Initialize variables
    int playerScore = 0, computerScore = 0, turnScore = 0, n, choice;
    char name[20];
    srand(time(NULL)); // Seed random number generator with current time

    // Get player name
    printf("Enter your name: ");
    scanf("%s", &name);
    printf("Welcome, %s!\n", name);

    // Game loop
    do {

        // Player turn
        printf("\n%s's turn:\n", name);
        do {
            n = rand() % 6 + 1; // Roll the dice
            printf("You rolled a %d\n", n);
            if (n == 1) {
                printf("You lose your turn and %d points\n", turnScore);
                turnScore = 0;
                break;
            }
            turnScore += n; // Add roll to turn score
            printf("Current turn score: %d\n", turnScore);
            printf("Do you want to roll again? (1 for yes, 0 for no): ");
            scanf("%d", &choice);
        } while (choice == 1);
        playerScore += turnScore; // Add turn score to player's total score
        printf("Your total score is now %d\n", playerScore);
        turnScore = 0; // Reset turn score for next player
        if (playerScore >= 100) {
            printf("Congratulations, %s! You win!\n", name);
            break;
        }

        // Computer turn
        printf("\nComputer's turn:\n");
        do {
            n = rand() % 6 + 1; // Roll the dice
            printf("Computer rolled a %d\n", n);
            if (n == 1) {
                printf("Computer loses its turn and %d points\n", turnScore);
                turnScore = 0;
                break;
            }
            turnScore += n; // Add roll to turn score
            printf("Current turn score: %d\n", turnScore);
            if (turnScore >= rand() % 10 + 10) { // Decide to stop rolling
                break;
            }
        } while (turnScore < 20);
        computerScore += turnScore; // Add turn score to computer's total score
        printf("Computer's total score is now %d\n", computerScore);
        turnScore = 0; // Reset turn score for next player
        if (computerScore >= 100) {
            printf("Sorry, %s. You lost.\n", name);
            break;
        }

    } while (1);

    return 0;
}