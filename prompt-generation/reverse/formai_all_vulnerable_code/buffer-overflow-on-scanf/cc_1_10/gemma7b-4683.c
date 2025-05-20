//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1024

int main()
{
    int x, y, i, j, k, l, m, n, r, g, b, a, f, e, h;
    double xx, yy, d, dx, dy, rrr, theta;

    system("clear");

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    dx = dy = d = 1.0;
    theta = 0.0;

    for (i = 0; i < n; i++)
    {
        for (x = -MAX/2; x < MAX/2; x++)
        {
            for (y = -MAX/2; y < MAX/2; y++)
            {
                rrr = 0.0;
                for (k = 0; k < MAX; k++)
                {
                    xx = x + dx * cos(theta) * k;
                    yy = y + dy * sin(theta) * k;

                    if (xx * xx + yy * yy < rrr)
                    {
                        rrr = xx * xx + yy * yy;
                    }
                }

                if (rrr < MAX)
                {
                    printf("%c", 219);
                }
                else
                {
                    printf("%c", 32);
                }
            }
        }
        printf("\n");
    }

    return 0;
}