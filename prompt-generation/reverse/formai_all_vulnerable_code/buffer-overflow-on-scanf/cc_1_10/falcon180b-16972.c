//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: accurate
/*
 * This is a simple game where the player has to guess a number between 1 and 100.
 * The program generates a random number and the player has to guess it.
 * The program gives hints to the player whether the guess is too high or too low.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num, guess;
    int too_high = 0, too_low = 0;
    int max_guesses = 10;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate a random number between 1 and 100
    num = rand() % 100 + 1;

    // Loop until the player guesses the correct number or runs out of guesses
    while (guess!= num && max_guesses > 0) {
        // Get the player's guess
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &guess);

        // Check if the guess is too high or too low
        if (guess < num) {
            too_low = 1;
        } else if (guess > num) {
            too_high = 1;
        }

        // Update the maximum number of guesses
        max_guesses--;

        // Print a hint to the player
        if (too_high && too_low) {
            printf("You're getting warmer!\n");
        } else if (too_high) {
            printf("Too high!\n");
        } else if (too_low) {
            printf("Too low!\n");
        }
    }

    // Print the result of the game
    if (guess == num) {
        printf("Congratulations, you guessed the number in %d guesses!\n", max_guesses);
    } else {
        printf("Sorry, you ran out of guesses. The correct number was %d.\n", num);
    }

    return 0;
}