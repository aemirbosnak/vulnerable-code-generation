//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Variables
    int numPlayers, rounds, guessNumber, secretNumber, isGuessing, score, roundScore;

    // Initialize the game
    numPlayers = 2;
    rounds = 5;
    secretNumber = rand() % 100 + 1;
    score = 0;
    roundScore = 0;

    // Game loop
    for (int round = 0; round < rounds; round++)
    {
        // Get the player's guess
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &guessNumber);

        // Check if the guess is correct
        isGuessing = guessNumber == secretNumber;

        // Update the score
        if (isGuessing)
        {
            roundScore = 10;
            score += roundScore;
            printf("You guessed the number! You get 10 points.\n");
        }
        else
        {
            roundScore = 0;
            printf("Sorry, that's not the number. Try again.\n");
        }

        // Print the round score
        printf("Your round score is: %d\n", roundScore);

        // Print the total score
        printf("Your total score is: %d\n", score);
    }

    // End of game
    printf("Thank you for playing! See you next time.\n");

    return 0;
}