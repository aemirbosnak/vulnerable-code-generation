//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int main()
{
    char str[MAX];
    int i, count = 0, word_count = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    // Convert the string into a lowercase array
    char lower_str[MAX];
    for (i = 0; str[i] != '\0'; i++)
    {
        lower_str[i] = str[i] - 32;
    }

    // Find the words in the string
    char word[MAX];
    word_count = 0;
    for (i = 0; lower_str[i] != '\0'; i++)
    {
        word[i] = lower_str[i];
        if (word[i] == ' ' || word[i] == '\n')
        {
            word_count++;
        }
    }

    // Count the frequency of each word
    int word_freq[word_count];
    for (i = 0; i < word_count; i++)
    {
        word_freq[i] = 0;
    }
    for (i = 0; str[i] != '\0'; i++)
    {
        char word_lower[MAX];
        word_lower[0] = str[i] - 32;
        for (int j = 0; word_lower[j] != '\0'; j++)
        {
            word_freq[word_count - 1] += 1;
        }
    }

    // Print the word frequency
    printf("Word frequency:\n");
    for (i = 0; i < word_count; i++)
    {
        printf("%s: %d\n", word[i], word_freq[i]);
    }

    return 0;
}