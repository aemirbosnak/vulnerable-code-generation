//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, i, j, k, l, r, x, y, z;
    float a, b, c, d, e, f, g, h, w, h_max, v_max, min_dist;

    printf("Enter the number of vertices:");
    scanf("%d", &n);

    h_max = 0.0;
    v_max = 0.0;
    min_dist = 1000000.0;

    for (i = 0; i < n; i++)
    {
        printf("Enter the coordinates of vertex %d:", i + 1);
        scanf("%f %f", &x, &y);

        a = x;
        b = y;

        h = sqrt(a * a + b * b);

        if (h_max < h)
        {
            h_max = h;
        }

        if (v_max < h)
        {
            v_max = h;
        }

        for (j = 0; j < i; j++)
        {
            c = x - a;
            d = y - b;

            e = sqrt(c * c + d * d);

            if (min_dist > e)
            {
                min_dist = e;
            }
        }
    }

    printf("The maximum height is: %.2f\n", h_max);
    printf("The maximum vertical distance is: %.2f\n", v_max);
    printf("The minimum distance between vertices is: %.2f\n", min_dist);

    return 0;
}