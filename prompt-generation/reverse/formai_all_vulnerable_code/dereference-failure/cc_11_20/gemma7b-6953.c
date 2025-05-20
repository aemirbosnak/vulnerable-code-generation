//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, n, i, j, k, l, m, p, q;
    char **a = NULL;
    char ch;

    printf("Enter the number of shapes: ");
    scanf("%d", &n);

    a = (char**)malloc(n * sizeof(char*));
    for (i = 0; i < n; i++)
    {
        a[i] = (char*)malloc(10 * sizeof(char));
    }

    printf("Enter the shapes: ");
    for (i = 0; i < n; i++)
    {
        scanf("%s", a[i]);
    }

    printf("Enter the number of transformations: ");
    scanf("%d", &k);

    for (i = 0; i < k; i++)
    {
        printf("Enter the transformation type: ");
        scanf(" %c", &ch);

        switch (ch)
        {
            case 'a':
                for (j = 0; j < n; j++)
                {
                    for (l = 0; l < 10; l++)
                    {
                        a[j][l] = a[j][l] ^ 0x12;
                    }
                }
                break;
            case 'b':
                for (j = 0; j < n; j++)
                {
                    for (l = 0; l < 10; l++)
                    {
                        a[j][l] = a[j][l] << 1;
                    }
                }
                break;
            case 'c':
                for (j = 0; j < n; j++)
                {
                    for (l = 0; l < 10; l++)
                    {
                        a[j][l] = a[j][l] >> 1;
                    }
                }
                break;
            case 'd':
                for (j = 0; j < n; j++)
                {
                    for (l = 0; l < 10; l++)
                    {
                        a[j][l] = ~a[j][l];
                    }
                }
                break;
            default:
                printf("Invalid transformation type.\n");
                break;
        }
    }

    for (i = 0; i < n; i++)
    {
        free(a[i]);
    }
    free(a);

    return 0;
}