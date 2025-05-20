//FormAI DATASET v1.0 Category: Spell checking ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#define DICTIONARY "words.txt"

int main(int argc, char* argv[])
{
    // Read dictionary
    char dictionary[10000][50];
    FILE* dict = fopen(DICTIONARY, "r");
    int dictSize = 0;
    while(fgets(dictionary[dictSize], 50, dict) != NULL)
    {
        dictionary[dictSize][strlen(dictionary[dictSize]) - 1] = '\0';
        dictSize++;
    }
    fclose(dict);

    // Read input file
    char input[10000];
    fgets(input, 10000, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // Split input into words
    char* words[10000];
    int numWords = 0;
    char* token = strtok(input, " ");
    while(token != NULL)
    {
        words[numWords] = token;
        numWords++;
        token = strtok(NULL, " ");
    }

    // Check each word against dictionary
    for(int i = 0; i < numWords; i++)
    {
        int found = 0;
        for(int j = 0; j < dictSize; j++)
        {
            if(strcmp(words[i], dictionary[j]) == 0)
            {
                found = 1;
                break;
            }
        }

        if(!found)
        {
            printf("%s is misspelled.\n", words[i]);
        }
    }

    return 0;
}