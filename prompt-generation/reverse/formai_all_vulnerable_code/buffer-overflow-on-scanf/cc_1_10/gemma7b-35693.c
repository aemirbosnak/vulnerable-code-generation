//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: lively
#include <stdio.h>
#include <math.h>

int main()
{
    int x, y, i, j, n, m;
    double dx, dy, x1, x2, y1, y2, r, a, b, c;

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    printf("Enter the fractal dimension: ");
    scanf("%d", &m);

    x1 = -2.0;
    x2 = 1.0;
    y1 = -1.0;
    y2 = 1.0;

    dx = (x2 - x1) / n;
    dy = (y2 - y1) / n;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            r = x1 + i * dx;
            a = y1 + j * dy;

            c = 0.0;
            for (int k = 0; k < 255; k++)
            {
                if (c > 2.0)
                    break;

                b = pow(r, 2) + pow(a, 2);
                c = c + b;
            }

            if (c < 2.0)
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