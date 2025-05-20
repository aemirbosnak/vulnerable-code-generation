//FormAI DATASET v1.0 Category: Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 10     // Maximum number of guesses
#define MAX_RANGE 50       // Maximum range for random number

int main()
{
    int numberToGuess, guess, triesLeft, isWin;
    srand((unsigned int) time(NULL)); // Initialize random number generator

    printf("--- Welcome to the Number Guessing Game! ---\n\n");

    // Generate random number to guess
    numberToGuess = rand() % MAX_RANGE + 1; 

    isWin = 0; // Initialize isWin flag to false
    triesLeft = MAX_GUESSES;

    // Loop until user wins or runs out of guesses
    while(triesLeft > 0 && !isWin)
    {
        printf("Guess the number (1-%d): ", MAX_RANGE);
        scanf("%d", &guess);

        // Check if guess is too low, too high, or correct
        if(guess < numberToGuess)
        {
            printf("Too low! You have %d tries left.\n", triesLeft-1);
        }
        else if(guess > numberToGuess)
        {
            printf("Too high! You have %d tries left.\n", triesLeft-1);
        }
        else
        {
            isWin = 1; // User guessed correctly
        }

        triesLeft--; // Decrement number of tries left
    }

    // Check if user won or lost
    if(isWin)
    {
        printf("\nCongratulations, you guessed the number %d!\n", numberToGuess);
    }
    else
    {
        printf("\nSorry, you ran out of tries. The number was %d.\n", numberToGuess);
    }

    return 0;
}