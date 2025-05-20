//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x, y, i, j, n, m, maxIter = 255;
    double zx, zy, cr, cy, r, g, b;

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    maxIter = n;

    printf("Enter the number of points: ");
    scanf("%d", &m);

    printf("Enter the maximum radius: ");
    scanf("%lf", &r);

    for(i = 0; i < m; i++)
    {
        printf("Enter the x coordinate: ");
        scanf("%d", &x);

        printf("Enter the y coordinate: ");
        scanf("%d", &y);

        zx = (double)x / r;
        zy = (double)y / r;

        for(j = 0; j < maxIter; j++)
        {
            cr = zx * cos(j * 0.01) + zy * cos(j * 0.01);
            cy = zx * sin(j * 0.01) + zy * sin(j * 0.01);

            if(cr * cr + cy * cy < 1)
            {
                r = 0.5 * r;
                g = 0.5 * r;
                b = 0.5 * r;
            }
            else
            {
                r = 0.2 * r;
                g = 0.2 * r;
                b = 0.2 * r;
            }

            printf("RGB values: (%d, %d, %d)\n", (int)r, (int)g, (int)b);
        }
    }

    return 0;
}