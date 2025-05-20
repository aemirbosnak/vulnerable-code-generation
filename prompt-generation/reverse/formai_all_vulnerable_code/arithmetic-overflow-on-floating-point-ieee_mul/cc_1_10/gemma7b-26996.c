//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define a cosmic fractal
    double x_fractal = 0.0;
    double y_fractal = 0.0;
    double fractal_size = 10.0;
    int iterations = 1000;

    // Initialize the spaceship
    double x_ship = 0.0;
    double y_ship = 0.0;
    double dx_ship = 1.0;
    double dy_ship = 1.0;

    // Begin the adventure
    for (int i = 0; i < iterations; i++)
    {
        // Move the spaceship
        x_ship += dx_ship * 0.01;
        y_ship += dy_ship * 0.01;

        // Draw the fractal
        for (double x = x_fractal - fractal_size / 2; x < x_fractal + fractal_size / 2; x++)
        {
            for (double y = y_fractal - fractal_size / 2; y < y_fractal + fractal_size / 2; y++)
            {
                double distance = sqrt(pow(x - x_ship, 2) + pow(y - y_ship, 2));

                if (distance < fractal_size / 2)
                {
                    printf("%c", '*');
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }

        // Update the fractal
        x_fractal = x_ship;
        y_fractal = y_ship;
    }

    return 0;
}