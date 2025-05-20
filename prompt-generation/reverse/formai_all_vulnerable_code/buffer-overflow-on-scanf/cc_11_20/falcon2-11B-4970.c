//Falcon2-11B DATASET v1.0 Category: Spell checking ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char word[100];
    int i, j, k, flag, count, pos, found;
    char dictionary[100][100];

    printf("Enter a word: ");
    scanf("%s", word);

    flag = 0;
    count = 0;

    printf("Dictionary:\n");
    for (i = 0; i < 100; i++)
    {
        for (j = 0; j < 100; j++)
            dictionary[i][j] = '\0';
    }
    fflush(stdin);

    printf("Enter words in the dictionary: ");
    for (i = 0; i < 100; i++)
    {
        scanf("%s", dictionary[i]);
        fflush(stdin);
    }
    fflush(stdin);

    pos = 0;
    found = 0;

    for (i = 0; i < strlen(word); i++)
    {
        for (j = 0; j < strlen(dictionary[pos]); j++)
        {
            if (word[i] == dictionary[pos][j])
            {
                flag = 1;
                found = 1;
                break;
            }
        }
        if (flag == 0)
        {
            count++;
            pos++;
            if (pos == strlen(dictionary))
                pos = 0;
        }
    }
    if (found == 1)
        printf("The word '%s' is found in the dictionary.\n", word);
    else
        printf("The word '%s' is not found in the dictionary.\n", word);

    if (count > 0)
        printf("The word '%s' is not found in the dictionary.\n", word);
    else
        printf("The word '%s' is found in the dictionary.\n", word);

    return 0;
}