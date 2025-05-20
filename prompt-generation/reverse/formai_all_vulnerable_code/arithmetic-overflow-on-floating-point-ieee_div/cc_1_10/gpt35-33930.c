//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Linus Torvalds
#include <stdio.h>

#define NUM_PLANETS 8

int main(void)
{
    char *planets[NUM_PLANETS] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"};
    double mass[NUM_PLANETS] = {0.33, 4.87, 5.97, 0.642, 1898, 568, 86.8, 102};

    double distance[NUM_PLANETS][NUM_PLANETS] = {
        {0, 0.387, 0.723, 1.52, 5.20, 9.58, 19.18, 30.07},
        {0.387, 0, 0.723, 1.83, 4.61, 8.94, 18.45, 29.18},
        {0.723, 0.723, 0, 1.00, 3.27, 7.79, 17.94, 28.79},
        {1.52, 1.83, 1.00, 0, 2.67, 6.09, 16.54, 27.32},
        {5.20, 4.61, 3.27, 2.67, 0, 4.04, 14.72, 25.40},
        {9.58, 8.94, 7.79, 6.09, 4.04, 0, 10.58, 20.20},
        {19.18, 18.45, 17.94, 16.54, 14.72, 10.58, 0, 9.44},
        {30.07, 29.18, 28.79, 27.32, 25.40, 20.20, 9.44, 0}};

    double pos[NUM_PLANETS][2], vel[NUM_PLANETS][2], force[NUM_PLANETS][2], acceleration[NUM_PLANETS][2];
    int i, j, k;
    double G = 6.673e-11;
    double timestep = 1e5;
    double time = 0;
    double t_end = 3.154e7;

    // initialize positions and velocities
    for (i = 0; i < NUM_PLANETS; i++)
    {
        pos[i][0] = 0;
        pos[i][1] = distance[i][0];
        vel[i][0] = sqrt(G * mass[0] / distance[i][0]);
        vel[i][1] = 0;
    }

    // simulation loop
    while (time < t_end)
    {
        // reset force and acceleration
        for (i = 0; i < NUM_PLANETS; i++)
        {
            force[i][0] = 0;
            force[i][1] = 0;
        }

        // calculate gravitational force and acceleration for each pair of planets
        for (i = 0; i < NUM_PLANETS; i++)
        {
            for (j = i + 1; j < NUM_PLANETS; j++)
            {
                double r = sqrt(pow(pos[j][0] - pos[i][0], 2) + pow(pos[j][1] - pos[i][1], 2));
                double f = G * mass[i] * mass[j] / pow(r, 2);
                double fx = f * (pos[j][0] - pos[i][0]) / r;
                double fy = f * (pos[j][1] - pos[i][1]) / r;

                force[i][0] += fx;
                force[i][1] += fy;
                force[j][0] -= fx;
                force[j][1] -= fy;
            }
        }

        // calculate acceleration from force and update velocity and position
        for (i = 0; i < NUM_PLANETS; i++)
        {
            acceleration[i][0] = force[i][0] / mass[i];
            acceleration[i][1] = force[i][1] / mass[i];

            vel[i][0] += acceleration[i][0] * timestep;
            vel[i][1] += acceleration[i][1] * timestep;

            pos[i][0] += vel[i][0] * timestep;
            pos[i][1] += vel[i][1] * timestep;
        }

        // print current positions
        printf("Time: %g\n", time);
        for (i = 0; i < NUM_PLANETS; i++)
        {
            printf("%s: (%g, %g)\n", planets[i], pos[i][0], pos[i][1]);
        }
        printf("\n");

        // update time
        time += timestep;
    }

    return 0;
}