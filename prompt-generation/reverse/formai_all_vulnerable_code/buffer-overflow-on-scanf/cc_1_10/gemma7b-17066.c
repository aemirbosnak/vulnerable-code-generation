//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20

int main()
{
    char word[MAX_WORD_LENGTH];
    int i, word_length;

    printf("Enter a word: ");
    scanf("%s", word);

    word_length = strlen(word);

    for (i = 0; i < word_length; i++)
    {
        if (!isalnum(word[i]))
        {
            printf("Error: Invalid character in word.\n");
            return 1;
        }
    }

    if (word_length < 3)
    {
        printf("Error: Word must have at least 3 letters.\n");
        return 1;
    }

    // Check if word is in the dictionary
    if (is_word(word))
    {
        printf("Word is valid.\n");
    }
    else
    {
        printf("Word is not valid.\n");
    }

    return 0;
}

int is_word(char *word)
{
    // Check if word is in the dictionary
    // (This function would normally return 1 if the word is in the dictionary, 0 otherwise)
    return 1;
}