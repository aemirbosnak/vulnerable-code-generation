//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: mind-bending
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    printf("Enter a word: ");
    scanf("%s", str);

    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
        i++;
    }

    int j = 0;
    char word[100];
    word[j] = str[0];
    j++;

    for (i = 1; str[i] != '\0'; i++)
    {
        if (str[i] != str[i - 1])
        {
            word[j] = str[i];
            j++;
        }
    }

    word[j] = '\0';

    int k = 0;
    char dictionary[100][100];
    dictionary[k][0] = 'a';
    dictionary[k][1] = 'b';
    dictionary[k][2] = 'c';
    k++;

    for (i = 0; dictionary[i][0] != '\0'; i++)
    {
        if (strcmp(word, dictionary[i]) == 0)
        {
            printf("Word is in the dictionary.\n");
            break;
        }
    }

    if (strcmp(word, dictionary[i]) != 0)
    {
        printf("Word is not in the dictionary.\n");
    }

    return 0;
}