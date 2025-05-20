//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: surprised
#include <stdio.h>
#include <math.h>

int main()
{
    int x, y, i, j, n, m;
    double dx, dy, r, g, b, x1, x2, y1, y2;

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    printf("Enter the number of points: ");
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
            r = x1 + j * dx;
            g = y1 + i * dy;

            for (x = 0; x < m; x++)
            {
                for (y = 0; y < n; y++)
                {
                    if (Mandelbrot(r, g) == 0)
                    {
                        printf(" ");
                    }
                    else
                    {
                        printf("#");
                    }
                }
            }

            printf("\n");
        }
    }

    return 0;
}

int Mandelbrot(double x, double y)
{
    int i, j, count = 0;

    for (i = 0; i < 255; i++)
    {
        for (j = 0; j < 255; j++)
        {
            double z = x + (j / 255.0) * 2.0;
            double w = y + (i / 255.0) * 2.0;

            if (MandelbrotPoint(z, w) == 0)
            {
                count++;
            }
        }
    }

    return count;
}

int MandelbrotPoint(double z, double w)
{
    int iter = 0;

    while (iter < 255 && z * z + w * w < 4)
    {
        double tmp = z * z + w * w;
        z = w * w + tmp * z;
        w = tmp * w;
        iter++;
    }

    return iter;
}