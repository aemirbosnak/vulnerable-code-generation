//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

int main(int argc, char *argv[])
{
    FILE *fp;
    char filename[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    int count = 0;
    int word_count = 0;
    int i;
    char *word_list[MAX_WORDS];

    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s", word)!= EOF)
    {
        if (count == MAX_WORDS)
        {
            printf("Maximum number of words reached.\n");
            break;
        }

        for (i = 0; i < count; i++)
        {
            if (strcmp(word, word_list[i]) == 0)
            {
                word_count++;
                break;
            }
        }

        if (i == count)
        {
            word_list[count] = strdup(word);
            count++;
        }
    }

    fclose(fp);

    printf("Number of unique words: %d\n", count);
    printf("Number of occurrences of the most frequent word: %d\n", word_count);

    return 0;
}