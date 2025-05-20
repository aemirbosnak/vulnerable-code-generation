//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x, y, i, j, n, m;
    double dx, dy, x1, x2, y1, y2, r, g, b, a;

    printf("Enter number of iterations: ");
    scanf("%d", &n);

    printf("Enter number of points: ");
    scanf("%d", &m);

    x1 = -1.5;
    x2 = 1.5;
    y1 = -1.0;
    y2 = 1.0;

    dx = (x2 - x1) / m;
    dy = (y2 - y1) / m;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            r = 0.0;
            g = 0.0;
            b = 0.0;

            a = 0.0;
            for (x = x1; x <= x2; x += dx)
            {
                for (y = y1; y <= y2; y += dy)
                {
                    if (Mandelbrot(x, y) > a)
                    {
                        r = 255.0;
                        g = 0.0;
                        b = 0.0;
                        a = Mandelbrot(x, y);
                    }
                }
            }

            printf("RGB: (%d, %d, %d)\n", (int)r, (int)g, (int)b);
        }
    }

    return 0;
}

int Mandelbrot(double x, double y)
{
    int i, iter = 0;
    double z, w, c_r, c_i, z_r, z_i;

    c_r = x;
    c_i = y;

    z = 0.0;
    w = 0.0;

    for (i = 0; z < 2.0 && iter < 255; i++)
    {
        z_r = z * z + w * w - c_r;
        z_i = 2 * z * w - c_i;
        w = z_r;
        z = z_i;
        iter++;
    }

    return iter;
}