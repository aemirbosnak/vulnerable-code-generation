//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, i, j, n, m;
    float dx, dy, d, x1, x2, y1, y2;

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    printf("Enter the dimensions of the fractal (x, y): ");
    scanf("%d %d", &m, &n);

    x1 = -m / 2.0;
    x2 = m / 2.0;
    y1 = -n / 2.0;
    y2 = n / 2.0;

    dx = (x2 - x1) / m;
    dy = (y2 - y1) / n;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            x = x1 + j * dx;
            y = y1 + i * dy;

            d = 0.0;
            for (int k = 0; k < 2; k++)
            {
                if (x + k * dy < x2 && x + k * dy > x1)
                {
                    if (y + k * dx < y2 && y + k * dx > y1)
                    {
                        d = d + 1.0;
                    }
                }
            }

            if (d > 0.5)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }

        printf("\n");
    }

    return 0;
}