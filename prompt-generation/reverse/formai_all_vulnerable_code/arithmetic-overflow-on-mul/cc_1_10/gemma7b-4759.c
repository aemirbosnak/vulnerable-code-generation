//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x, y, i, n, m, p, q;
    float dx, dy, x1, x2, y1, y2, r, g, b;

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    printf("Enter the number of points: ");
    scanf("%d", &m);

    printf("Enter the radius of the fractal: ");
    scanf("%f", &r);

    x1 = -r;
    x2 = r;
    y1 = -r;
    y2 = r;

    dx = (x2 - x1) / m;
    dy = (y2 - y1) / m;

    for (i = 0; i < n; i++)
    {
        for (p = 0; p < m; p++)
        {
            for (q = 0; q < m; q++)
            {
                x = x1 + p * dx;
                y = y1 + q * dy;

                if (x * x + y * y <= r * r)
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

        printf("\n");
    }

    return 0;
}