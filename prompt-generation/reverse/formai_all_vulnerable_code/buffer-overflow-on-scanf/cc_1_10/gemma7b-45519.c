//Gemma-7B DATASET v1.0 Category: Table Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 10

int main()
{
    int i, j, score = 0, round = 1, guessNumber, targetNumber;

    // Generate a random target number between 1 and MAX_NUMBER
    targetNumber = rand() % MAX_NUMBER + 1;

    // Display the target number
    printf("Target number: %d\n", targetNumber);

    // Start the game loop
    while (score < 5 && round <= 3)
    {
        // Get the user's guess
        printf("Enter your guess: ");
        scanf("%d", &guessNumber);

        // Check if the guess is correct
        if (guessNumber == targetNumber)
        {
            // Increment the score and end the round
            score++;
            round++;
            printf("Congratulations! You guessed the number in %d rounds.\n", round);
        }
        else if (guessNumber > targetNumber)
        {
            // Print an error message
            printf("Your guess is too high.\n");
        }
        else
        {
            // Print an error message
            printf("Your guess is too low.\n");
        }

        // Increment the round number
        round++;
    }

    // End the game
    printf("Game over! Your final score is: %d\n", score);

    return 0;
}