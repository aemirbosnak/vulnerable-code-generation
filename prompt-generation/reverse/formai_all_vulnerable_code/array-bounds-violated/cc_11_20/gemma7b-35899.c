//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    char str[1000];
    int i, count = 0, flag = 0;
    printf("Enter your text: ");
    fgets(str, 1000, stdin);

    // Removing punctuation and converting to lowercase
    for (i = 0; str[i] != '\0'; i++)
    {
        if (ispunct(str[i]) || str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = '\0';
        }
        str[i] = tolower(str[i]);
    }

    // Counting words and checking for common spam words
    char *words[] = {"free", "lottery", "miracle", "prize", "golden", "offer"};
    for (i = 0; i < 5; i++)
    {
        if (strstr(str, words[i]) != NULL)
        {
            count++;
        }
    }

    // Checking for suspicious formatting
    if (str[0] == '$' || str[0] == '#')
    {
        flag = 1;
    }

    // Checking for repeated words
    char *wordList[100];
    int wordIndex = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (wordList[wordIndex] == NULL)
        {
            wordList[wordIndex] = str[i];
            wordIndex++;
        }
        else if (wordList[wordIndex - 1] == str[i])
        {
            count++;
        }
    }

    // Final decision
    if (count > 5 || flag == 1)
    {
        printf("Your text may contain spam. Please review your text and try again.\n");
    }
    else
    {
        printf("Your text is clean. Enjoy!\n");
    }

    return 0;
}