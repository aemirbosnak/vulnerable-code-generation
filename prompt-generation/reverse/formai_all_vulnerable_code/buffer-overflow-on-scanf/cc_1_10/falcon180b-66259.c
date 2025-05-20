//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 80

int main()
{
    FILE *fp;
    char filename[MAX_WORD_LENGTH];
    char *word;
    char *buffer = NULL;
    size_t len = 0;
    ssize_t read;
    int num_words = 0;
    int num_lines = 0;
    int num_chars = 0;
    int i;
    bool found_word = false;
    printf("Enter filename: ");
    scanf("%[^\n]", filename);
    fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Error: File not found\n");
        exit(1);
    }
    while((read = getline(&buffer, &len, fp))!= -1)
    {
        num_lines++;
        num_chars += read;
        word = strtok(buffer, " \t\n\r\f\v");
        while(word!= NULL)
        {
            num_words++;
            if(strlen(word) > MAX_WORD_LENGTH)
            {
                printf("Error: Word too long\n");
                exit(1);
            }
            found_word = true;
            word = strtok(NULL, " \t\n\r\f\v");
        }
        if(!found_word)
        {
            printf("Error: No words found\n");
            exit(1);
        }
        found_word = false;
    }
    if(ferror(fp))
    {
        printf("Error: File read error\n");
        exit(1);
    }
    printf("Number of lines: %d\n", num_lines);
    printf("Number of words: %d\n", num_words);
    printf("Number of characters: %d\n", num_chars);
    fclose(fp);
    return 0;
}