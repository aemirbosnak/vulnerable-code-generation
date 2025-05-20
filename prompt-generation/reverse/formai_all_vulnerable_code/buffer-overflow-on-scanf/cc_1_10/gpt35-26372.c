//FormAI DATASET v1.0 Category: Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Maximum number of guesses allowed
#define MAX_GUESSES 5

int main()
{
    // Seed the random number generator with current time
    srand(time(NULL));

    // Generate a random number between 1 and 100
    int number = rand() % 100 + 1;

    // Initialize number of guesses to 0
    int num_guesses = 0;

    // Initialize guess variable
    int guess;

    // Let the user know the game has started
    printf("I'm thinking of a number between 1 and 100. You have %d guesses.\n", MAX_GUESSES);

    // Loop until the user exceeds the maximum number of guesses or guesses the correct number
    while (num_guesses < MAX_GUESSES)
    {
        // Increment the number of guesses
        num_guesses++;

        // Prompt the user to enter a guess
        printf("Guess %d: ", num_guesses);
        scanf("%d", &guess);

        // If the guess is correct, print a message and exit the loop
        if (guess == number)
        {
            printf("Congratulations, you guessed the number in %d tries!\n", num_guesses);
            return 0;
        }
        // If the guess is too high, tell the user
        else if (guess > number)
        {
            printf("Too high! ");
        }
        // If the guess is too low, tell the user
        else
        {
            printf("Too low! ");
        }

        // Let the user know how many guesses they have left
        printf("You have %d guesses left.\n", MAX_GUESSES - num_guesses);
    }

    // If the user exceeds the maximum number of guesses, print a message with the correct number
    printf("Sorry, you didn't guess the number. The number was %d.\n", number);

    return 0;
}