//FormAI DATASET v1.0 Category: Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This program generates a simple game called "Guess the Number".
   The computer chooses a random number between 1 and 100 and the player must
   guess it in as few attempts as possible. */

int main()
{
    int number, guess, num_guesses = 0;
    char name[20];

    // Get the player's name
    printf("Welcome to Guess the Number!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Hello, %s! Let's play!\n\n", name);

    // Generate the random number
    srand(time(NULL));
    number = rand() % 100 + 1;

    // Start the game
    while (1)
    {
        // Get the player's guess
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &guess);

        // Check if the guess is correct
        if (guess == number)
        {
            printf("Congratulations, %s! You guessed the number in %d tries!\n", name, num_guesses);
            break;
        }

        // Give the player a hint
        if (guess < number)
        {
            printf("Too low! Guess higher.\n");
        }
        else
        {
            printf("Too high! Guess lower.\n");
        }

        // Increase the number of guesses
        num_guesses++;
    }

    return 0;
}