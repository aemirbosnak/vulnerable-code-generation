//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: mathematical
#include <stdio.h>
#include <math.h>

int main()
{
    int x, y, i, j, n, m;
    float x1, x2, y1, y2, r, g, b;

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    printf("Enter the number of points: ");
    scanf("%d", &m);

    x1 = -2.0f;
    x2 = 1.0f;
    y1 = -1.0f;
    y2 = 1.0f;

    r = 0.6f;
    g = 0.2f;
    b = 0.2f;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            float z = (x1 + (x2 - x1) * j / (m - 1)) * pow(r, i) + x1;
            float w = (y1 + (y2 - y1) * i / (n - 1)) * pow(r, i) + y1;

            int color = 0;

            for (int k = 0; k < 255; k++)
            {
                if (z * z + w * w < 4)
                {
                    color++;
                }
                else
                {
                    break;
                }
            }

            printf("(%d, %d) - %d\n", x, y, color);
        }
    }

    return 0;
}