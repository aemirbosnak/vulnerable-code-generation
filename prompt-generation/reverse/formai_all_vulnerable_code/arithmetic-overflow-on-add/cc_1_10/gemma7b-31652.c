//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 1000

int main()
{
    int x, y, i, iteration;
    double x_real, x_imag, z_real, z_imag;
    char buffer[1024];

    printf("Prepare for a mind-bending fractal journey!\n");
    printf("Press 'Enter' to begin...\n");
    fgets(buffer, 1024, stdin);

    for (x = -1000; x <= 1000; x++)
    {
        for (y = -1000; y <= 1000; y++)
        {
            iteration = 0;
            z_real = x + 1.5 * sin(y) / MAX_ITERATIONS;
            z_imag = y - 1.5 * cos(x) / MAX_ITERATIONS;

            for (i = 0; i < MAX_ITERATIONS; i++)
            {
                x_real = z_real - 2.0 * z_imag * z_real * z_imag;
                x_imag = z_imag + 2.0 * z_real * z_imag * z_real;
                z_real = x_real + 0.2 * x_imag;
                z_imag = x_imag;

                if (abs(z_real) + abs(z_imag) > 2)
                {
                    break;
                }
                iteration++;
            }

            if (iteration == MAX_ITERATIONS)
            {
                printf("(%d, %d): Black\n", x, y);
            }
            else
            {
                printf("(%d, %d): Color!\n", x, y);
            }
        }
    }

    printf("Congratulations, you have completed the fractal pilgrimage!\n");

    return 0;
}