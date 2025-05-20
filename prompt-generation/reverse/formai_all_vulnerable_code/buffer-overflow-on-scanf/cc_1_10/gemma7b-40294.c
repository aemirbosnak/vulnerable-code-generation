//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ascii_art(char **arr, int n, int i, int j)
{
    if (i >= n - 1)
    {
        return 0;
    }

    if (j >= n - 1)
    {
        ascii_art(arr, n, i + 1, 0);
    }

    printf("%c ", arr[i][j]);

    ascii_art(arr, n, i, j + 1);

    return 0;
}

int main()
{
    char **arr = NULL;
    int n = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    arr = (char **)malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(n * sizeof(char));
    }

    printf("Enter the number of columns: ");
    scanf("%d", &n);

    printf("Enter the characters: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%c", &arr[i][j]);
        }
    }

    ascii_art(arr, n, 0, 0);

    return 0;
}