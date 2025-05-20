//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count frequency of each word
void countWordFreq(char* sentence)
{
    char* token;
    char* delimiters = " ,.;:\"(){}[]!?-_\n\t";
    int wordCount = 0;
    int freq[100], index = 0;

    // Initialize frequency array
    for(int i = 0; i < 100; i++)
    {
        freq[i] = 0;
    }

    // Loop through sentence and count frequency of each word
    token = strtok(sentence, delimiters);
    while(token != NULL)
    {
        wordCount++;

        // Check if word is already in array
        int isAlreadyInArray = 0;
        for(int i = 0; i < index; i++)
        {
            if(strcmp(token, sentence[i]) == 0)
            {
                freq[i]++;
                isAlreadyInArray = 1;
                break;
            }
        }

        // Add word to array if not already in array
        if(!isAlreadyInArray)
        {
            freq[index] = 1;
            strcpy(sentence[index++], token);
        }

        token = strtok(NULL, delimiters);
    }

    // Print results
    printf("Word count: %d\n\n", wordCount);
    printf("Word\t\tFrequency\n");
    for(int i = 0; i < index; i++)
    {
        printf("%s\t\t%d\n", sentence[i], freq[i]);
    }
}

int main()
{
    printf("Welcome to the word frequency counter!\n\n");

    // Get sentence from user
    char sentence[1000];
    printf("Enter a sentence (max. 1000 characters):\n");
    fgets(sentence, 1000, stdin);

    // Remove newline character
    sentence[strlen(sentence)-1] = '\0';

    printf("\nCalculating word frequency...\n\n");

    // Count frequency of each word
    countWordFreq(sentence);

    printf("\nThank you for using the word frequency counter!\n");

    return 0;
}