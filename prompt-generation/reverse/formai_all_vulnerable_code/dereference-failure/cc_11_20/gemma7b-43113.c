//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1024

int main()
{
    int x, y, i, j, n, m, iter = 0;
    float x1, x2, y1, y2, r, g, b, hue, sat, val;

    // Allocate memory
    int **arr = (int**)malloc(MAX * sizeof(int*));
    for(i = 0; i < MAX; i++)
        arr[i] = (int*)malloc(MAX * sizeof(int));

    // Initialize the array
    for(i = 0; i < MAX; i++)
        for(j = 0; j < MAX; j++)
            arr[i][j] = 0;

    // Set the parameters
    x1 = -2.0f;
    x2 = 1.0f;
    y1 = -1.0f;
    y2 = 1.0f;
    r = 0.0f;
    g = 0.0f;
    b = 0.0f;
    hue = 0.0f;
    sat = 100.0f;
    val = 255.0f;

    // Generate the fractal
    for(n = 0; n < MAX; n++)
    {
        for(m = 0; m < MAX; m++)
        {
            x = (m - MAX / 2) * 2.0f / MAX;
            y = (n - MAX / 2) * 2.0f / MAX;

            iter = 0;
            while(iter < MAX && (x * x + y * y) < 4)
            {
                float z = 1.0f / (1.0f + sqrtf(x * x + y * y));
                x = x1 + z * (x2 - x1);
                y = y1 + z * (y2 - y1);
                iter++;
            }

            arr[n][m] = iter;
        }
    }

    // Display the fractal
    for(i = 0; i < MAX; i++)
    {
        for(j = 0; j < MAX; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for(i = 0; i < MAX; i++)
        free(arr[i]);
    free(arr);

    return 0;
}