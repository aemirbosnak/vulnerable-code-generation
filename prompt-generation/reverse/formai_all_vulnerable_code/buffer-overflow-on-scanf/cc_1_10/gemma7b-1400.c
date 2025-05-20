//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1024

int main()
{
    int x, y, z, i, j, k, l, m, n;
    float r, g, b, d, x1, x2, y1, y2, z1, z2;

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the fractal parameters (r, g, b, d): ");
        scanf("%f %f %f %f", &r, &g, &b, &d);

        x1 = -1.0f - d / 2.0f;
        x2 = 1.0f + d / 2.0f;
        y1 = -1.0f - d / 2.0f;
        y2 = 1.0f + d / 2.0f;
        z1 = -1.0f - d / 2.0f;
        z2 = 1.0f + d / 2.0f;

        for (x = x1; x <= x2; x++)
        {
            for (y = y1; y <= y2; y++)
            {
                z = 0;
                for (k = 0; k < MAX; k++)
                {
                    if (sqrt(x * x + y * y + z * z) < d)
                    {
                        z++;
                    }
                    else
                    {
                        break;
                    }
                }

                printf("%d ", z);
            }
            printf("\n");
        }
    }

    return 0;
}