//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: all-encompassing
#include <stdio.h>
#include <math.h>

int main()
{
    int x, y, i, j, n, m;
    double dx, dy, c, r, x1, x2, y1, y2;

    printf("Enter number of iterations: ");
    scanf("%d", &n);

    printf("Enter number of points: ");
    scanf("%d", &m);

    dx = 1.0 / m;
    dy = 1.0 / m;

    x1 = -2.0;
    x2 = 1.0;
    y1 = -1.0;
    y2 = 1.0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            c = 0.0;
            for (x = x1; x <= x2; x += dx)
            {
                for (y = y1; y <= y2; y += dy)
                {
                    r = x + 0.5 * cos(y);
                    c += abs(r) * dx * dy;
                }
            }

            if (c > 255)
            {
                printf("%c ", 255);
            }
            else
            {
                printf("%c ", (int)c);
            }
        }

        printf("\n");
    }

    return 0;
}