//Gemma-7B DATASET v1.0 Category: Text processing ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **arr = NULL;
    int i = 0, j = 0, k = 0, n = 0, m = 0, count = 0;
    char str[1000] = "";

    printf("Enter the number of lines: ");
    scanf("%d", &n);

    arr = (char **)malloc(n * sizeof(char *));

    for (i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(100 * sizeof(char));
    }

    printf("Enter the lines: ");

    for (i = 0; i < n; i++)
    {
        gets(arr[i]);
    }

    printf("Enter the number of words: ");
    scanf("%d", &m);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            char word[20] = "";
            int flag = 0;

            printf("Enter the word: ");
            scanf("%s", word);

            for (k = 0; k < count; k++)
            {
                if (strcmp(word, arr[k]) == 0)
                {
                    flag = 1;
                }
            }

            if (flag == 0)
            {
                arr[k] = word;
                count++;
            }
        }
    }

    printf("The words are: ");

    for (i = 0; i < count; i++)
    {
        printf("%s ", arr[i]);
    }

    free(arr);

    return 0;
}