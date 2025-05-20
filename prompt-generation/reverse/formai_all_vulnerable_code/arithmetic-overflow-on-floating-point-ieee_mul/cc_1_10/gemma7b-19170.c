//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x, y, iterations;
    double re, im, c_real, c_imag;

    printf("Enter the number of iterations: ");
    scanf("%d", &iterations);

    for (x = -1000; x <= 1000; x++)
    {
        for (y = -1000; y <= 1000; y++)
        {
            re = (double)x / 1000.0;
            im = (double)y / 1000.0;

            c_real = re - im * im;
            c_imag = 2 * im;

            if (iter_fract(c_real, c_imag, iterations) == iterations)
            {
                printf("%c", 248);
            }
            else
            {
                printf("%c", 0);
            }
        }
    }

    return 0;
}

int iter_fract(double c_real, double c_imag, int iterations)
{
    int i;
    double z_real, z_imag, z_mag;

    for (i = 0; i < iterations; i++)
    {
        z_real = c_real + z_imag * z_imag;
        z_imag = 2 * z_real * z_imag;

        z_mag = sqrt(z_real * z_real + z_imag * z_imag);

        if (z_mag > 2)
        {
            return i;
        }

        c_real = z_real;
        c_imag = z_imag;
    }

    return iterations;
}