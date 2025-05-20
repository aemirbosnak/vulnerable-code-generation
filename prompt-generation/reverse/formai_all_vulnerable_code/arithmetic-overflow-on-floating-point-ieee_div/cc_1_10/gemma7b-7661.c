//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x, y, i, j, n, m, z;
    long int seed;
    double dx, dy, x1, x2, y1, y2, c;

    seed = rand() / 2;
    srand(seed);

    n = rand() % 10 + 1;
    m = rand() % 10 + 1;

    x1 = -1.5 + (double)n / n;
    x2 = 1.5 + (double)n / n;
    y1 = -1.5 + (double)m / m;
    y2 = 1.5 + (double)m / m;

    dx = (x2 - x1) / n;
    dy = (y2 - y1) / m;

    c = 0.01 * rand() / seed;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            z = 0;
            x = x1 + i * dx;
            y = y1 + j * dy;

            for (z = 0; z < 255; z++)
            {
                if (x * x + y * y - c * z < 0)
                    break;
            }

            if (z == 255)
                printf(" ");
            else
                printf("%c", 240 - z);
        }
        printf("\n");
    }

    return 0;
}