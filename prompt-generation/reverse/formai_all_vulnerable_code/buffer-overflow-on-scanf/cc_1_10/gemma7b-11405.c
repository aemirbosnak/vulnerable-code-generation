//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x, y, i, n, m, k;
    float r, g, b, x1, x2, y1, y2;

    printf("Enter number of iterations: ");
    scanf("%d", &n);

    x1 = -2.5f;
    x2 = 1.5f;
    y1 = -1.0f;
    y2 = 1.0f;

    for (i = 0; i < n; i++)
    {
        printf("Generation %d:\n", i + 1);

        for (x = x1; x <= x2; x++)
        {
            for (y = y1; y <= y2; y++)
            {
                k = 0;
                m = 0;

                for (int j = 0; j < 255; j++)
                {
                    if (abs(x * x + y * y - 1) < 0.01)
                    {
                        k++;
                    }
                    if (k > m)
                    {
                        m = k;
                    }
                }

                printf("%d ", m);
            }
            printf("\n");
        }

        printf("\n");
    }

    return 0;
}