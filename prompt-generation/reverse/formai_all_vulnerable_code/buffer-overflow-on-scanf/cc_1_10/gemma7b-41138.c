//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main()
{

    system("clear");

    // Create a random number between 1-10
    int randomNumber = rand() % 10 + 1;

    // Define the number of guesses
    int guesses = 0;

    // Start the game loop
    while (guesses < 5)
    {
        // Get the user's guess
        int guess = 0;
        printf("Enter your guess: ");
        scanf("%d", &guess);

        // Check if the guess is correct
        if (guess == randomNumber)
        {
            // You won!
            printf("Congratulations! You won!");
            break;
        }
        else if (guess < randomNumber)
        {
            // Guess too low!
            printf("Guess too low. Try again.");
        }
        else
        {
            // Guess too high!
            printf("Guess too high. Try again.");
        }

        // Increment the number of guesses
        guesses++;
    }

    // If the user ran out of guesses, they lose
    if (guesses == 5)
    {
        printf("Sorry, you lose. The number was %d.", randomNumber);
    }

    return 0;
}