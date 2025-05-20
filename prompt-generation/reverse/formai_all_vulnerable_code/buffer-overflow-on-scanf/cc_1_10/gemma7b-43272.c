//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x, y, i, j, n, m;
    float x1, x2, y1, y2, r, g, b;
    char ch;

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    printf("Enter the number of points: ");
    scanf("%d", &m);

    x1 = -2.0f;
    x2 = 1.0f;
    y1 = -1.0f;
    y2 = 1.0f;

    r = 0.0f;
    g = 1.0f;
    b = 0.0f;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            float z = (x1 + (x2 - x1) * j / (m - 1)) * pow(2.0f, i) + y1 * pow(2.0f, i);
            int iterations = 0;

            while (z * z + y1 * y1 > 4.0f && iterations < 255)
            {
                z = (z * z + y1 * y1) * 0.8f - y1 * 0.8f;
                iterations++;
            }

            x = iterations;
            y = 255 - iterations;

            printf("%c", 32);
            printf("%c", x);
            printf("%c", y);
        }

        printf("\n");
    }

    return 0;
}