//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ascii_art(char **arr, int n, int m)
{
    if (n == 0)
    {
        for (int i = 0; i < m; i++)
        {
            printf("%c ", arr[0][i]);
        }
        printf("\n");
    }
    else
    {
        ascii_art(arr, n - 1, m);

        for (int i = 0; i < m; i++)
        {
            printf("%c ", arr[n][i]);
        }
        printf("\n");
    }
}

int main()
{
    char **arr = NULL;
    int n = 0, m = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    arr = (char **)malloc(n * sizeof(char *) + 1);

    for (int i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(m * sizeof(char) + 1);
    }

    printf("Enter the characters: ");
    ascii_art(arr, n, m);

    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }

    free(arr);

    return 0;
}