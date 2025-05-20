//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 10000

typedef struct Word
{
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: %s <input file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *inputFile = fopen(argv[1], "r");

    if(inputFile == NULL)
    {
        printf("Error opening input file\n");
        exit(EXIT_FAILURE);
    }

    Word words[MAX_NUM_WORDS];
    int numWords = 0;

    char currentWord[MAX_WORD_LENGTH];

    while(fscanf(inputFile, "%s", currentWord) != EOF)
    {
        // Remove any non-alphanumeric characters from the word
        int length = strlen(currentWord);
        int j = 0;
        for(int i = 0; i < length; i++)
        {
            if(isalnum(currentWord[i]))
            {
                currentWord[j++] = tolower(currentWord[i]);
            }
        }
        currentWord[j] = '\0';

        // If the word is not empty, add it to the array of words
        if(strlen(currentWord) > 0)
        {
            int found = 0;
            for(int i = 0; i < numWords; i++)
            {
                if(strcmp(words[i].word, currentWord) == 0)
                {
                    words[i].count++;
                    found = 1;
                    break;
                }
            }
            if(!found)
            {
                strcpy(words[numWords].word, currentWord);
                words[numWords].count = 1;
                numWords++;
            }
        }
    }

    fclose(inputFile);

    printf("Word frequency count of %s:\n\n", argv[1]);

    for(int i = 0; i < numWords; i++)
    {
        printf("%-15s%d\n", words[i].word, words[i].count);
    }

    return 0;
}