//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

int main()
{
    char text[MAX_WORDS][MAX_WORD_LENGTH], word[MAX_WORD_LENGTH], ch;
    int i, j, k, count;
 
    printf("Enter text: ");
    i = 0;
    while ((ch = getchar()) != EOF && i < MAX_WORDS && ch != '\n')
    {
        if (ch == ' ')
        {
            text[i][j++] = '\0';
            i++;
            j = 0;
        }
        else
        {
            text[i][j++] = ch;
        }
    }
    text[i][j] = '\0';
    int words_count[i+1];
    for (k = 0; k <= i; k++)
    {
        words_count[k] = -1;
    }
    for (k = 0; k <= i; k++)
    {
        strcpy(word, text[k]);
        count = 1;
        for (j = k + 1; j <= i; j++)
        {
            if (strcmp(word, text[j]) == 0)
            {
                count++;
                words_count[j] = 0;
            }
        }
        if (words_count[k] != 0)
        {
            words_count[k] = count;
        }
    }
    printf("\nWord\t\tFrequency\n");
    for (k = 0; k <= i; k++)
    {
        if (words_count[k] != 0)
        {
            printf("%-s\t\t%d\n", text[k], words_count[k]);
        }
    }
    return 0;
}