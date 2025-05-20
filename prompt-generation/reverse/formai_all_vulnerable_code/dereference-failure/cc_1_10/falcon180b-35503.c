//Falcon-180B DATASET v1.0 Category: File handling ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct
{
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int compareWords(const void *a, const void *b)
{
    Word *word1 = (Word *)a;
    Word *word2 = (Word *)b;

    return strcmp(word1->word, word2->word);
}

int main()
{
    FILE *inputFile, *outputFile;
    char inputFileName[50], outputFileName[50];
    char line[1000];
    char word[MAX_WORD_LENGTH];
    Word words[MAX_WORDS];
    int numWords = 0;
    int i;

    printf("Enter the name of the input file: ");
    scanf("%s", inputFileName);

    inputFile = fopen(inputFileName, "r");

    if(inputFile == NULL)
    {
        printf("Error opening input file.\n");
        exit(1);
    }

    printf("Enter the name of the output file: ");
    scanf("%s", outputFileName);

    outputFile = fopen(outputFileName, "w");

    if(outputFile == NULL)
    {
        printf("Error opening output file.\n");
        exit(1);
    }

    while(fgets(line, sizeof(line), inputFile)!= NULL)
    {
        int wordStart = 0;
        int wordEnd = 0;

        for(i = 0; i < strlen(line); i++)
        {
            if(isalpha(line[i]))
            {
                if(wordStart == 0)
                {
                    wordStart = i;
                }
            }
            else
            {
                if(wordStart!= 0)
                {
                    wordEnd = i;
                    break;
                }
            }
        }

        if(wordStart!= 0)
        {
            strncpy(word, &line[wordStart], wordEnd - wordStart);
            word[wordEnd - wordStart] = '\0';

            for(i = 0; i < numWords; i++)
            {
                if(strcmp(words[i].word, word) == 0)
                {
                    words[i].count++;
                    break;
                }
            }

            if(i == numWords)
            {
                strcpy(words[numWords].word, word);
                words[numWords].count = 1;
                numWords++;
            }
        }
    }

    qsort(words, numWords, sizeof(Word), compareWords);

    for(i = 0; i < numWords; i++)
    {
        fprintf(outputFile, "%s: %d\n", words[i].word, words[i].count);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}