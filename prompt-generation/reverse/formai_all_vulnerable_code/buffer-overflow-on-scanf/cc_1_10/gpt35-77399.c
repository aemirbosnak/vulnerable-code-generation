//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int highscore = 0; // keeps track of the highest score achieved
    srand(time(NULL)); // initializes the random number generator seed

    printf("Welcome to the Number Guessing Game!\n");
    printf("You have three attempts to guess the correct number.\n");

    while (1) { // loop for playing multiple rounds
        int target = rand() % 100 + 1; // generates a random number between 1 and 100
        int score = 0; // keeps track of the current score (number of tries used)

        while (score < 3) {
            int guess;
            printf("Guess the number (1-100): ");
            scanf("%d", &guess);

            if (guess == target) {
                printf("Congratulations! You guessed the correct number in %d tries.\n", score+1);
                if (score+1 > highscore) {
                    highscore = score+1;
                    printf("New highscore: %d!\n", highscore);
                }
                break; // exit inner loop
            } else if (guess < target) {
                printf("Too low. ");
            } else {
                printf("Too high. ");
            }

            score++;
        }

        if (score == 3) {
            printf("Sorry, you couldn't guess the number in time. The correct number was %d.\n", target);
        }

        char playAgain;
        printf("Play again? (y/n): ");
        scanf(" %c", &playAgain);

        if (playAgain != 'y') {
            break; // exit outer loop
        }
    }

    printf("Thanks for playing! Your highest score was %d.\n", highscore);

    return 0;
}