//FormAI DATASET v1.0 Category: Fractal Generation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Define constants */
#define WIDTH 79
#define HEIGHT 40
#define MAX_ITER 100

/* Function to generate the fractal */
void generateFractal(char canvas[HEIGHT][WIDTH])
{
    int x, y, i, n;
    float r, theta, fx, fy, x0, y0, x1, y1;

    /* Loop through every pixel on the canvas */
    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            /* Convert pixel coordinates to Cartesian coordinates */
            r = sqrt(pow(x - WIDTH / 2.0, 2) + pow(y - HEIGHT / 2.0, 2));
            theta = atan2(y - HEIGHT / 2.0, x - WIDTH / 2.0);

            /* Initialize variables */
            x0 = 0.0;
            y0 = 0.0;
            n = 0;

            /* Iterate until MAX_ITER or until escape condition is met */
            while (n < MAX_ITER && sqrt(pow(x0, 2) + pow(y0, 2)) < 2.0)
            {
                /* Apply transformation */
                fx = (x0 * cos(theta) + y0 * sin(theta)) / 2.0;
                fy = (-x0 * sin(theta) + y0 * cos(theta)) / 2.0;
                x1 = fx + sin(r);
                y1 = fy + cos(r);

                /* Update current point */
                x0 = x1;
                y0 = y1;

                /* Increment counter */
                n++;
            }

            /* Set pixel value based on number of iterations */
            if (n == MAX_ITER)
            {
                canvas[y][x] = '#'; /* Wall */
            }
            else
            {
                canvas[y][x] = '.'; /* Floor */
            }
        }
    }
}

/* Function to print the generated fractal */
void printFractal(char canvas[HEIGHT][WIDTH])
{
    int x, y;

    /* Print the fractal */
    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            printf("%c", canvas[y][x]);
        }
        printf("\n");
    }
}

/* Driver function */
int main()
{
    char canvas[HEIGHT][WIDTH];

    /* Generate the fractal */
    generateFractal(canvas);

    /* Print the fractal */
    printFractal(canvas);

    return 0;
}