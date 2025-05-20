//FormAI DATASET v1.0 Category: Word Count Tool ; Style: retro
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50

int main(void)
{
    char sentence[500];
    int wordCount = 0;
    printf("Enter a sentence: ");
    fgets(sentence, 500, stdin);

    int length = strlen(sentence);
    if (sentence[length - 1] == '\n')
    {
        sentence[length - 1] = '\0';
    }

    // Convert sentence to lowercase
    for (int i = 0; sentence[i]; i++)
    {
        sentence[i] = tolower(sentence[i]);
    }

    // Initialize array to store unique words
    char words[MAX_WORD_LENGTH][MAX_WORD_LENGTH];
    int frequency[MAX_WORD_LENGTH];
    for (int i = 0; i < MAX_WORD_LENGTH; i++)
    {
        frequency[i] = 0;
    }

    // Extract words from sentence
    char *token = strtok(sentence, " ");
    while (token)
    {
        // Check if word already exists in array
        int existingIndex = -1;
        for (int i = 0; i < MAX_WORD_LENGTH; i++)
        {
            if (strcmp(words[i], token) == 0)
            {
                existingIndex = i;
                break;
            }
        }

        // If word is new, add it to array
        if (existingIndex == -1)
        {
            strcpy(words[wordCount], token);
            frequency[wordCount] = 1;
            wordCount++;
        }
        // If word already exists, increment its frequency count
        else
        {
            frequency[existingIndex]++;
        }

        token = strtok(NULL, " ");
    }

    // Print unique words and their frequency count
    printf("\nWord Count Tool Results:\n");
    printf("-------------------------\n");
    for (int i = 0; i < wordCount; i++)
    {
        printf("%s: %d\n", words[i], frequency[i]);
    }

    return 0;
}