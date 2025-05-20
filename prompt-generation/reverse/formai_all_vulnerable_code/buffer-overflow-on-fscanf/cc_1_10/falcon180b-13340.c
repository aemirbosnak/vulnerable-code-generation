//Falcon-180B DATASET v1.0 Category: Educational ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define MAX_WORDS 10000
#define MIN_WORD_LENGTH 3

//function to read words from the file and store in an array
void readWords(char *filename, char *words[])
{
    FILE *fp;
    int i = 0;
    char word[50];
    fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("File not found!");
        exit(0);
    }
    while(fscanf(fp, "%s", word)!= EOF)
    {
        if(strlen(word) >= MIN_WORD_LENGTH)
        {
            strcpy(words[i], word);
            i++;
        }
    }
    fclose(fp);
}

//function to display the words in the array
void displayWords(char *words[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%s ", words[i]);
    }
    printf("\n");
}

//function to sort the words in alphabetical order
void sortWords(char *words[], int n)
{
    int i, j;
    char temp[50];
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(strcmp(words[i], words[j]) > 0)
            {
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }
}

//function to count the frequency of each word
void countWords(char *words[], int n)
{
    int i, j;
    int freq[10000];
    for(i=0; i<n; i++)
    {
        freq[i] = 0;
    }
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(strcmp(words[i], words[j]) == 0)
            {
                freq[i]++;
            }
        }
    }
    for(i=0; i<n; i++)
    {
        printf("%s %d\n", words[i], freq[i]);
    }
}

//function to display the time taken for sorting
void displayTime(double start, double end)
{
    double time_taken;
    time_taken = end - start;
    printf("Time taken for sorting: %.2f seconds\n", time_taken);
}

int main()
{
    char filename[50];
    printf("Enter the name of the input file: ");
    scanf("%s", filename);
    char words[MAX_WORDS][50];
    int n;
    readWords(filename, words);
    n = strlen(words[0]);
    printf("The words in the file are:\n");
    displayWords(words, n);
    printf("The words sorted in alphabetical order are:\n");
    sortWords(words, n);
    displayWords(words, n);
    printf("The frequency of each word is:\n");
    countWords(words, n);
    return 0;
}