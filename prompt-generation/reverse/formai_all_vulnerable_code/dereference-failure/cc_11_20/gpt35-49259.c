//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j, k, flag = 0;
    char str[100];

    printf("Enter the number of strings you want to sanitize: ");
    scanf("%d", &n);

    char **strings = (char **)malloc(n * sizeof(char *));
    if (strings == NULL)
    {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter string %d: ", i + 1);
        scanf("%s", str);

        strings[i] = (char *)malloc(strlen(str) * sizeof(char));
        if (strings[i] == NULL)
        {
            printf("Error: Memory allocation failed!\n");
            exit(1);
        }

        strcpy(strings[i], str);
    }

    for (i = 0; i < n; i++)
    {
        k = 0;
        for (j = 0; j < strlen(strings[i]); j++)
        {
            if (strings[i][j] != '<' && strings[i][j] != '>' && strings[i][j] != '\"' && strings[i][j] != '\'' && strings[i][j] != '\\')
            {
                strings[i][k++] = strings[i][j];
            }
            else
            {
                flag = 1;
            }
        }
        strings[i][k] = '\0';

        if (flag)
        {
            printf("String %d has been sanitized as: %s\n", i + 1, strings[i]);
            flag = 0;
        }
        else
        {
            printf("String %d does not contain any invalid characters.\n", i + 1);
        }
    }

    for (i = 0; i < n; i++)
    {
        free(strings[i]);
    }
    free(strings);

    return 0;
}