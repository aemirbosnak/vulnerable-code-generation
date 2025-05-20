//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846
#define G 6.674e-11

int main()
{
    // Initialize variables
    double x, y, z, vx, vy, vz, ax, ay, az, dt, t;
    int i, n;

    // Get user input for number of simulations
    printf("Enter the number of simulations: ");
    scanf("%d", &n);

    // Loop through each simulation
    for (i = 0; i < n; i++)
    {
        // Initialize position and velocity
        x = 0.0;
        y = 0.0;
        z = 0.0;
        vx = 0.0;
        vy = 0.0;
        vz = 0.0;

        // Loop through each time step
        while (1)
        {
            // Calculate acceleration due to gravity
            ax = 0.0;
            ay = 0.0;
            az = -G;

            // Calculate new position and velocity
            vx += ax * dt;
            vy += ay * dt;
            vz += az * dt;

            x += vx * dt;
            y += vy * dt;
            z += vz * dt;

            // Check if drone has crashed
            if (z < 0.0)
            {
                printf("Simulation %d ended at t = %f\n", i+1, t);
                break;
            }

            // Check if simulation has ended
            if (t >= 100.0)
            {
                printf("Simulation %d ended at t = %f\n", i+1, t);
                break;
            }

            // Increment time
            t += dt;
        }
    }

    return 0;
}