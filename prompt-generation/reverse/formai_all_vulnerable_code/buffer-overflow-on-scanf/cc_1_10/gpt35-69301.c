//FormAI DATASET v1.0 Category: Table Game ; Style: automated
// Unique C Table Game Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize random number generator
    srand(time(0));

    // Declare variables
    int guess, answer, attempts = 0;

    // Generate random number between 1 and 100
    answer = rand() % 100 + 1;

    // Welcome message
    printf("Welcome to the Guessing Game!\n");
    printf("A random number between 1 and 100 has been generated.\n");
    printf("You have 10 attempts to guess it correctly.\n");

    // Loop for 10 attempts
    while (attempts < 10)
    {
        // Prompt user to enter a guess
        printf("Guess #%d: ", attempts + 1);
        scanf("%d", &guess);

        // Check if guess is correct
        if (guess == answer)
        {
            printf("Congratulations, you guessed the number in %d attempts!\n", attempts + 1);
            break;
        }
        else if (guess < answer)
        {
            printf("Your guess is too low. Try again.\n");
        }
        else
        {
            printf("Your guess is too high. Try again.\n");
        }

        attempts++;
    }

    // If all attempts are used up
    if (attempts == 10)
    {
        printf("Sorry, you have used up all your attempts.\n");
        printf("The correct answer was %d.\n", answer);
    }

    return 0;
}