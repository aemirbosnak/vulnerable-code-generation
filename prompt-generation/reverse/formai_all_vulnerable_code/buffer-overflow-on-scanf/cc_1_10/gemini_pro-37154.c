//GEMINI-pro DATASET v1.0 Category: Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Constants.
    const int NUM_COLORS = 6;
    const int NUM_GUESSES = 10;
    const int MAX_COLOR_VALUE = 255;

    // Initialize random number generator.
    srand(time(NULL));

    // Generate a random color.
    int secret_color[3];
    for (int i = 0; i < 3; i++)
    {
        secret_color[i] = rand() % (MAX_COLOR_VALUE + 1);
    }

    // Game loop.
    int guesses = 0;
    while (guesses < NUM_GUESSES)
    {
        // Get the player's guess.
        int guess_color[3];
        printf("Enter your guess (3 numbers between 0 and 255): ");
        scanf("%d %d %d", &guess_color[0], &guess_color[1], &guess_color[2]);

        // Check if the player's guess is correct.
        int correct = 1;
        for (int i = 0; i < 3; i++)
        {
            if (guess_color[i] != secret_color[i])
            {
                correct = 0;
                break;
            }
        }

        // Print the result.
        if (correct)
        {
            printf("You guessed the correct color!\n");
            break;
        }
        else
        {
            printf("Your guess is incorrect.\n");
            guesses++;
        }
    }

    // Print the secret color.
    if (guesses == NUM_GUESSES)
    {
        printf("The secret color was: %d %d %d\n", secret_color[0], secret_color[1], secret_color[2]);
    }

    return 0;
}