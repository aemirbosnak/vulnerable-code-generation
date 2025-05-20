//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20

int main()
{
    char word[MAX_WORD_LENGTH];
    char dictionary[MAX_WORD_LENGTH][MAX_WORD_LENGTH];
    int dictionarySize = 0;
    int i, j, k, found = 0;

    // Load the dictionary
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp)
    {
        while (fscanf(fp, "%s", dictionary[dictionarySize]) != EOF)
        {
            dictionarySize++;
        }
        fclose(fp);
    }

    // Get the word to check
    printf("Enter a word: ");
    scanf("%s", word);

    // Check if the word is in the dictionary
    for (i = 0; i < dictionarySize; i++)
    {
        for (j = 0; dictionary[i][j] != '\0'; j++)
        {
            if (strcmp(word, dictionary[i]) == 0)
            {
                found = 1;
                break;
            }
        }
    }

    // Print the result
    if (found)
    {
        printf("Word found.\n");
    }
    else
    {
        printf("Word not found.\n");
    }

    return 0;
}