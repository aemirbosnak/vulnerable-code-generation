//FormAI DATASET v1.0 Category: Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to simulate a player's turn
void playerTurn(char *word, char *guessed)
{
    char guess;
    printf("\nGuess a letter: ");
    scanf(" %c", &guess);
    // Check if input is a valid letter
    if ((guess < 'a' || guess > 'z') && (guess < 'A' || guess > 'Z'))
    {
        printf("Invalid input. Please guess a letter.\n");
        playerTurn(word, guessed);
        return;
    }
    // Check if letter has already been guessed
    if (strchr(guessed, guess) != NULL)
    {
        printf("You already guessed that letter. Please guess a different letter.\n");
        playerTurn(word, guessed);
        return;
    }
    // Check if letter is in word
    if (strchr(word, guess) != NULL)
    {
        printf("Good guess!\n");
        // Add letter to list of guessed letters
        strncat(guessed, &guess, 1);
        // Print word with guessed letters filled in
        for (int i = 0; i < strlen(word); i++)
        {
            if (strchr(guessed, word[i]) != NULL)
            {
                printf("%c ", word[i]);
            }
            else
            {
                printf("_ ");
            }
        }
        // Check if player has won
        if (strspn(guessed, word) == strlen(word))
        {
            printf("\nCongratulations! You win!\n");
            return;
        }
        playerTurn(word, guessed);
    }
    else 
    {
        printf("Incorrect guess. Please try again.\n");
        // Add letter to list of guessed letters
        strncat(guessed, &guess, 1);
        // Print word with guessed letters filled in
        for (int i = 0; i < strlen(word); i++)
        {
            if (strchr(guessed, word[i]) != NULL)
            {
                printf("%c ", word[i]);
            }
            else
            {
                printf("_ ");
            }
        }
        playerTurn(word, guessed);
    }
}

// Function to select a random word from an array of words
int selectWord(char *words[], int length)
{
    srand(time(0));
    return rand() % length;
}

int main()
{
    char *words[] = {"programming", "computer", "language", "debug", "testing", "algorithm", "variable", "memory", "binary", "logic"};
    int length = sizeof(words) / sizeof(words[0]);
    int index = selectWord(words, length);
    char *word = words[index];
    int wordLength = strlen(word);
    char guessed[wordLength + 1];
    memset(guessed, '_', wordLength);
    guessed[wordLength] = '\0';
    printf("Guess the word: ");
    for (int i = 0; i < strlen(word); i++)
    {
        printf("_ ");
    }
    playerTurn(word, guessed);
    return 0;
}