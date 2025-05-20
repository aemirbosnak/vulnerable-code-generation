//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: brave
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20

int main()
{
    char word[MAX_WORD_LENGTH];
    int i, word_length, is_word_valid = 0;

    printf("Enter a word: ");
    scanf("%s", word);

    word_length = strlen(word);

    for (i = 0; i < word_length; i++)
    {
        // Check if the character is alphabetical
        if (!isalnum(word[i]))
        {
            is_word_valid = 1;
            break;
        }
    }

    // Check if the word is too long or short
    if (word_length < 3 || word_length > MAX_WORD_LENGTH)
    {
        is_word_valid = 1;
    }

    // Check if the word contains a vowel
    for (i = 0; i < word_length; i++)
    {
        // Check if the character is a vowel
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            is_word_valid = 1;
            break;
        }
    }

    // Check if the word is valid
    if (is_word_valid)
    {
        printf("The word is not valid.\n");
    }
    else
    {
        printf("The word is valid.\n");
    }

    return 0;
}