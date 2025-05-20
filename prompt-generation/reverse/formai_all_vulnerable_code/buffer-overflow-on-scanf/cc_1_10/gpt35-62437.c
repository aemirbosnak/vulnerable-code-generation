//FormAI DATASET v1.0 Category: Table Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //initialize variables
    int answer, guess, numAttempts;
    char playAgain;

    //set random seed
    srand((unsigned) time(NULL));

    do {
        //generate random number between 1-100
        answer = rand() % 100 + 1;

        //initialize attempt counter
        numAttempts = 0;

        //start game
        printf("\n");
        printf("Guess the number between 1-100!\n");

        do {
            //get user guess
            printf("Enter your guess: ");
            scanf("%d", &guess);

            //increment attempt counter
            numAttempts++;

            //check if guess is correct or incorrect
            if (guess == answer) {
                printf("Congratulations! You guessed the correct number in %d attempts.\n", numAttempts);
            } else if (guess < answer) {
                printf("Incorrect. Guess higher.\n");
            } else {
                printf("Incorrect. Guess lower.\n");
            }

        } while (guess != answer);

        //prompt user to play again
        printf("Do you want to play again? (Y/N): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'Y' || playAgain == 'y');

    return 0;
}