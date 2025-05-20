//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000];
    char word[50][100];
    int count[50] = {0};
    int i, j, k, len, words;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    len = strlen(str);

    if (str[len - 1] == '\n')
        str[len - 1] = '\0';

    words = 0;
    j = 0;
    for (i = 0; i <= len; i++)
    {
        if (str[i] == ' ' || str[i] == '\0')
        {
            word[words][j] = '\0';
            words++;
            j = 0;
        }
        else
        {
            word[words][j] = str[i];
            j++;
        }
    }

    for (i = 0; i < words; i++)
    {
        for (j = 0; j < words; j++)
        {
            if (i == j)
                continue;

            if (strcmp(word[i], word[j]) == 0)
            {
                count[i]++;
            }
        }
    }

    printf("\nWord Count\n");
    for (i = 0; i < words; i++)
    {
        int flag = 0;
        for (j = 0; j < i; j++)
        {
            if (strcmp(word[i], word[j]) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
            printf("%s: %d\n", word[i], count[i] + 1);
    }

    return 0;
}