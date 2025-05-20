//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: lively
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1024

int main()
{
    char str[MAX];
    int i, j, k, l, flag = 0, word_count = 0;
    printf("Enter a string: ");
    scanf("%s", str);

    // Convert str to lowercase
    for (i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower(str[i]);
    }

    // Split str into words
    char *word = strtok(str, " ");
    while (word)
    {
        word_count++;
        word = strtok(NULL, " ");
    }

    // Check for misspelled words
    for (i = 0; i < word_count; i++)
    {
        int word_length = strlen(word);
        for (j = 0; j < word_length; j++)
        {
            // Check if letter is not alphabetical
            if (!isalnum(word[j]))
            {
                flag = 1;
            }
        }

        // Check if word length is too short or long
        if (word_length < 3 || word_length > 15)
        {
            flag = 1;
        }

        // Check if word is a common misspelling
        if (strcmp(word, "their") == 0 || strcmp(word, "there") == 0 || strcmp(word, "they're") == 0)
        {
            flag = 1;
        }

        // If flag is 1, word is misspelled
        if (flag)
        {
            printf("Word '%s' is misspelled.\n", word);
        }

        flag = 0;
        word = strtok(NULL, " ");
    }

    // Print the number of words in the string
    printf("Number of words in the string: %d\n", word_count);

    return 0;
}