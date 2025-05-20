//Gemma-7B DATASET v1.0 Category: Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Declare variables
    int n, i, j, score = 0, highScore = 0, guessNumber, attempts = 3;
    char name[20];

    // Get the user's name
    printf("Enter your name: ");
    scanf("%s", name);

    // Initialize the game loop
    while (attempts > 0)
    {
        // Generate a random number
        srand(time(NULL));
        guessNumber = rand() % 100 + 1;

        // Get the user's guess
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &n);

        // Check if the guess is correct
        if (n == guessNumber)
        {
            // Increment the user's score
            score++;

            // Check if the user's score is higher than the high score
            if (score > highScore)
            {
                highScore = score;
            }

            // Print a congratulatory message
            printf("Congratulations, %s! You guessed the number correctly!\n", name);

            // Break out of the game loop
            break;
        }
        else
        {
            // Decrement the user's attempts
            attempts--;

            // Print an error message
            printf("Sorry, %s. Your guess was incorrect. You have %d attempts left.\n", name, attempts);
        }
    }

    // Print the user's final score and high score
    printf("Your final score: %d\n", score);
    printf("Your high score: %d\n", highScore);

    return 0;
}