//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

void main()
{
    char str[MAX];
    printf("Enter a string: ");
    gets(str);

    int len = strlen(str);
    int i, count = 0;
    char word[MAX];

    for (i = 0; i < len; i++)
    {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
        {
            word[count] = str[i - 1];
            count++;
        }
    }

    int word_count = count;
    char most_frequent[MAX];
    int max_count = 0;

    for (i = 0; i < word_count; i++)
    {
        int occurrences = 0;
        for (int j = 0; j < word_count; j++)
        {
            if (strcmp(word[i], word[j]) == 0)
            {
                occurrences++;
            }
        }

        if (occurrences > max_count)
        {
            max_count = occurrences;
            most_frequent[i] = word[i];
        }
    }

    printf("Most frequent word: %s\n", most_frequent[0]);
    printf("Number of occurrences: %d\n", max_count);
}