//Gemma-7B DATASET v1.0 Category: Digital signal processing ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n, i, k, x, y, z;
    float a, b, c, d, e, f, g, h, w;

    printf("Enter the number of samples: ");
    scanf("%d", &n);

    w = (float)n;
    x = (int)(w * 0.8);
    y = (int)(w * 0.2);
    z = x - y;

    a = 0.5;
    b = 1.0;
    c = 2.0;
    d = 3.0;
    e = 4.0;
    f = 5.0;
    g = 6.0;
    h = 7.0;

    for (i = 0; i < n; i++)
    {
        k = i;
        if (k < x)
        {
            z = (int)(a * k);
        }
        else if (k < y)
        {
            z = (int)(b * k);
        }
        else if (k < z)
        {
            z = (int)(c * k);
        }
        else if (k < w)
        {
            z = (int)(d * k);
        }
        else
        {
            z = (int)(e * k);
        }

        printf("%d ", z);
    }

    printf("\n");

    return;
}