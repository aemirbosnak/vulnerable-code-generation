//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x, y, i, j, n, m;
    double dx, dy, c, r, x1, x2, y1, y2;

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    x1 = -2.5;
    x2 = 1.0;
    y1 = -1.0;
    y2 = 1.0;

    dx = (x2 - x1) / n;
    dy = (y2 - y1) / n;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            c = 0.0;
            r = dx * i + x1;
            y = dy * j + y1;

            for (m = 0; m < 255; m++)
            {
                if (c > 1.0)
                    break;

                x = r + dx * m;
                y = y + dy * m;

                c += sqrt(x * x + y * y);
            }

            if (c < 1.0)
                printf("%c ", 255 - (int)(255 * c));
            else
                printf("%c ", 0);
        }

        printf("\n");
    }

    return 0;
}