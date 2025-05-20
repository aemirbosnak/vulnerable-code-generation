//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: modular
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
    if (word[0] == '\0' || word[0] == '\n')
    {
        printf("Error: invalid word.\n");
        return 1;
    }

    // Normalize the word
    word[0] = tolower(word[0]);
    for (int i = 1; word[i] != '\0'; i++)
    {
        word[i] = tolower(word[i]);
    }

    // Check if the word is in the dictionary
    int is_word_valid = 0;
    char *dictionary[] = {"apple", "banana", "orange", "grape", "apricot", "mango", "peach", "pear"};
    for (int i = 0; i < 8; i++)
    {
        if (strcmp(word, dictionary[i]) == 0)
        {
            is_word_valid = 1;
            break;
        }
    }

    // Print the results
    if (is_word_valid)
    {
        printf("The word %s is valid.\n", word);
    }
    else
    {
        printf("The word %s is not valid.\n", word);
    }

    return 0;
}