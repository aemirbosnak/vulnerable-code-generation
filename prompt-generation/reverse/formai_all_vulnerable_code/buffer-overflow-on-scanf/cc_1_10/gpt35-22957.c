//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: lively
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// this function gets the frequency of each word in the given file
void getWordFrequency(char* filename);

// this function counts the occurrence of a word in the given string
int countWordOccurrence(char* str, char* word);

int main()
{
    char filename[100];

    printf("Enter the filename: ");
    scanf("%s", filename);

    getWordFrequency(filename);

    return 0;
}

void getWordFrequency(char* filename)
{
    FILE* file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    char str[100];
    char* words[10000];
    int count[10000] = {0};
    int wordCount = 0;

    while (fscanf(file, "%s", str) != EOF)
    {
        // convert the string to lowercase
        for (int i = 0; str[i]; i++)
        {
            str[i] = tolower(str[i]);
        }

        int wordFound = 0;

        // check if the word already exists in the array of words
        for (int i = 0; i < wordCount; i++)
        {
            if (strcmp(str, words[i]) == 0)
            {
                count[i]++;
                wordFound = 1;
                break;
            }
        }

        // if the word is not found in the array of words, add it
        if (!wordFound)
        {
            words[wordCount] = strdup(str);
            count[wordCount] = 1;
            wordCount++;
        }
    }

    fclose(file);

    // sort the words and their frequencies in descending order
    for (int i = 0; i < wordCount - 1; i++)
    {
        for (int j = 0; j < wordCount - i - 1; j++)
        {
            if (count[j] < count[j+1])
            {
                int tempCount = count[j];
                count[j] = count[j+1];
                count[j+1] = tempCount;

                char* tempWord = words[j];
                words[j] = words[j+1];
                words[j+1] = tempWord;
            }
        }
    }

    // print the word frequency
    printf("Word Frequency\n");
    printf("----------------\n");
    for (int i = 0; i < wordCount; i++)
    {
        printf("%s: %d\n", words[i], count[i]);
    }

    // get the occurrence of a specific word
    char searchWord[100];
    printf("\nEnter a word to search: ");
    scanf("%s", searchWord);

    int occurrence = countWordOccurrence(filename, searchWord);

    printf("%s occurs %d times in the file.\n", searchWord, occurrence);
}

int countWordOccurrence(char* filename, char* word)
{
    FILE* file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    char str[100];
    int occurrence = 0;

    while (fscanf(file, "%s", str) != EOF)
    {
        // convert the string to lowercase
        for (int i = 0; str[i]; i++)
        {
            str[i] = tolower(str[i]);
        }

        // check if the word matches the string
        if (strcmp(str, word) == 0)
        {
            occurrence++;
        }
    }

    fclose(file);

    return occurrence;
}