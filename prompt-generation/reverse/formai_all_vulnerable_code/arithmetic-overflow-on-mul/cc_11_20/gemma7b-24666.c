//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, h, w, r, b, x, y;
    char ch;

    printf("Enter the number of rows: ");
    scanf("%d", &h);

    printf("Enter the number of columns: ");
    scanf("%d", &w);

    printf("Enter the character to be drawn: ");
    scanf(" %c", &ch);

    l = h * w;
    m = l / 2;
    x = w / 2;
    y = h / 2;

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            if (i == y && j == x)
            {
                printf("%c", ch);
            }
            else if (i < y && j < x)
            {
                printf("%c", ch);
            }
            else if (i > y && j < x)
            {
                printf("%c", ch);
            }
            else if (i > y && j > x)
            {
                printf("%c", ch);
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}