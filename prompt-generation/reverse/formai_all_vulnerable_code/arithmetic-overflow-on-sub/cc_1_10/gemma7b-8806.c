//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char **arr = NULL;
    int n, m, i, j, k, l, r, h;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    arr = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(m * sizeof(char));
    }

    printf("Enter the height of the ASCII art: ");
    scanf("%d", &h);

    r = h - 1;
    l = h - 1;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            for (k = 0; k < h; k++)
            {
                arr[i][j] = '*';
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            for (k = 0; k < h; k++)
            {
                printf("%c", arr[i][j]);
            }
            printf("\n");
        }
    }

    free(arr);

    return 0;
}