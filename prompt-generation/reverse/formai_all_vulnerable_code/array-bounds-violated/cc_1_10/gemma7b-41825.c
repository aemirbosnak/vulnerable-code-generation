//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10
#define MAX_LETTERS 5

typedef struct Word
{
    char letters[MAX_LETTERS];
    int score;
} Word;

Word words[MAX_WORDS] =
{
    {"APPLE", 10},
    {"BANANA", 8},
    {"Orange", 7},
    {"Peach", 9},
    {"Strawberry", 6},
    {"Kiwi", 5},
    {"Mango", 4},
    {"Grape", 3},
    {"Melon", 2},
    {"Watermelon", 1}
};

int main()
{
    srand(time(NULL));

    int guessWordIndex = rand() % MAX_WORDS;

    char guessWord[MAX_LETTERS] = "";

    for (int i = 0; i < MAX_LETTERS; i++)
    {
        guessWord[i] = '_';
    }

    guessWord[MAX_LETTERS - 1] = '\0';

    int guesses = 0;

    while (guessWord[guessWordIndex] != words[guessWordIndex].letters[0] && guesses < MAX_LETTERS)
    {
        char guessLetter = getchar();

        if (guessLetter >= 'a' && guessLetter <= 'z')
        {
            guessWord[guessLetter - 'a'] = guessLetter;

            guesses++;

            if (guessWord[guessWordIndex] == words[guessWordIndex].letters[0])
            {
                printf("Congratulations! You won!\n");
                break;
            }
            else
            {
                printf("Incorrect guess. Try again.\n");
            }
        }
    }

    if (guesses == MAX_LETTERS)
    {
        printf("Sorry, you lost. The word was: %s\n", words[guessWordIndex].letters);
    }

    return 0;
}