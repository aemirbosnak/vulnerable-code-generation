//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fractal(int x, int y, int zoom, int max_iter)
{
    int i, j, r, g, b;
    double xx, yy, d, cr, ci;

    xx = (double)x / zoom;
    yy = (double)y / zoom;
    cr = xx - 0.5;
    ci = yy - 0.5;

    for (i = 0; i < max_iter; i++)
    {
        d = cr * cr + ci * ci;
        if (d > 4)
            break;

        r = (int)(255 * sqrt(d));
        g = (int)(255 * sqrt(d));
        b = (int)(255 * sqrt(d));

        printf("%d %d %d ", r, g, b);
    }

    printf("\n");
}

int main()
{
    int x, y, zoom, max_iter;

    printf("Enter the number of iterations: ");
    scanf("%d", &max_iter);

    printf("Enter the zoom factor: ");
    scanf("%d", &zoom);

    printf("Enter the x coordinate: ");
    scanf("%d", &x);

    printf("Enter the y coordinate: ");
    scanf("%d", &y);

    fractal(x, y, zoom, max_iter);

    return 0;
}