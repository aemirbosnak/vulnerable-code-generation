//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 100
#define MAX_WORD_LENGTH 20

int main()
{
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int i = 0, j = 0;

    printf("Enter the file name: ");
    scanf("%s", line);

    FILE *fp = fopen(line, "r");

    if (fp == NULL)
    {
        printf("File not found.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL)
    {
        i = 0;
        while (line[i]!= '\0')
        {
            if (isalpha(line[i]))
            {
                strcat(word, tolower(line[i]));
                i++;
            }
            else
            {
                if (strlen(word) > 0)
                {
                    printf("%s ", word);
                    strcpy(word, "");
                }
                i++;
            }
        }
        if (strlen(word) > 0)
        {
            printf("%s\n", word);
        }
    }

    fclose(fp);

    return 0;
}