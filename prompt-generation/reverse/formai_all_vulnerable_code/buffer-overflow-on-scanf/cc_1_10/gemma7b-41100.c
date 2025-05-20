//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: protected
#include <stdio.h>
#include <math.h>

int main()
{
    int x, y, i, j, n, m;
    double px, py, r, g, b;

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    printf("Enter the number of points: ");
    scanf("%d", &m);

    px = -1.5;
    py = -1.0;
    r = 0.6;
    g = 0.6;
    b = 0.6;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            int z = 0;
            for (x = -n / 2; x < n / 2; x++)
            {
                for (y = -n / 2; y < n / 2; y++)
                {
                    double c_r = px + x * r;
                    double c_i = py + y * r;
                    double z_value = 0.0;

                    for (int k = 0; k < 255; k++)
                    {
                        if (z_value > 2)
                        {
                            break;
                        }
                        z_value = sqrt(c_r * c_r + c_i * c_i) + z;
                        z++;
                    }

                    if (z == 255)
                    {
                        printf(" ");
                    }
                    else
                    {
                        printf("%c", 32 + z);
                    }
                }
            }
            printf("\n");
        }
    }

    return 0;
}