//Gemma-7B DATASET v1.0 Category: Data mining ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100];
    FILE *fp;

    fp = fopen("data.txt", "r");
    fscanf(fp, "%s", str);
    fclose(fp);

    char *words[100];
    int i = 0;
    words[i] = strtok(str, " ");

    while (words[i] != NULL)
    {
        i++;
        words[i] = strtok(NULL, " ");
    }

    int word_count = i;

    char most_frequent_word[20];
    int max_occurrence = 0;

    for (i = 0; i < word_count; i++)
    {
        int occurrence = 0;
        for (int j = 0; j < word_count; j++)
        {
            if (strcmp(words[i], words[j]) == 0)
            {
                occurrence++;
            }
        }

        if (occurrence > max_occurrence)
        {
            max_occurrence = occurrence;
            strcpy(most_frequent_word, words[i]);
        }
    }

    printf("The most frequent word is: %s\n", most_frequent_word);
    printf("The maximum occurrence is: %d\n", max_occurrence);

    return 0;
}