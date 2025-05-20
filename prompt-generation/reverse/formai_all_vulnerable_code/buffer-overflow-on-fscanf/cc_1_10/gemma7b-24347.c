//Gemma-7B DATASET v1.0 Category: Data mining ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[1000];
    FILE *fp;
    fp = fopen("data.txt", "r");
    fscanf(fp, "%s", str);
    fclose(fp);

    char *ptr = str;
    char **words = NULL;
    int i = 0;
    int word_count = 0;

    while (ptr)
    {
        char *word = strtok(ptr, " ");
        if (word)
        {
            words = realloc(words, (word_count + 1) * sizeof(char *));
            words[word_count++] = word;
        }
        ptr = strtok(NULL, " ");
    }

    int frequency[word_count];
    for (i = 0; i < word_count; i++)
    {
        frequency[i] = 0;
        for (int j = 0; j < word_count; j++)
        {
            if (words[i] == words[j])
            {
                frequency[i]++;
            }
        }
    }

    int most_frequent = 0;
    for (i = 0; i < word_count; i++)
    {
        if (frequency[i] > most_frequent)
        {
            most_frequent = frequency[i];
        }
    }

    printf("Most frequent word: %s", words[most_frequent - 1]);

    return 0;
}