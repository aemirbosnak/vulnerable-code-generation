//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: irregular
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100

char words[MAX_WORDS][MAX_WORDS];

int main()
{
    int i, j, k, word_count = 0, found = 0;
    char word[MAX_WORDS];

    // Load the dictionary
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp)
    {
        while (fscanf(fp, "%s", words[word_count]) != EOF)
        {
            word_count++;
        }
        fclose(fp);
    }

    // Get the word to check
    printf("Enter a word: ");
    scanf("%s", word);

    // Search for the word in the dictionary
    for (i = 0; i < word_count; i++)
    {
        for (j = 0; words[i][j] != '\0'; j++)
        {
            if (strcmp(word, words[i]) == 0)
            {
                found = 1;
                break;
            }
        }
    }

    // Print the result
    if (found)
    {
        printf("Word found.\n");
    }
    else
    {
        printf("Word not found.\n");
    }

    return 0;
}