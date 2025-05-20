//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20

int main()
{
    char word[MAX_WORD_LENGTH];

    printf("Enter a word: ");
    scanf("%s", word);

    // Check if the word is valid
    if (isWordValid(word))
    {
        printf("The word %s is valid.\n", word);
    }
    else
    {
        printf("The word %s is not valid.\n", word);
    }

    return 0;
}

int isWordValid(char *word)
{
    // Check if the word is too short or long
    if (strlen(word) < 3 || strlen(word) > MAX_WORD_LENGTH)
    {
        return 0;
    }

    // Check if the word contains any non-alphabetic characters
    for (int i = 0; i < strlen(word); i++)
    {
        if (!isalnum(word[i]))
        {
            return 0;
        }
    }

    // Check if the word contains any repeated letters
    for (int i = 0; i < strlen(word); i++)
    {
        int letterCount = 0;
        for (int j = 0; j < strlen(word); j++)
        {
            if (word[i] == word[j])
            {
                letterCount++;
            }
        }

        if (letterCount > 1)
        {
            return 0;
        }
    }

    return 1;
}