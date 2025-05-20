//FormAI DATASET v1.0 Category: Physics simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i, j, k, n;
    float x[100], y[100], z[100];
    float vx[100], vy[100], vz[100];
    float m[100];

    printf("Enter the number of particles: ");
    scanf("%d", &n);

    printf("Enter the initial positions and velocities of each particle:\n");
    for (i = 0; i < n; i++)
    {
        printf("Particle %d:\n", i + 1);
        printf("x = ");
        scanf("%f", &x[i]);
        printf("y = ");
        scanf("%f", &y[i]);
        printf("z = ");
        scanf("%f", &z[i]);
        printf("vx = ");
        scanf("%f", &vx[i]);
        printf("vy = ");
        scanf("%f", &vy[i]);
        printf("vz = ");
        scanf("%f", &vz[i]);
        printf("mass = ");
        scanf("%f", &m[i]);
    }

    printf("Enter the time step size: ");
    float dt;
    scanf("%f", &dt);

    printf("Enter the number of time steps: ");
    int N;
    scanf("%d", &N);

    // Perform N time steps
    for (k = 0; k < N; k++)
    {
        // Compute pairwise forces between particles
        float fx, fy, fz, r2, r;
        for (i = 0; i < n; i++)
        {
            fx = fy = fz = 0;
            for (j = 0; j < n; j++)
            {
                if (i != j) // Compute force between two distinct particles
                {
                    r2 = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) + (z[i] - z[j]) * (z[i] - z[j]);
                    r = sqrt(r2);
                    fx += m[i] * m[j] * (x[j] - x[i]) / pow(r, 3);
                    fy += m[i] * m[j] * (y[j] - y[i]) / pow(r, 3);
                    fz += m[i] * m[j] * (z[j] - z[i]) / pow(r, 3);
                }
            }
            // Update velocities and positions of particle i
            vx[i] += fx * dt / m[i];
            vy[i] += fy * dt / m[i];
            vz[i] += fz * dt / m[i];
            x[i] += vx[i] * dt;
            y[i] += vy[i] * dt;
            z[i] += vz[i] * dt;
        }

        // Print the positions of all particles at this time step
        printf("Time step %d:\n", k + 1);
        for (i = 0; i < n; i++)
        {
            printf("Particle %d:\n", i + 1);
            printf("x = %f\n", x[i]);
            printf("y = %f\n", y[i]);
            printf("z = %f\n", z[i]);
        }
    }

    return 0;
}