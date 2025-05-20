//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 100

char *largestWord; /* to store the largest word in the file */
int maxCount; /* to store the frequency count of the largest word */

/* Function to count word frequency */
void countFrequency(char *inputFileName)
{
    int wordCount = 0;
    int uniqueWordCount = 0;
    char word[MAX_WORD_LEN];
    FILE *fpIn = fopen(inputFileName, "r");
    if (fpIn == NULL)
    {
        printf("File does not exist.\n");
        exit(0);
    }

    /* Generate and open the output file */
    char outputFileName[MAX_WORD_LEN];
    sprintf(outputFileName, "%s_frequency_count.txt", inputFileName);
    FILE *fpOut = fopen(outputFileName, "w");
    if (fpOut == NULL)
    {
        printf("Error in creating output file.\n");
        exit(0);
    }
    fprintf(fpOut, "Word frequency count for file %s:\n\n", inputFileName);

    /* Read the input file */
    while (fscanf(fpIn, "%s", word) != EOF)
    {
        int len = strlen(word);
        /* Removing punctuations from the word */
        for (int i = 0; i < len; i++)
        {
            if (!isalpha(word[i]))
            {
                for (int j = i; j < len; j++)
                {
                    word[j] = word[j + 1];
                }
                len--;
                i--;
            }
            else
            {
                word[i] = tolower(word[i]);
            }
        }
        if (strlen(word) > 1)
        {
            wordCount++;

            int found = 0;
            /* Counting the frequency of each unique word */
            rewind(fpIn);
            while (fscanf(fpIn, "%s", largestWord) != EOF)
            {
                if (strcasecmp(largestWord, word) == 0)
                {
                    found++;
                    if (found == 1)
                    {
                        uniqueWordCount++;
                    }
                }
            }
            /* Writing the current word with its frequency to the output file */
            fprintf(fpOut, "%s - %d\n", word, found);
            /* Identifying the largest word by frequency */
            if (found > maxCount)
            {
                maxCount = found;
                largestWord = word;
            }
        }
    }
    /* Writing the summary information to the output file */
    fprintf(fpOut, "\nTotal number of words: %d\n", wordCount);
    fprintf(fpOut, "Number of unique words: %d\n", uniqueWordCount);
    fprintf(fpOut, "Largest word by frequency: %s - %d times\n", largestWord, maxCount);

    fclose(fpIn);
    fclose(fpOut);
}

int main()
{
    printf("Enter the input file name: ");
    char inputFileName[MAX_WORD_LEN];
    scanf("%s", inputFileName);
    countFrequency(inputFileName);

    printf("\nWord frequency count generated for file %s.\n", inputFileName);
    return 0;
}