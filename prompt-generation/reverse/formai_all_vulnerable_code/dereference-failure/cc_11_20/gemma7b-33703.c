//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    int i, j, k;
    char **a = malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {
        a[i] = malloc(n * sizeof(char));
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[i][j] = ' ';
        }
    }

    printf("Enter the character: ");
    char ch;
    scanf("%c", &ch);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] == ' ' && ch != ' ')
            {
                a[i][j] = ch;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++)
    {
        free(a[i]);
    }
    free(a);

    return 0;
}