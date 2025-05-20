//Gemma-7B DATASET v1.0 Category: Data mining ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
    char **arr = NULL;
    int i, j, n, m, k, count = 0;
    char keyword[20];

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    arr = (char **)malloc(n * m * sizeof(char *));

    for (i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(m * sizeof(char));
    }

    printf("Enter the data: ");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%c", &arr[i][j]);
        }
    }

    printf("Enter the keyword: ");
    scanf("%s", keyword);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            k = 0;
            while (arr[i][j] != '\0' && k < MAX)
            {
                if (arr[i][j] == keyword[k])
                {
                    count++;
                }
                k++;
            }
        }
    }

    printf("The number of occurrences of the keyword is: %d", count);

    return 0;
}