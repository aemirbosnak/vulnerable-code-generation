//Falcon-180B DATASET v1.0 Category: File handling ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_LINE_SIZE 1000
#define MAX_WORD_SIZE 50

int main()
{
    char filename[MAX_LINE_SIZE];
    printf("Enter the filename: ");
    scanf("%s", filename);
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file!");
        exit(1);
    }
    int word_count = 0;
    int line_count = 0;
    char word[MAX_WORD_SIZE];
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL)
    {
        line_count++;
        int i = 0;
        while (line[i]!= '\0' && line[i]!= '\n')
        {
            if (isalpha(line[i]))
            {
                word[i] = tolower(line[i]);
                i++;
            }
            else
            {
                i++;
            }
        }
        word[i] = '\0';
        if (strlen(word) > 0)
        {
            word_count++;
        }
    }
    printf("Total number of lines: %d\n", line_count);
    printf("Total number of words: %d\n", word_count);
    fclose(fp);
    return 0;
}