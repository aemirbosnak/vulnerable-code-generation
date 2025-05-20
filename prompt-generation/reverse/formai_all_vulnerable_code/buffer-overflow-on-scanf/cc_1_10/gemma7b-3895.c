//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: portable
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

int main()
{
    char word[MAX_WORD_LENGTH];

    printf("Enter a word: ");
    scanf("%s", word);

    int length = strlen(word);

    for (int i = 0; i < length; i++)
    {
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            word[i] = word[i] - 32;
        }
    }

    int isValidWord = 0;

    FILE *fp = fopen("dictionary.txt", "r");

    char line[MAX_WORD_LENGTH];

    while (fgets(line, MAX_WORD_LENGTH, fp) != NULL)
    {
        if (strcmp(line, word) == 0)
        {
            isValidWord = 1;
            break;
        }
    }

    fclose(fp);

    if (isValidWord)
    {
        printf("Word is valid.\n");
    }
    else
    {
        printf("Word is not valid.\n");
    }

    return 0;
}