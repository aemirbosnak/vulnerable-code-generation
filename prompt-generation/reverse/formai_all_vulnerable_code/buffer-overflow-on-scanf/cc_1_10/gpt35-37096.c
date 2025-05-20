//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main() {
    // initialize variables
    int score = 0;
    int lives = 3;
    int num_guesses = 0;
    int num_to_guess;

    // generate random number
    srand(time(NULL));
    num_to_guess = rand() % 100 + 1;

    // game loop
    while(true) {
        // print game info
        printf("--------------------\n");
        printf("Guess the number (1-100)\n");
        printf("Score: %d\n", score);
        printf("Lives: %d\n", lives);
        printf("--------------------\n");

        // get user input
        int guess;
        printf("Enter a number: ");
        scanf("%d", &guess);
        num_guesses++;

        // check if user guessed correctly
        if(guess == num_to_guess) {
            printf("Congratulations! You guessed the number.\n");
            printf("Number of guesses: %d\n", num_guesses);
            score += 100;
            break;
        }

        // check if user ran out of lives
        lives--;
        if(lives == 0) {
            printf("Game over! You ran out of lives.\n");
            printf("The number to guess was: %d\n", num_to_guess);
            break;
        }

        // give user hint
        if(guess < num_to_guess) {
            printf("The number is higher.\n");
        } else {
            printf("The number is lower.\n");
        }

        // calculate score
        if(num_guesses <= 3) {
            score += 50;
        } else if(num_guesses <= 5) {
            score += 25;
        } else if(num_guesses <= 10) {
            score += 10;
        }

        // wait for user to press enter
        printf("Press enter to continue.\n");
        getchar();
        getchar();
    }

    return 0;
}