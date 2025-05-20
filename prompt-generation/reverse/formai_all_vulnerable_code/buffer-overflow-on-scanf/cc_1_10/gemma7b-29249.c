//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

int main()
{
    char word[MAX_WORD_LENGTH];
    int i, j, word_length, flag = 0;

    printf("Enter a word: ");
    scanf("%s", word);

    word_length = strlen(word);

    for (i = 0; i < word_length; i++)
    {
        // Check if the character is alphabetical
        if (!isalnum(word[i]))
        {
            flag = 1;
            break;
        }

        // Check if the character is a vowel
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
        {
            flag = 1;
            break;
        }
    }

    // Check if the word is too long
    if (word_length > MAX_WORD_LENGTH)
    {
        flag = 1;
    }

    // If there are no errors, print the word
    if (!flag)
    {
        printf("Your word is: %s\n", word);
    }
    else
    {
        printf("Error: Invalid word.\n");
    }

    return 0;
}