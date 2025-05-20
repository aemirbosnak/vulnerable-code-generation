//FormAI DATASET v1.0 Category: Fractal Generation ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    // Set Iterations
    int max_iterations = 2000;

    // Set resolution of Fractal
    int res = 700;

    // Initialize Variables
    int x, y, i, j;
    float scale = 0.0065, a, b, c, d, a_new;
    float z_real, z_imag, z_real_temp, z_imag_temp;
    int fractal[res][res];

    // Set seed for random numbers
    srand(time(0));

    // Set the initial values for the complex parameters of fractal algorithm
    a = (float)(rand() % 20000 - 10000) / 10000;
    b = (float)(rand() % 20000 - 10000) / 10000;
    c = (float)(rand() % 20000 - 10000) / 10000;
    d = (float)(rand() % 20000 - 10000) / 10000;

    // Generate the fractal using the Iterated Function System (IFS)
    for (i = 0; i < res; i++)
    {
        for (j = 0; j < res; j++)
        {
            z_real = (float)(j - res/2) * scale;
            z_imag = (float)(i - res/2) * scale;
            for (int k = 0; k < max_iterations; k++)
            {
                a_new = a*z_real + b*z_imag + c;
                z_imag_temp = d*z_real + a* z_imag + d;
                z_real = a_new;
                z_imag = z_imag_temp;

                // Calculate the index to assign the color value to the pixel
                x = (int)((z_real + 2.0) / 4.0 * res);
                y = (int)((z_imag + 2.0) / 4.0 * res);

                // Color the pixel based on the index
                fractal[y][x]++;
            }
        }
    }

    // Print the fractal in ASCII
    for (i = 0; i < res; i++)
    {
        for (j = 0; j < res; j++)
        {

            if (fractal[i][j] < max_iterations / 50) { // Black
                printf("  ");
            }
            else if (fractal[i][j] < max_iterations / 10) { // Grey
                printf("%c%c", 176, 176);
            }
            else if (fractal[i][j] < max_iterations / 4) { // Lighter Grey
                printf("%c%c", 177, 177);
            }
            else { // White
                printf("%c%c", 178, 178);
            }
        }
        printf("\n");
    }

    return 0;
}