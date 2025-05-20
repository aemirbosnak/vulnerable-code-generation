//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 20

int main()
{
    char word[MAX_WORD_LENGTH];
    char dictionary[1000][MAX_WORD_LENGTH];
    int dictionarySize = 0;
    char query[MAX_WORD_LENGTH];

    // Load the dictionary
    FILE *dictFile = fopen("dictionary.txt", "r");
    if (dictFile)
    {
        char line[MAX_WORD_LENGTH];
        while (fgets(line, MAX_WORD_LENGTH, dictFile) != NULL)
        {
            dictionary[dictionarySize][0] = line[0];
            strcpy(dictionary[dictionarySize][1], line);
            dictionarySize++;
        }
        fclose(dictFile);
    }

    // Get the query word
    printf("Enter a word: ");
    scanf("%s", query);

    // Check if the word is in the dictionary
    int isWordInDictionary = 0;
    for (int i = 0; i < dictionarySize; i++)
    {
        if (strcmp(query, dictionary[i][1]) == 0)
        {
            isWordInDictionary = 1;
            break;
        }
    }

    // Print the result
    if (isWordInDictionary)
    {
        printf("The word %s is in the dictionary.\n", query);
    }
    else
    {
        printf("The word %s is not in the dictionary.\n", query);
    }

    return 0;
}