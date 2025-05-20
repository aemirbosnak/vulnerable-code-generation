//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[100];
    printf("Enter a string: ");
    gets(str);

    int i = 0;
    while (str[i] != '\0')
    {
        if (!isalnum(str[i]))
        {
            str[i] = '\0';
        }
        i++;
    }

    char word[20];
    printf("Enter a word: ");
    gets(word);

    int j = 0;
    while (word[j] != '\0')
    {
        if (!isalnum(word[j]))
        {
            word[j] = '\0';
        }
        j++;
    }

    int flag = 0;
    for (int k = 0; str[k] != '\0'; k++)
    {
        if (strcmp(str + k, word) == 0)
        {
            flag = 1;
        }
    }

    if (flag == 1)
    {
        printf("The word '%s' is found in the string '%s'.\n", word, str);
    }
    else
    {
        printf("The word '%s' is not found in the string '%s'.\n", word, str);
    }

    return 0;
}