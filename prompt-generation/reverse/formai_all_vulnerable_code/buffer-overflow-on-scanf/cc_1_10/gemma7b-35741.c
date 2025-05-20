//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: innovative
#include <stdio.h>
#include <math.h>

int main()
{
    int x, y, i, n;
    float r, g, b, d, x1, x2, y1, y2;

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    r = 255.0f;
    g = 255.0f;
    b = 255.0f;
    d = 0.0f;

    x1 = -1.0f;
    x2 = 1.0f;
    y1 = -1.0f;
    y2 = 1.0f;

    for (i = 0; i < n; i++)
    {
        for (x = (int)x1; x <= (int)x2; x++)
        {
            for (y = (int)y1; y <= (int)y2; y++)
            {
                int iterations = 0;
                for (int j = 0; j < 255; j++)
                {
                    float x_c = x + d * j / 255.0f;
                    float y_c = y;
                    float z = 0.0f;
                    while (z < 2.0f && iterations < 255)
                    {
                        float w = z * z + x_c * x_c + y_c * y_c;
                        z = w * w + z;
                        iterations++;
                    }

                    int color = iterations * 2;
                    if (color > 255)
                        color = 255;

                    r = 255 - color;
                    g = color;
                    b = 0;

                    printf("RGB (%d, %d, %d) ", r, g, b);
                }
            }
        }

        printf("\n");
    }

    return 0;
}