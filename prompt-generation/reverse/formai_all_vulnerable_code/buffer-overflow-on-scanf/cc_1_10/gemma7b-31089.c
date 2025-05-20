//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

int main()
{
    int x, y, i, j, n;
    double dx, dy, c, r, theta, x1, x2, y1, y2;

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    x1 = -1.5;
    x2 = 1.5;
    y1 = -1.0;
    y2 = 1.0;

    dx = (x2 - x1) / MAX;
    dy = (y2 - y1) / MAX;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            c = 0.0;
            for (x = x1; x <= x2; x += dx)
            {
                for (y = y1; y <= y2; y += dy)
                {
                    r = x + dx * cos(theta) - y * dx * sin(theta);
                    if (r * r + y * y > 4)
                        c = 1.0;
                }
            }

            if (c == 0.0)
            {
                printf(" ");
            }
            else
            {
                printf("*");
            }
        }

        printf("\n");
    }

    return 0;
}