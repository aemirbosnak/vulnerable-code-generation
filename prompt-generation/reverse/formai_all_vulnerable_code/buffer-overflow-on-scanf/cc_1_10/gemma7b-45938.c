//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: protected
#include <stdio.h>
#include <math.h>

int main()
{
    int x, y, i, n;
    float x1, x2, y1, y2, r, g, b, d;

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    x1 = -2.0f;
    x2 = 1.0f;
    y1 = -1.0f;
    y2 = 1.0f;

    r = 0.6f;
    g = 0.2f;
    b = 0.2f;

    for (i = 0; i < n; i++)
    {
        for (x = (int)x1; x <= (int)x2; x++)
        {
            for (y = (int)y1; y <= (int)y2; y++)
            {
                d = 0.0f;
                for (int k = 0; k < 2; k++)
                {
                    float x_c = x + k / 2.0f * 0.01f;
                    float y_c = y + k / 2.0f * 0.01f;
                    float z = 0.0f;
                    int iter = 0;
                    while (z < 2.0f && iter < 255)
                    {
                        float w = x_c * x_c + y_c * y_c + z;
                        z = w * w + z;
                        iter++;
                    }
                    d += iter;
                }
                if (d > 0)
                {
                    printf("(");
                    printf("%d, ", d);
                    printf("), ");
                }
            }
        }
    }

    printf("\n");

    return 0;
}