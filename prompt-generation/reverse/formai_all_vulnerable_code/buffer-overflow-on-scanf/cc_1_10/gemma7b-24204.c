//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LIVES 3

int main()
{
    char guessWord[20];
    char playerGuess[20];
    int lives = MAX_LIVES;
    int wordLength;
    int i;

    // Generate a random word
    srand(time(NULL));
    wordLength = rand() % 11 + 5;
    guessWord[wordLength] = '\0';

    // Fill the guess word with random letters
    for (i = 0; i < wordLength; i++)
    {
        guessWord[i] = (rand() % 26) + 'a';
    }

    // Get the player's guess
    printf("Enter your guess: ");
    scanf("%s", playerGuess);

    // Check if the guess is correct
    int isGuessCorrect = 0;
    for (i = 0; i < wordLength; i++)
    {
        if (playerGuess[i] == guessWord[i])
        {
            isGuessCorrect = 1;
        }
    }

    // Check if the player has won or lost
    if (isGuessCorrect)
    {
        printf("Congratulations! You won!");
    }
    else
    {
        printf("Sorry, you lost. The word was: %s", guessWord);
    }

    return 0;
}