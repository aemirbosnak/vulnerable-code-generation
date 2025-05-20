//FormAI DATASET v1.0 Category: Table Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max values
int getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    int playerScore = 0;
    int computerScore = 0;
    int playerMove, computerMove;
    char playAgain;

    // Seed random number generator with current time
    srand(time(NULL));

    printf("Welcome to the Peaceful Table Game!\n");

    do {
        // Get player's move
        printf("Choose your move:\n");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        scanf("%d", &playerMove);

        // Generate computer's move
        computerMove = getRandomNumber(1, 3);

        // Display moves
        printf("You played ");

        switch (playerMove) {
            case 1:
                printf("Rock.\n");
                break;
            case 2:
                printf("Paper.\n");
                break;
            case 3:
                printf("Scissors.\n");
                break;
            default:
                printf("an invalid move.\n");
                break;
        }

        printf("Computer played ");

        switch (computerMove) {
            case 1:
                printf("Rock.\n");
                break;
            case 2:
                printf("Paper.\n");
                break;
            case 3:
                printf("Scissors.\n");
                break;
        }

        // Determine winner
        if (playerMove == computerMove) {
            printf("It's a tie!\n");
        } else if ((playerMove == 1 && computerMove == 3) ||
                   (playerMove == 2 && computerMove == 1) ||
                   (playerMove == 3 && computerMove == 2)) {
            printf("You win!\n");
            playerScore++;
        } else {
            printf("Computer wins!\n");
            computerScore++;
        }

        // Display scores
        printf("Scores:\n");
        printf("You: %d\n", playerScore);
        printf("Computer: %d\n", computerScore);

        // Ask player if they want to play again
        printf("Play again? (y/n)\n");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thank you for playing the Peaceful Table Game!\n");

    return 0;
}