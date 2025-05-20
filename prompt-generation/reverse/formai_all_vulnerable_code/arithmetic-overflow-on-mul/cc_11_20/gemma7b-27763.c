//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: Cryptic
#include <stdio.h>
#include <math.h>

int main()
{
    int x, y, i, n, m;
    double dx, dy, d, x1, x2, y1, y2;

    scanf("%d", &n);
    m = 2 * n + 1;

    x1 = -1.5 * n;
    x2 = 1.5 * n;
    y1 = -1.5 * n;
    y2 = 1.5 * n;

    dx = (x2 - x1) / m;
    dy = (y2 - y1) / m;

    for (i = 0; i < n; i++)
    {
        for (y = 0; y < n; y++)
        {
            d = 0.0;
            for (x = 0; x < m; x++)
            {
                for (y = 0; y < m; y++)
                {
                    if (x == 0 || y == 0)
                    {
                        d += 1.0;
                    }
                    else
                    {
                        if (x == m - 1 || y == m - 1)
                        {
                            d += 1.0;
                        }
                        else
                        {
                            if (x == 0 && y == 0)
                            {
                                d += 1.0;
                            }
                        }
                    }
                }
            }
            if (d > 1.0)
            {
                printf("X");
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }

    return 0;
}