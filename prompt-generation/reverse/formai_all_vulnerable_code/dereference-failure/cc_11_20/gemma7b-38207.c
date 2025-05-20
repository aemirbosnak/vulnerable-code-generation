//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r, c, i, j, k;
    char **a = NULL;
    char b[256];

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &r, &c);

    a = (char **)malloc(r * sizeof(char *) + 1);
    for (i = 0; i < r; i++)
    {
        a[i] = (char *)malloc(c * sizeof(char) + 1);
    }

    printf("Enter the image data (each pixel as a number): ");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d ", &k);
            a[i][j] = k;
        }
    }

    printf("Converting image to ASCII art...\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            switch (a[i][j])
            {
                case 0:
                    b[0] = '\0';
                    break;
                case 1:
                    b[0] = '.';
                    break;
                case 2:
                    b[0] = ' ';
                    break;
                case 3:
                    b[0] = '+';
                    break;
                case 4:
                    b[0] = '*';
                    break;
                case 5:
                    b[0] = '#';
                    break;
            }
            printf("%c", b[0]);
        }
        printf("\n");
    }

    free(a);

    return 0;
}