//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: realistic
#include <stdio.h>
#include <math.h>

#define G 6.67e-11 // Gravitational constant

int main()
{
    int numPlanets; // number of planets
    printf("Enter number of planets: ");
    scanf("%d", &numPlanets);

    double masses[numPlanets];
    double positions[numPlanets][3];
    double velocities[numPlanets][3];

    // prompt user to enter data for each planet
    for (int i = 0; i < numPlanets; i++)
    {
        printf("\nEnter data for planet %d:\n", i + 1);
        printf("Mass (kg): ");
        scanf("%lf", &masses[i]);
        printf("Position (m) <x, y, z>: ");
        scanf("%lf %lf %lf", &positions[i][0], &positions[i][1], &positions[i][2]);
        printf("Velocity (m/s) <x, y, z>: ");
        scanf("%lf %lf %lf", &velocities[i][0], &velocities[i][1], &velocities[i][2]);
    }

    // simulation settings
    double deltaTime = 60 * 60 * 24; // time step (1 day)
    double totalTime = 365 * 5; // total time (5 years)

    // simulation loop
    for (double t = 0; t < totalTime; t += deltaTime)
    {
        // calculate acceleration for each planet
        double accelerations[numPlanets][3];
        for (int i = 0; i < numPlanets; i++)
        {
            accelerations[i][0] = 0;
            accelerations[i][1] = 0;
            accelerations[i][2] = 0;

            for (int j = 0; j < numPlanets; j++)
            {
                if (i == j) continue;

                double dx = positions[j][0] - positions[i][0];
                double dy = positions[j][1] - positions[i][1];
                double dz = positions[j][2] - positions[i][2];

                double r = sqrt(dx*dx + dy*dy + dz*dz);
                double a = G * masses[j] / (r*r);

                accelerations[i][0] += a * dx / r;
                accelerations[i][1] += a * dy / r;
                accelerations[i][2] += a * dz / r;
            }
        }

        // update positions and velocities for each planet
        for (int i = 0; i < numPlanets; i++)
        {
            positions[i][0] += velocities[i][0] * deltaTime + 0.5 * accelerations[i][0] * deltaTime * deltaTime;
            positions[i][1] += velocities[i][1] * deltaTime + 0.5 * accelerations[i][1] * deltaTime * deltaTime;
            positions[i][2] += velocities[i][2] * deltaTime + 0.5 * accelerations[i][2] * deltaTime * deltaTime;

            velocities[i][0] += accelerations[i][0] * deltaTime;
            velocities[i][1] += accelerations[i][1] * deltaTime;
            velocities[i][2] += accelerations[i][2] * deltaTime;
        }
    }

    // output final positions and velocities for each planet
    printf("\n\nFinal planet positions and velocities:\n");
    for (int i = 0; i < numPlanets; i++)
    {
        printf("Planet %d\n", i + 1);
        printf("Position: <%e, %e, %e> m\n", positions[i][0], positions[i][1], positions[i][2]);
        printf("Velocity: <%e, %e, %e> m/s\n", velocities[i][0], velocities[i][1], velocities[i][2]);
    }

    return 0;
}