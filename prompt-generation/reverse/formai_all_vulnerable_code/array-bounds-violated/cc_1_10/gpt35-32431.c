//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

// Function to convert all characters in a string to lowercase
void toLowercase(char *str)
{
    while(*str)
    {
        *str = tolower(*str);
        str++;
    }
}

int main()
{
    char text[MAX_SIZE];
    char *wordList[MAX_SIZE/2];
    int freqList[MAX_SIZE/2] = {0};     // Initialize all elements to 0
    int wordCount = 0, i, j;

    printf("Enter the text: ");
    fgets(text, MAX_SIZE, stdin);       // Read input from user

    // Remove newline character at the end
    if(text[strlen(text)-1] == '\n')
        text[strlen(text)-1] = '\0';

    toLowercase(text);                  // Convert all characters to lowercase

    // Split text into words and count frequency
    char *token = strtok(text, " ,.?;:!-");
    while(token != NULL)
    {
        for(i=0; i<wordCount; i++)
        {
            if(strcmp(token, wordList[i]) == 0)     // If word already exists in array
            {
                freqList[i]++;
                break;
            }
        }
        if(i == wordCount)                          // If word does not exist in array
        {
            wordList[wordCount] = strdup(token);
            freqList[wordCount] = 1;
            wordCount++;
        }
        token = strtok(NULL, " ,.?;:!-");
    }

    // Bubble sort the arrays in descending order of frequency
    int tempFreq;
    char *tempWord;
    for(i=0; i<wordCount-1; i++)
    {
        for(j=0; j<wordCount-i-1; j++)
        {
            if(freqList[j] < freqList[j+1])
            {
                // Swap the frequency element
                tempFreq = freqList[j];
                freqList[j] = freqList[j+1];
                freqList[j+1] = tempFreq;

                // Swap the corresponding word element
                tempWord = wordList[j];
                wordList[j] = wordList[j+1];
                wordList[j+1] = tempWord;
            }
        }
    }

    // Print the results
    printf("\nWord frequency in descending order:\n");
    for(i=0; i<wordCount; i++)
    {
        printf("%s: %d\n", wordList[i], freqList[i]);
        free(wordList[i]);      // Free memory allocated by strdup
    }
    return 0;
}