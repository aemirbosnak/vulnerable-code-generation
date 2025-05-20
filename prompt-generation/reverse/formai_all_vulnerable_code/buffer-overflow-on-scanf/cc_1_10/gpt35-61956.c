//FormAI DATASET v1.0 Category: Table Game ; Style: enthusiastic
// Welcome to the amazing game of Code Table! 
// This is a unique and exciting game that is sure to keep you entertained for hours.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between 1-100
int generateRandomNumber()
{
    srand(time(NULL)); // Seed the random number generator with current time
    return (rand() % 100) + 1;
}

// Function to check if player's guess is too high, too low, or correct
int checkGuess(int secretNumber, int guess)
{
    if (guess > secretNumber)
    {
        printf("Too high! Try again.\n");
        return 0;
    }
    else if (guess < secretNumber)
    {
        printf("Too low! Try again.\n");
        return 0;
    }
    else
    {
        printf("Congratulations! You guessed it correctly.\n");
        return 1;
    }
}

// Main function
int main()
{
    int secretNumber, guess;
    int numGuesses = 0;

    // Generate a secret number
    secretNumber = generateRandomNumber();

    printf("\nWelcome to Code Table!\n");
    printf("I am thinking of a number between 1-100, can you guess it?\n");

    do
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        numGuesses++; // Increment number of guesses

    } while (!checkGuess(secretNumber, guess));

    printf("You took %d guesses to find the correct number.\n", numGuesses);

    return 0;
}