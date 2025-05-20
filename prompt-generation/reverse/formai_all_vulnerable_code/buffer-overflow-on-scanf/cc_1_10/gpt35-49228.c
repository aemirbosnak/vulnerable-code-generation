//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random integer between min and max, inclusive
int get_random_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Welcome message
    printf("*** Welcome to the Guessing Game! ***\n");
    printf("You have 10 chances to guess the secret number between 1 and 100.\n");

    // Generate the secret number
    int secret_number = get_random_int(1, 100);

    // Main game loop
    int num_guesses = 0;
    while (num_guesses < 10) {
        // Prompt the user to guess the number
        printf("Guess #%d: ", num_guesses + 1);
        int guess;
        scanf("%d", &guess);

        // Check if the guess is correct
        if (guess == secret_number) {
            printf("Congratulations! You guessed the secret number in %d guesses!\n", num_guesses + 1);
            return 0;
        }

        // Give a hint to the user about their guess
        if (guess < secret_number) {
            printf("Too low!\n");
        } else {
            printf("Too high!\n");
        }

        // Increment the number of guesses
        num_guesses++;
    }

    // If the user didn't guess the number within the given number of tries, print the secret number
    printf("Sorry, you did not guess the secret number within 10 tries.\n");
    printf("The secret number was %d.\n", secret_number);

    return 0;
}