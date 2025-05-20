//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fractal(int x1, int y1, int x2, int y2, int depth)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int pdx = dx / 2;
    int pdy = dy / 2;

    if (depth == 0)
    {
        printf("*");
        return;
    }

    fractal(x1, y1, x1 + pdx, y1 + pdy, depth - 1);
    fractal(x1 + pdx, y1, x2, y1 + pdy, depth - 1);
    fractal(x2, y1 + pdy, x2, y2, depth - 1);
    fractal(x1, y1 + pdy, x1, y2, depth - 1);
}

int main()
{
    int width, height, x1, y1, x2, y2;

    printf("Enter the width of the image: ");
    scanf("%d", &width);

    printf("Enter the height of the image: ");
    scanf("%d", &height);

    printf("Enter the coordinates of the first point: ");
    scanf("%d %d", &x1, &y1);

    printf("Enter the coordinates of the second point: ");
    scanf("%d %d", &x2, &y2);

    printf("\n");

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            fractal(j * (x2 - x1) / width + x1, i * (y2 - y1) / height + y1, (j + 1) * (x2 - x1) / width + x1, (i + 1) * (y2 - y1) / height + y1, 8);
        }
        printf("\n");
    }

    return 0;
}