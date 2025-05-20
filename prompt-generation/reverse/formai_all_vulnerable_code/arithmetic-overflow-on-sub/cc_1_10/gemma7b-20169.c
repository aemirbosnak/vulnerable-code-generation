//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 255

void draw_fractal(int x, int y, int zoom, int iterations)
{
    int i, j;

    for (i = x - zoom; i <= x + zoom; i++)
    {
        for (j = y - zoom; j <= y + zoom; j++)
        {
            int distance = abs((i - x) * cos(iterations) + (j - y) * sin(iterations));

            if (distance < MAX_ITERATIONS)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
    }

    printf("\n");
}

int main()
{
    int x, y, zoom, iterations;

    printf("Enter the number of iterations: ");
    scanf("%d", &iterations);

    printf("Enter the x-coordinate: ");
    scanf("%d", &x);

    printf("Enter the y-coordinate: ");
    scanf("%d", &y);

    printf("Enter the zoom factor: ");
    scanf("%d", &zoom);

    draw_fractal(x, y, zoom, iterations);

    return 0;
}