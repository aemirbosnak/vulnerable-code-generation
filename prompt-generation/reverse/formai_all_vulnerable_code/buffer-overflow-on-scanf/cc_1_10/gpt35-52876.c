//FormAI DATASET v1.0 Category: Funny ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Random number generator
    srand(time(NULL));

    // Welcome message
    printf("Welcome to the guessing game!\n");

    // Select a random number between 1 and 100
    int secret_number = rand() % 100 + 1;

    // Prompt the user to enter a guess
    printf("Please enter your guess (between 1 and 100): ");

    // Keep track of the number of guesses made
    int number_of_guesses = 0;

    // Loop until the user correctly guesses the secret number
    while (1)
    {
        // Read the guess from the user
        int guess;
        scanf("%d", &guess);

        // Increment the number of guesses made
        number_of_guesses++;

        // Check if the guess is too high
        if (guess > secret_number)
        {
            printf("Too high! Try again: ");
        }
        // Check if the guess is too low
        else if (guess < secret_number)
        {
            printf("Too low! Try again: ");
        }
        // The user has correctly guessed the secret number!
        else
        {
            printf("Congratulations, you won!\n");
            printf("You took %d %s to correctly guess the secret number.\n", 
                    number_of_guesses, number_of_guesses == 1 ? "guess" : "guesses");
            // Ask the user if they want to play again
            printf("Play again? (y/n) ");
            char again;
            scanf(" %c", &again);
            if (again == 'y')
            {
                // Start a new game
                printf("Starting a new game...\n");
                secret_number = rand() % 100 + 1;
                number_of_guesses = 0;
                printf("Please enter your guess (between 1 and 100): ");
            }
            else
            {
                // Exit the program
                printf("Thanks for playing!\n");
                break;
            }
        }
    }

    return 0;
}