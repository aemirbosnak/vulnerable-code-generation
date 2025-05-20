//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: puzzling
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {

    // Initialize variables
    int score = 0, guess, num, max_range;
    char play_again = 'y';

    // Greet user and ask for range of numbers
    printf("Welcome to the Number Guessing Game!\n");
    printf("\nChoose a range of numbers to guess from (up to 100): ");
    scanf("%d", &max_range);
    printf("\n");

    while (play_again == 'y') {

        // Generate random number within range
        srand((unsigned int) time(NULL));
        num = rand() % max_range;

        // Ask user to guess the number and keep track of score
        printf("Guess a number between 0 and %d:\n", max_range);
        scanf("%d", &guess);

        while (guess != num) {
            if (guess < num) {
                printf("Too low! Try again:\n");
                score++;
                scanf("%d", &guess);
            } else {
                printf("Too high! Try again:\n");
                score++;
                scanf("%d", &guess);
            }
        }

        // If user guesses correctly, congratulate them and ask if they want to play again
        printf("Congratulations! You guessed the number in %d tries!\n", score);
        printf("Would you like to play again? (y/n)\n");
        scanf(" %c", &play_again);

        // Reset score for new game
        score = 0;
    }

    // Thank user for playing and end program
    printf("\nThanks for playing the Number Guessing Game!\n");
    return 0;
}