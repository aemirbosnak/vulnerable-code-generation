//Code Llama-13B DATASET v1.0 Category: Game ; Style: romantic
/*
 * A romantic game in C
 *
 * Author: [Your Name]
 * Date: [Current Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random number between 1 and 10
int get_random_number() {
    return rand() % 10 + 1;
}

// Function to check if the guess is correct
int check_guess(int guess, int answer) {
    if (guess == answer) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    // Initialize the random number seed
    srand(time(NULL));

    // Generate a random number between 1 and 10
    int answer = get_random_number();

    // Initialize the guess variable
    int guess = 0;

    // Loop until the user guesses the correct number
    while (guess != answer) {
        // Ask the user to guess a number
        printf("Guess a number between 1 and 10: ");
        scanf("%d", &guess);

        // Check if the guess is correct
        if (check_guess(guess, answer)) {
            printf("You guessed it! The answer was %d.\n", answer);
            break;
        } else {
            printf("Sorry, that's not correct. Try again.\n");
        }
    }

    return 0;
}