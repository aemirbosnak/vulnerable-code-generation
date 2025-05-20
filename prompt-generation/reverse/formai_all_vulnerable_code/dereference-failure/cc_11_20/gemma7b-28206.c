//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: satisfied
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int x, y, i, n, max_iter = 255;
    double zx, zy, cr, cy, r, g, b, hue, sat, val;

    // Allocates memory for a 2D array
    int **pixel = (int **)malloc(1024 * sizeof(int *));
    for (i = 0; i < 1024; i++)
    {
        pixel[i] = (int *)malloc(1024 * sizeof(int));
    }

    // Initializes pixel values
    for (x = 0; x < 1024; x++)
    {
        for (y = 0; y < 1024; y++)
        {
            pixel[x][y] = 0;
        }
    }

    // Iterates over the fractal
    for (n = 0; n < max_iter; n++)
    {
        cr = -2.0;
        cy = -1.0;
        for (x = 0; x < 1024; x++)
        {
            for (y = 0; y < 1024; y++)
            {
                r = cr + (x - 512.0) / 1024.0;
                g = cy + (y - 512.0) / 1024.0;
                zx = r * r + g * g;
                zy = 2.0 * r * g;

                if (zx + zy > 4.0)
                {
                    pixel[x][y] = n;
                }
            }
        }
    }

    // Writes pixel values to an image file
    FILE *fp = fopen("fractal.ppm", "w");
    fprintf(fp, "P Bitmap 1024 1024 3\n");
    fprintf(fp, "RGB\n");
    for (x = 0; x < 1024; x++)
    {
        for (y = 0; y < 1024; y++)
        {
            fprintf(fp, "%d %d %d ", pixel[x][y], pixel[x][y], pixel[x][y]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);

    // Free allocated memory
    for (i = 0; i < 1024; i++)
    {
        free(pixel[i]);
    }
    free(pixel);

    return 0;
}