//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of guesses
#define MAX_GUESSES 5

// Define the secret number to be guessed
int secret_number = 12;

// Main game loop
int main()
{
    // Initialize the number of guesses
    int guesses = 0;

    // Loop until the player guesses the number or runs out of guesses
    while (guesses < MAX_GUESSES)
    {
        // Get the player's guess
        int guess = 0;
        printf("Enter your guess: ");
        scanf("%d", &guess);

        // Check if the guess is correct
        if (guess == secret_number)
        {
            // The player has guessed the number
            printf("Congratulations! You have guessed the number!\n");
            break;
        }
        else if (guess < secret_number)
        {
            // The guess is too low
            printf("Your guess is too low. Try again.\n");
        }
        else
        {
            // The guess is too high
            printf("Your guess is too high. Try again.\n");
        }

        // Increment the number of guesses
        guesses++;
    }

    // If the player runs out of guesses
    if (guesses == MAX_GUESSES)
    {
        // The player has run out of guesses
        printf("Sorry, you have run out of guesses. The secret number was %d.\n", secret_number);
    }

    return 0;
}