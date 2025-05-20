//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, i, n, m, z;
    float r, g, b, d;
    FILE *fp;

    fp = fopen("fractal.txt", "w");

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    printf("Enter the number of points: ");
    scanf("%d", &m);

    r = 0.0f;
    g = 0.0f;
    b = 0.0f;

    for (i = 0; i < n; i++)
    {
        for (y = 0; y < m; y++)
        {
            z = 0;
            for (x = 0; x < m; x++)
            {
                if (z > 255)
                {
                    r = 255.0f;
                    g = 255.0f;
                    b = 255.0f;
                }
                else
                {
                    d = (float)z / 255.0f;
                    r = d * 255.0f;
                    g = d * 255.0f;
                    b = 0.0f;
                }

                fprintf(fp, "%d, %d, %d, %f\n", x, y, z, r);
                z++;
            }
        }
    }

    fclose(fp);

    return 0;
}