//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // initialize random seed
    srand(time(NULL));

    // game start!
    while (1) {

        // generate random number between 1 to 3
        int shape = rand() % 3 + 1;

        // display game board with random shape
        printf("\n\n\n");
        if (shape == 1) {
            printf("      *  \n");
            printf("   *     * \n");
            printf(" *         *\n");
            printf("   *     * \n");
            printf("      *  \n");
        } else if (shape == 2) {
            printf("  *****  \n");
            printf(" **** ****\n");
            printf("***   ***\n");
            printf(" **** ****\n");
            printf("  *****  \n");
        } else {
            printf("     *     \n");
            printf("   *   *   \n");
            printf("  *     *  \n");
            printf("   *   *   \n");
            printf("     *     \n");
        }

        // ask user to guess the shape
        int guess;
        printf("\nGuess the shape! (1: Star, 2: Square, 3: Triangle): ");
        scanf("%d", &guess);

        // check user's guess and display message accordingly
        if (guess == shape) {
            printf("\nCongratulations! You guessed it right!\n");
        } else {
            printf("\nSorry, wrong guess! The correct answer is: %d\n", shape);
        }

        // ask user if they want to play again
        char playAgain;
        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

        // if user doesn't want to play again, end the game
        if (playAgain != 'y' && playAgain != 'Y') {
            printf("\nThanks for playing! Goodbye...\n");
            break;
        }
    }

    return 0;
}