//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **arr = NULL;
    int n = 0, m = 0, i = 0, j = 0, k = 0;

    printf("Enter the number of rows:");
    scanf("%d", &n);

    printf("Enter the number of columns:");
    scanf("%d", &m);

    arr = (char **)malloc(n * sizeof(char *));

    for(i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(m * sizeof(char));
    }

    printf("Enter the characters:");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%c", &arr[i][j]);
        }
    }

    printf("The ASCII art is:");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            free(arr[i][j]);
        }
        free(arr[i]);
    }

    free(arr);

    return 0;
}