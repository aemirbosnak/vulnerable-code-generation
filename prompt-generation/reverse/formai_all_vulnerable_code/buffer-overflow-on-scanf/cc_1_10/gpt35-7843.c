//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: thoughtful
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    // Welcome message
    printf("Welcome to the Guessing Game!\n\n");

    // Random number generation
    srand(time(0));
    int randomNumber = rand() % 100 + 1;

    // Variable declaration
    int guess = 0;
    int attempts = 0;
    int maxAttempts = 10;

    // Game loop
    while (guess != randomNumber && attempts < maxAttempts) 
    {
        // Getting user input
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &guess);
        
        // Checking if guess is valid
        if (guess < 1 || guess > 100)
        {
            printf("Invalid guess! Please guess again.\n");
            continue; // Start the loop again and ignore all subsequent code
        }

        // Updating attempts
        attempts++;
        
        // Giving hints based on guess
        if (guess < randomNumber)
        {
            printf("Sorry, your guess is too low. Guess again.\n");
        }
        else if (guess > randomNumber)
        {
            printf("Sorry, your guess is too high. Guess again.\n");
        }
    }

    // Game ended, displaying result
    if (guess == randomNumber)
    {
        printf("\nCongratulations! You guessed the number in %d attempts.\n", attempts);
    }
    else
    {
        printf("\nSorry, you did not guess the number in %d attempts. The number was %d.\n", maxAttempts, randomNumber);
    }

    return 0; // End of program
}