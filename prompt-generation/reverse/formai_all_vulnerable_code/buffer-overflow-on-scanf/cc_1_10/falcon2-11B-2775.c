//Falcon2-11B DATASET v1.0 Category: Math exercise ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 10
int generateRandomNumber()
{
    return rand() % 11 + 1;
}

// Function to check if a player's guess is correct
int checkGuess(int guess, int computerGuess)
{
    if (guess == computerGuess)
    {
        return 1; // Player guessed correctly
    }
    else
    {
        return 0; // Player guessed incorrectly
    }
}

// Function to determine if a player has won or lost
int determineWinner(int playerGuess, int computerGuess)
{
    if (checkGuess(playerGuess, computerGuess))
    {
        printf("Player wins!\n");
        return 1; // Player wins
    }
    else if (playerGuess == computerGuess)
    {
        printf("It's a tie!\n");
        return 2; // Tie
    }
    else
    {
        printf("Computer wins!\n");
        return 3; // Computer wins
    }
}

// Main function to run the game
int main()
{
    int playerGuess, computerGuess;

    // Generate a random number for the computer's turn
    computerGuess = generateRandomNumber();

    // Prompt the player to guess a number
    printf("Guess a number between 1 and 10: ");
    scanf("%d", &playerGuess);

    // Determine the winner
    int winner = determineWinner(playerGuess, computerGuess);

    // Print the result
    if (winner == 1)
    {
        printf("Player wins!\n");
    }
    else if (winner == 2)
    {
        printf("It's a tie!\n");
    }
    else
    {
        printf("Computer wins!\n");
    }

    return 0;
}