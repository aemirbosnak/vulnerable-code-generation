//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char str[] = "This is a string with some words. The words are repeated several times. And there are some numbers too.";

    int i = 0;
    int word_count = 0;
    char word[20];

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            word_count++;
            word[0] = '\0';
        }
        else
        {
            word[i - word_count] = str[i];
        }
    }

    word_count++;
    int frequency[word_count];

    for (i = 0; i < word_count; i++)
    {
        frequency[i] = 0;
    }

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            int j = 0;
            for (j = 0; word[j] != '\0'; j++)
            {
                if (str[i] == word[j])
                {
                    frequency[j]++;
                }
            }
        }
    }

    int max_frequency = 0;
    for (i = 0; i < word_count; i++)
    {
        if (frequency[i] > max_frequency)
        {
            max_frequency = frequency[i];
        }
    }

    printf("The most frequent word is: %s with a frequency of %d\n", word[max_frequency - 1], max_frequency);
}