//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: surprised
#include <stdio.h>
#include <math.h>

int main()
{
    printf("Welcome to the Planet Gravity Simulation!\n");
    printf("Enter the number of planets: ");
    int num_planets;
    scanf("%d", &num_planets);

    double x[num_planets], y[num_planets], z[num_planets];   /* Positions of the planets */
    double vx[num_planets], vy[num_planets], vz[num_planets]; /* Velocities of the planets */
    double ax[num_planets], ay[num_planets], az[num_planets]; /* Accelerations of the planets */
    double mass[num_planets];                                /* Mass of each planet */

    for(int i=0; i<num_planets; i++)
    {
        printf("\nEnter the initial position of Planet %d (x,y,z): ", i+1);
        scanf("%lf %lf %lf", &x[i], &y[i], &z[i]);
        printf("Enter the initial velocity of Planet %d (vx,vy,vz): ", i+1);
        scanf("%lf %lf %lf", &vx[i], &vy[i], &vz[i]);
        printf("Enter the mass of Planet %d: ", i+1);
        scanf("%lf", &mass[i]);
    }

    double G = 6.6743e-11; /* Gravitational constant */

    double time_step = 1.0; /* Time step for simulation */
    double time_elapsed = 0.0; /* Total time elapsed in simulation */
    printf("\nStarting simulation!\n");

    while(1)
    {
        /* Update accelerations for each planet */
        for(int i=0; i<num_planets; i++)
        {
            ax[i] = 0.0;
            ay[i] = 0.0;
            az[i] = 0.0;

            for(int j=0; j<num_planets; j++)
            {
                if(j == i) continue;

                double dx = x[j] - x[i];
                double dy = y[j] - y[i];
                double dz = z[j] - z[i];

                double distance_squared = dx*dx + dy*dy + dz*dz;
                double distance = sqrt(distance_squared);

                double force_magnitude = G * mass[i] * mass[j] / distance_squared;
                double force_x = force_magnitude * dx / distance;
                double force_y = force_magnitude * dy / distance;
                double force_z = force_magnitude * dz / distance;

                ax[i] += force_x / mass[i];
                ay[i] += force_y / mass[i];
                az[i] += force_z / mass[i];
            }
        }

        /* Update positions and velocities for each planet */
        for(int i=0; i<num_planets; i++)
        {
            x[i] += vx[i]*time_step + 0.5*ax[i]*time_step*time_step;
            y[i] += vy[i]*time_step + 0.5*ay[i]*time_step*time_step;
            z[i] += vz[i]*time_step + 0.5*az[i]*time_step*time_step;

            vx[i] += ax[i]*time_step;
            vy[i] += ay[i]*time_step;
            vz[i] += az[i]*time_step;
        }

        time_elapsed += time_step;

        printf("\nTime elapsed: %lf seconds\n", time_elapsed);

        for(int i=0; i<num_planets; i++)
        {
            printf("Planet %d position: (%lf, %lf, %lf)\n", i+1, x[i], y[i], z[i]);
            printf("Planet %d velocity: (%lf, %lf, %lf)\n", i+1, vx[i], vy[i], vz[i]);
        }
    }

    return 0;
}