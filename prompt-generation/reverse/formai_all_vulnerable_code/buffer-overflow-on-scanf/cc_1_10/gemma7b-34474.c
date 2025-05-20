//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: mathematical
#include <stdio.h>
#include <math.h>

int main()
{
    int x, y, i, j, n, m;
    float a, b, c, d, e, f, g, h;

    printf("Enter number of iterations: ");
    scanf("%d", &n);

    printf("Enter number of points: ");
    scanf("%d", &m);

    a = -1.5f;
    b = 1.5f;
    c = -1.0f;
    d = 1.0f;
    e = 0.0f;
    f = 0.0f;
    g = 0.0f;
    h = 0.0f;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            x = (int) (a + f * j / m);
            y = (int) (c + g * i / n);

            if (x >= 0 && x < m && y >= 0 && y < n)
            {
                int z = abs(x) + abs(y);

                if (z % 2 == 0)
                {
                    printf(" ");
                }
                else
                {
                    printf("#");
                }
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}