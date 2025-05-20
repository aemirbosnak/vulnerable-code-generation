//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: funny
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int x, y, iteration, maxIter = 100;
    double zx, zy, c_re, c_im;

    printf("Prepare to witness the mesmerizing dance of fractal flames!\n");
    printf("Please select the number of iterations: ");
    scanf("%d", &maxIter);

    for (iteration = 0; iteration < maxIter; iteration++)
    {
        printf("Iteration %d: ", iteration);

        for (x = -1000; x <= 1000; x++)
        {
            for (y = -1000; y <= 1000; y++)
            {
                c_re = (double)x / 1000.0;
                c_im = (double)y / 1000.0;

                zx = 0.0;
                zy = 0.0;

                for (int i = 0; i < 255; i++)
                {
                    double z_re = zx + c_re * i;
                    double z_im = zy + c_im * i;

                    if (z_re * z_re + z_im * z_im > 4)
                        break;

                    zx = zy;
                    zy = sqrt(-2.0 * z_re * z_re - 2.0 * z_im * z_im) + z_re;
                }

                if (zx * zx + zy * zy > 4)
                {
                    printf("!");
                }
                else
                {
                    printf(".");
                }
            }
        }

        printf("\n");
    }

    return 0;
}