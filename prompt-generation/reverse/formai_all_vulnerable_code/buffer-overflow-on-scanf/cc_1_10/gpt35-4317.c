//FormAI DATASET v1.0 Category: Table Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Welcome message
    printf("*** Welcome to the Grateful Table Game! ***\n\n");
    printf("In this game, you will play against the computer to reach a total score of 21.\n");
    printf("Each turn you will choose to either draw a card or hold.\n");
    printf("Be careful not to go over 21, or you will lose the game!\n\n");

    // Initiate game variables
    int playerScore = 0;
    int computerScore = 0;
    int playerTurn = 1;
    int cardValue;

    // Play the game until someone wins
    while (playerScore < 21 && computerScore < 21) {
        printf("Player score: %d   Computer score: %d\n", playerScore, computerScore);

        // Player's turn
        if (playerTurn) {
            printf("Your turn! Enter 1 to draw a card or 2 to hold: ");
            int choice;
            scanf("%d", &choice);

            // Draw a card
            if (choice == 1) {
                srand(time(NULL));
                cardValue = rand() % 10 + 1;
                playerScore += cardValue;
                printf("You drew a %d. Your score is now %d.\n", cardValue, playerScore);

                // Check if player went over 21
                if (playerScore > 21) {
                    printf("Oops! You went over 21. Computer wins!\n");
                    return 0;
                }
            }
            // Hold
            else {
                printf("You held. Computer's turn!\n");
                playerTurn = 0;
            }
        }

        // Computer's turn
        else {
            srand(time(NULL));
            cardValue = rand() % 10 + 1;
            computerScore += cardValue;
            printf("Computer drew a %d. Its score is now %d.\n", cardValue, computerScore);

            // Check if computer went over 21
            if (computerScore > 21) {
                printf("Oops! Computer went over 21. You win!\n");
                return 0;
            }

            // Computer holds if score is 17 or higher
            if (computerScore >= 17) {
                printf("Computer holds! Your turn!\n");
                playerTurn = 1;
            }
        }
    }

    // Game ended in a tie
    if (playerScore == computerScore) {
        printf("It's a tie! Great job!\n");
    }
    // Player wins
    else if (playerScore > computerScore) {
        printf("Congratulations! You win!\n");
    }
    // Computer wins
    else {
        printf("Sorry, you lose. Better luck next time.\n");
    }

    return 0;
}