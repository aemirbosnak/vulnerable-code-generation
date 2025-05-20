//FormAI DATASET v1.0 Category: Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Welcome to the Grateful Game!
    printf("Welcome to the Grateful Game!\n\n");
    printf("You are a traveler on a journey, and you have come across a wise old man. He challenges you to a game. If you win, he will give you a priceless treasure. If you lose, he will keep your horse.\n");
    printf("Do you accept his challenge? (y/n)\n");

    // Initialize variables for player choice and game result
    char choice;
    int result;

    // Get player choice
    scanf("%c", &choice);

    // Check if player accepts challenge
    if (choice == 'y')
    {
        // Tell player the game is starting
        printf("Great! Let's get started!\n\n");

        // Seed random number generator
        srand(time(NULL));

        // Generate a random number
        int answer = rand() % 10 + 1;

        // Ask player to guess a number
        printf("I'm thinking of a number between 1 and 10. Can you guess what it is?\n");

        // Loop until player guesses correctly
        do
        {
            // Get player guess
            int guess;
            scanf("%d", &guess);

            // Check if player's guess is correct
            if (guess == answer)
            {
                printf("Congratulations! You've won the game and the priceless treasure!\n");
                result = 1;
                break;
            }
            else if (guess < answer)
                printf("Oops, that's too low! Guess again.\n");
            else
                printf("Oops, that's too high! Guess again.\n");

        } while (1);

    }
    else
    {
        // Player declines challenge
        printf("Sorry to hear that. Perhaps another time.\n");
        result = 0;
    }

    // Return success or failure
    return result;
}