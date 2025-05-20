//FormAI DATASET v1.0 Category: Spell checking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORD_LENGTH 100
#define MAX_DICT_WORDS 1000

//Function to read dictionary and store it in a 2D character array
void readDictionary(char dictionary[][MAX_WORD_LENGTH], int *numWords)
{
    FILE *fp;
    fp = fopen("dictionary.txt", "r");
    if(fp == NULL)
    {
        printf("Error: File not found");
        exit(0);
    }
    char word[MAX_WORD_LENGTH];
    int i=0;

    while(fscanf(fp, "%s", word) == 1 && i<MAX_DICT_WORDS)
    {
        strcpy(dictionary[i], word);
        i++;
    }
    *numWords = i;
    fclose(fp);
}

//Function to calculate Levenshtein distance between two strings
int levenshteinDistance(char *s1, char *s2)
{
    int m = strlen(s1);
    int n = strlen(s2);

    int dp[m+1][n+1];

    for(int i=0;i<=m;i++)
        dp[i][0] = i;

    for(int j=0;j<=n;j++)
        dp[0][j] = j;

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                int replace = dp[i-1][j-1] + 1;
                int insert = dp[i][j-1] + 1;
                int remove = dp[i-1][j] + 1;
                int min = replace < insert ? replace : insert;
                min = remove < min ? remove : min;
                dp[i][j] = min;
            }
        }
    }

    return dp[m][n];
}

//Function to check the spelling of a word
void checkSpelling(char *word, char dictionary[][MAX_WORD_LENGTH], int numWords)
{
    int minDistance = MAX_WORD_LENGTH;
    char suggestedWord[MAX_WORD_LENGTH] = "\0";

    for(int i=0;i<numWords;i++)
    {
        int distance = levenshteinDistance(word, dictionary[i]);
        if(distance < minDistance)
        {
            minDistance = distance;
            strcpy(suggestedWord, dictionary[i]);
        }
    }

    if(minDistance == 0)
    {
        printf("%s is spelled correctly.\n", word);
    }
    else
    {
        printf("Did you mean %s?\n", suggestedWord);
    }
}

int main()
{
    char dictionary[MAX_DICT_WORDS][MAX_WORD_LENGTH];
    int numWords = 0;

    printf("Reading dictionary from file...\n");
    readDictionary(dictionary, &numWords);
    printf("Dictionary read successfully!\n");

    while(1)
    {
        char word[MAX_WORD_LENGTH];
        printf("Enter a word (or 'q' to quit): ");
        scanf("%s", word);
        if(strcmp(word, "q") == 0)
        {
            break;
        }
        checkSpelling(word, dictionary, numWords);
    }

    return 0;
}