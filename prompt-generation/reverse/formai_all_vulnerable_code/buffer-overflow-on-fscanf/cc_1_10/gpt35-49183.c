//FormAI DATASET v1.0 Category: Spell checking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    printf("Welcome to the Spell Checker!\n");
    printf("Enter a word to check: ");

    char word[50];
    scanf("%s", word);

    int len = strlen(word);

    for(int i = 0; i < len; i++){
        if(isdigit(word[i]))
        {
            printf("ERROR: The word contains numbers!\n");
            return 0;
        }
    }

    char dictionary[1000][50];
    FILE *fp;
    fp = fopen("dictionary.txt", "r");
    if(fp == NULL)
    {
        printf("ERROR: Could not open dictionary file.\n");
        return 0;
    }

    int dictSize = 0;
    while(fscanf(fp, "%s", dictionary[dictSize++]) != EOF);

    fclose(fp);

    int found = 0;
    for(int i = 0; i < dictSize; i++)
    {
        if(strcmp(word, dictionary[i]) == 0){
            printf("The word is spelled correctly!\n");
            found = 1;
            break;
        }
    }

    if(!found)
        printf("The word is spelled incorrectly!\n");

    return 0;
}