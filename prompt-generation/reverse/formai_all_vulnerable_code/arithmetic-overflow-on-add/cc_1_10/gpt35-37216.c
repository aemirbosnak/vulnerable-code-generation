//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: light-weight
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

void remove_punctuation(char *str)
{
    char *p = str;
    while (*p)
    {
        if (ispunct((unsigned char)*p))
        {
            memmove(p, p + 1, strlen(p + 1) + 1);
        }
        else
        {
            p++;
        }
    }
}

int main()
{
    char text[MAX_WORD_LENGTH];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int count[MAX_WORDS];
    int n = 0, unique = 0;

    // Get input text
    printf("Enter some text:\n");
    fgets(text, MAX_WORD_LENGTH, stdin);

    // Tokenize input text into words
    char *token = strtok(text, " ");
    while (token)
    {
        strcpy(words[n], token);
        remove_punctuation(words[n]);

        // Check if word is unique
        int i, is_unique = 1;
        for (i = 0; i < unique; i++)
        {
            if (strcmp(words[n], words[i]) == 0)
            {
                is_unique = 0;
                count[i]++;
                break;
            }
        }
        if (is_unique)
        {
            count[unique]++;
            unique++;
        }

        n++;
        if (n >= MAX_WORDS)
            break;

        token = strtok(NULL, " ");
    }

    // Print word count
    printf("\nWord frequency:\n");
    int i;
    for (i = 0; i < unique; i++)
    {
        printf("%s: %d\n", words[i], count[i]);
    }

    return 0;
}