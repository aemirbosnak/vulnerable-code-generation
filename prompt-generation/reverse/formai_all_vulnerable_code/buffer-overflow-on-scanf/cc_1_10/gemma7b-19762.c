//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x, y, i, n, m;
    float x1, x2, y1, y2, r, g, b;

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    printf("Enter the number of points: ");
    scanf("%d", &m);

    x1 = -1.5f;
    x2 = 1.5f;
    y1 = -1.0f;
    y2 = 1.0f;

    r = 0.0f;
    g = 0.0f;
    b = 1.0f;

    for (i = 0; i < m; i++)
    {
        x = rand() % (int)(x2 - x1) + x1;
        y = rand() % (int)(y2 - y1) + y1;

        for (int j = 0; j < n; j++)
        {
            float distance = sqrtf(x * x + y * y);

            if (distance < 2.0f)
            {
                r = 255.0f - distance * 255.0f;
                g = distance * 255.0f;
                b = 0.0f;
            }
            else
            {
                r = 0.0f;
                g = 0.0f;
                b = 255.0f;
            }

            printf("%d %d %d\n", (int)r, (int)g, (int)b);
        }
    }

    return 0;
}