//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: accurate
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX_WORDS 5000
#define MAX_WORD_LENGTH 20

typedef struct 
{
    char *english;
    char *alien;
} word;

void add_word(word *dict, int *size, char *english, char *alien) 
{
    if (*size >= MAX_WORDS) 
    {
        printf("Dictionary is full.\n");
        return;
    }
    dict[*size].english = strdup(english);
    dict[*size].alien = strdup(alien);
    (*size)++;
}

int load_dictionary(word *dict, int *size, char *filename) 
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) 
    {
        printf("Cannot open file %s.\n", filename);
        return 0;
    }
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) 
    {
        char *english = strtok(line, " ");
        char *alien = strtok(NULL, " ");
        if (english == NULL || alien == NULL) 
        {
            printf("Invalid line in dictionary file: %s\n", line);
            continue;
        }
        add_word(dict, size, english, alien);
    }
    fclose(fp);
    return 1;
}

int main() 
{
    word dict[MAX_WORDS];
    int size = 0;
    load_dictionary(dict, &size, "dictionary.txt");
    char input[MAX_WORD_LENGTH];
    while (1) 
    {
        printf("Enter English word or type 'quit' to exit: ");
        scanf("%s", input);
        if (strcmp(input, "quit") == 0) 
        {
            break;
        }
        int i;
        for (i = 0; i < size; i++) 
        {
            if (strcmp(dict[i].english, input) == 0) 
            {
                printf("Alien language: %s\n", dict[i].alien);
                break;
            }
        }
        if (i == size) 
        {
            printf("No translation found.\n");
        }
    }
    return 0;
}