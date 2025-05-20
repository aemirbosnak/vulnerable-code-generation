//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Introductory message
    printf("Welcome to the SURPRISE game!\n\n");

    // Initializing variables
    int secret_number, guess, tries = 0;
    srand(time(0));
    secret_number = rand() % 100 + 1;

    // Start of game loop
    do {
        printf("Guess the secret number (between 1 and 100): ");
        scanf("%d", &guess);
        tries++;

        // If guess is too high
        if (guess > secret_number) {
            printf("Too high! Try again.\n\n");
        }

        // If guess is too low
        else if (guess < secret_number) {
            printf("Too low! Try again.\n\n");
        }

        // If guess is correct
        else {
            printf("\nCongratulations! You guessed the secret number in %d tries!\n", tries);
        }
    } while (guess != secret_number);

    // Surprising ending message
    printf("But wait! That's not all...\n\n");
    printf("*SURPRISE*\n\n");
    printf("You have unlocked a secret level!\n\n");

    // Initializing variables for second game loop
    int secret_word = rand() % 5 + 1;
    char guess_word;

    // Start of second game loop
    do {
        printf("Guess the secret word (enter a letter between A and E): ");
        scanf(" %c", &guess_word);

        // If guess is incorrect
        if (guess_word < 'A' || guess_word > 'E') {
            printf("Invalid guess! Try again.\n\n");
        }
        else if (guess_word != secret_word + 'A') {
            printf("Incorrect! Try again.\n\n");
        }
    } while (guess_word != secret_word + 'A');

    // Final message
    printf("\nYOU WIN! Congratulations on uncovering the secret level.\n");
    printf("Thanks for playing the SURPRISE game! Goodbye.\n");

    return 0;
}