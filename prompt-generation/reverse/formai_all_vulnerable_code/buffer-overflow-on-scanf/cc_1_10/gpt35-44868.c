//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITY 6.674e-11 // gravitational constant

int main()
{
    int num_planets;
    printf("Enter the number of planets: ");
    scanf("%d", &num_planets);

    double *mass = malloc(num_planets * sizeof(double));
    double *pos_x = malloc(num_planets * sizeof(double));
    double *pos_y = malloc(num_planets * sizeof(double));
    double *vel_x = malloc(num_planets * sizeof(double));
    double *vel_y = malloc(num_planets * sizeof(double));

    printf("Enter the properties of each planet (mass, position, velocity):\n");

    for (int i = 0; i < num_planets; i++)
    {
        printf("Planet %d:\n", i+1);
        scanf("%lf %lf %lf %lf %lf", &mass[i], &pos_x[i], &pos_y[i], &vel_x[i], &vel_y[i]);
    }

    double time_step;
    printf("Enter the time step (in seconds): ");
    scanf("%lf", &time_step);

    int num_steps;
    printf("Enter the number of time steps: ");
    scanf("%d", &num_steps);

    for (int step = 0; step < num_steps; step++)
    {
        for (int i = 0; i < num_planets; i++)
        {
            double acc_x = 0.0;
            double acc_y = 0.0;

            for (int j = 0; j < num_planets; j++)
            {
                if (i == j) continue;

                double dx = pos_x[j] - pos_x[i];
                double dy = pos_y[j] - pos_y[i];

                double dist = sqrt(dx*dx + dy*dy);
                double force = GRAVITY * mass[i] * mass[j] / (dist*dist);

                acc_x += force * dx / dist / mass[i];
                acc_y += force * dy / dist / mass[i];
            }

            vel_x[i] += acc_x * time_step;
            vel_y[i] += acc_y * time_step;
            pos_x[i] += vel_x[i] * time_step;
            pos_y[i] += vel_y[i] * time_step;

            printf("%lf %lf\n", pos_x[i], pos_y[i]);
        }
    }

    free(mass);
    free(pos_x);
    free(pos_y);
    free(vel_x);
    free(vel_y);

    return 0;
}