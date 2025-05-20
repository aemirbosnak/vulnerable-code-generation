//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: active
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int x, y, i, n, m;
    double dx, dy, cx, cy, r, theta;

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    printf("Enter the number of points: ");
    scanf("%d", &m);

    dx = 2.0 / (double)m;
    dy = 2.0 / (double)m;

    for (x = 0; x < m; x++)
    {
        for (y = 0; y < m; y++)
        {
            cx = -1.0 + dx * (double)x;
            cy = 1.0 - dy * (double)y;
            r = 0.0;

            for (i = 0; i < n; i++)
            {
                theta = r * 2.0 * M_PI;
                x = (int) (cx + r * cos(theta));
                y = (int) (cy + r * sin(theta));

                if (x >= 0 && x < m && y >= 0 && y < m)
                {
                    r = 1.0;
                }
            }

            if (r == 1.0)
            {
                printf(" ");
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