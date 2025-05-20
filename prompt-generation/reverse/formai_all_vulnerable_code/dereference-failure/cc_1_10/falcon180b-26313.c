//Falcon-180B DATASET v1.0 Category: Text processing ; Style: sophisticated
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char *remove_punctuations(char *word)
{
    char *p;
    int len = strlen(word);
    char *result = (char *)malloc(len+1);

    for(p=word; *p; p++)
    {
        if(!isalpha(*p))
        {
            continue;
        }
        *result = tolower(*p);
        result++;
    }

    *result = '\0';
    return result;
}

int main()
{
    FILE *fp;
    char ch, word[100];
    char *result = NULL;
    int count = 0, len;

    fp = fopen("input.txt", "r");

    if(fp == NULL)
    {
        printf("Error opening file.\n");
        exit(0);
    }

    while((ch = fgetc(fp))!= EOF)
    {
        if(isalpha(ch))
        {
            strcat(word, &ch);
        }
        else
        {
            result = remove_punctuations(word);
            len = strlen(result);

            if(len > 0)
            {
                count++;
                printf("%s - %d\n", result, count);
            }

            memset(word, 0, sizeof(word));
        }
    }

    if(strlen(word) > 0)
    {
        result = remove_punctuations(word);
        len = strlen(result);

        if(len > 0)
        {
            count++;
            printf("%s - %d\n", result, count);
        }
    }

    fclose(fp);
    free(result);
    return 0;
}