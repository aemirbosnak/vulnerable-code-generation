//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// Function to count frequency of words in a file
void wordFrequency(FILE * fp)
{
    char word[100];
    int count = 0;
    char ch;
    int i = 0;
    char c;
    // Declare an array of Strings to store frequency of each word
    char **words = (char **)malloc(5 * sizeof(char*));
    for(i = 0; i < 5; i++)
        words[i] = (char *)malloc(100 * sizeof(char));

    printf("The Words and their Frequency are as Follows\n");
    while((ch = fgetc(fp)) != EOF)
    {
        if(isalpha(ch))
        {
            word[i++] = ch;
        }
        else if((ch == ' ')||(ch == '\n')||(ch == '\t'))
        {
            word[i] = '\0';
            i = 0;
            for(int j = 0; j < count; j++)
            {
                if(strcmp(words[j], word) == 0)
                {
                    count++;
                    goto end;
                }
            }
            strcpy(words[count], word);
            count++;
            end:
            memset(word, 0, sizeof(word));
        }
    }
    // Print the frequency of each word
    for(int i = 0; i < count; i++)
        printf("%s : %d\n", words[i], i + 1);
}

int main()
{
    FILE * fp;
    char filename[100]; 
    
    // Open a file to read using user input
    printf("Enter the filename to read the word frequency: ");
    scanf("%s", filename);

    fp = fopen(filename, "r"); // Open the file in read mode
    if(fp == NULL)
    {
        printf("File Doesn't Exist\n");
        exit(0);
    }
    wordFrequency(fp);
    fclose(fp);
    return 0;
}