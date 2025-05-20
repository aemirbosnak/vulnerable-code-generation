//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10

int main()
{
    int num_guess, guess_history[MAX_NUM], target, attempts = 0, game_over = 0;

    printf("Welcome to the Guessing Game!\n");

    // Generate a random target number
    target = rand() % MAX_NUM + 1;

    // Initialize the guess history
    for (int i = 0; i < MAX_NUM; i++)
    {
        guess_history[i] = 0;
    }

    // Start the game loop
    while (!game_over)
    {
        // Get the user's guess
        printf("Enter your guess: ");
        scanf("%d", &num_guess);

        // Check if the guess is valid
        if (num_guess < 1 || num_guess > MAX_NUM)
        {
            printf("Invalid guess.\n");
            continue;
        }

        // Check if the guess has already been made
        if (guess_history[num_guess] == 1)
        {
            printf("You already guessed that number.\n");
            continue;
        }

        // Record the guess in the history
        guess_history[num_guess] = 1;

        // Check if the guess is correct
        if (num_guess == target)
        {
            printf("Congratulations! You won!\n");
            game_over = 1;
        }
        else
        {
            // Increment the number of attempts
            attempts++;

            // Give feedback on the guess
            if (num_guess < target)
            {
                printf("Your guess is too low.\n");
            }
            else
            {
                printf("Your guess is too high.\n");
            }

            // Check if the user has exhausted their attempts
            if (attempts == MAX_NUM)
            {
                printf("Sorry, you lost. The target number was %d.\n", target);
                game_over = 1;
            }
        }
    }

    return 0;
}