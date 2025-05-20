//Code Llama-13B DATASET v1.0 Category: Game ; Style: Donald Knuth
/*
 * A unique C game program in a Donald Knuth style.
 *
 * This program plays a game of "Guess the Number" with the user.
 * The computer will think of a number between 1 and 100, and the
 * user will have to guess it. After each guess, the computer will
 * give a hint, indicating whether the guess was too high or too low.
 *
 * The game will continue until the user correctly guesses the number.
 *
 * The program will be written in a style similar to that of Donald Knuth.
 * It will use a lot of comments and punctuation, and will be
 * written in a way that is easy to read and understand.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate a random number between 1 and 100
    int number = rand() % 100 + 1;

    // Prompt the user to start guessing
    printf("Guess a number between 1 and 100.\n");

    // Loop until the user correctly guesses the number
    while (1) {
        // Get the user's guess
        int guess;
        scanf("%d", &guess);

        // Check if the guess is correct
        if (guess == number) {
            printf("You guessed correctly! The number was %d.\n", number);
            break;
        }

        // Give a hint based on the user's guess
        if (guess < number) {
            printf("Your guess is too low. Try again.\n");
        } else {
            printf("Your guess is too high. Try again.\n");
        }
    }

    // End the program
    return 0;
}