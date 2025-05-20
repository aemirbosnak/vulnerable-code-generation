//Falcon-180B DATASET v1.0 Category: Sorting ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 1000
#define MAX_WORDS 10000

struct word{
    char *word;
    int freq;
};

int compare(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}

int main()
{
    FILE *file;
    char ch;
    char word[100];
    int count=0;
    struct word words[MAX_WORDS];
    char *text = malloc(MAX_SIZE);
    int i=0;
    int j=0;

    file = fopen("sherlock.txt", "r");

    if(file == NULL)
    {
        printf("Error opening file\n");
        exit(0);
    }

    while((ch = fgetc(file))!= EOF)
    {
        if(isalpha(ch))
        {
            word[0] = ch;
            word[1] = '\0';
            while(isalpha(ch))
            {
                strcat(word, &ch);
                ch = fgetc(file);
            }
            words[j].word = strdup(word);
            words[j].freq = 1;
            j++;
        }
        else
        {
            if(isdigit(ch))
            {
                word[0] = ch;
                word[1] = '\0';
                while(isdigit(ch))
                {
                    strcat(word, &ch);
                    ch = fgetc(file);
                }
                words[j].word = strdup(word);
                words[j].freq = 1;
                j++;
            }
            else if(isspace(ch))
            {
                continue;
            }
            else
            {
                printf("Error parsing file\n");
                exit(0);
            }
        }
    }

    fclose(file);

    qsort(words, j, sizeof(struct word), compare);

    for(i=0; i<j; i++)
    {
        printf("%s %d\n", words[i].word, words[i].freq);
    }

    free(text);
    for(i=0; i<j; i++)
    {
        free(words[i].word);
    }
    return 0;
}