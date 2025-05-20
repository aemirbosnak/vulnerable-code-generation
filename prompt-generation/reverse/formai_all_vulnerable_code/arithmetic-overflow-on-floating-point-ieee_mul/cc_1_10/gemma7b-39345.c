//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x, y, i, j, n, m, r, g, b, h, w, d;
    double xx, yy, dx, dy, x1, x2, y1, y2, xo, yo, zoom;
    char c;

    system("clear");

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    printf("Enter the fractal type (H, C, S): ");
    scanf(" %c", &c);

    switch (c)
    {
        case 'H':
            h = 1;
            w = 1;
            break;
        case 'C':
            h = 2;
            w = 1;
            break;
        case 'S':
            h = 1;
            w = 2;
            break;
        default:
            printf("Invalid fractal type.\n");
            return 1;
    }

    zoom = 1.0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            xx = x1 + dx * i;
            yy = y1 + dy * j;

            r = (int)(xx * w) % h;
            g = (int)(yy * w) % h;
            b = 255 - r - g;

            printf("\x1b[38;2;%d;%dm ", r, g, b);
            printf(" ");
        }

        printf("\n");
    }

    return 0;
}