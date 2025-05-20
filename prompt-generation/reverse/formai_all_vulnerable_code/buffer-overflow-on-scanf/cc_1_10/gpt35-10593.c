//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430E-11
#define SIZE 3

void update_velocity(double dt, double mass[SIZE], double pos[SIZE][3], double vel[SIZE][3], int i, int j)
{
    double r = sqrt(pow(pos[j][0] - pos[i][0], 2) + pow(pos[j][1] - pos[i][1], 2) + pow(pos[j][2] - pos[i][2], 2));

    double force = G * mass[i] * mass[j] / pow(r, 2);

    double force_x = force * (pos[j][0] - pos[i][0]) / r;
    double force_y = force * (pos[j][1] - pos[i][1]) / r;
    double force_z = force * (pos[j][2] - pos[i][2]) / r;

    vel[i][0] += force_x / mass[i] * dt;
    vel[i][1] += force_y / mass[i] * dt;
    vel[i][2] += force_z / mass[i] * dt;

}

void update_position(double dt, double mass[SIZE], double pos[SIZE][3], double vel[SIZE][3], int i)
{
    pos[i][0] += vel[i][0] * dt;
    pos[i][1] += vel[i][1] * dt;
    pos[i][2] += vel[i][2] * dt;

}

int main()
{
    double mass[SIZE] = {5.97E24, 7.34E22, 1.98E30};
    double pos[SIZE][3] = {{0,0,0}, {384400000,0,0}, {0,149600000000,0}};
    double vel[SIZE][3] = {{0,0,0}, {0,1022,0}, {29783,0,0}};

    double dt, time;

    printf("Enter time step: ");
    scanf("%lf", &dt);

    printf("Enter total time: ");
    scanf("%lf", &time);

    int i, j;
    for(double t = 0; t < time; t += dt)
    {
        for(i = 0; i < SIZE; i++)
        {
            for(j = 0; j < SIZE; j++)
            {
                if(i != j)
                {
                    update_velocity(dt, mass, pos, vel, i, j);
                }
            }
        }
        for(i = 0; i < SIZE; i++)
        {
            update_position(dt, mass, pos, vel, i);
        }

        printf("t = %f, Earth Position = (%e, %e, %e), Moon Position = (%e, %e, %e), Sun Position = (%e, %e, %e)\n", t,
               pos[0][0], pos[0][1], pos[0][2],
               pos[1][0], pos[1][1], pos[1][2],
               pos[2][0], pos[2][1], pos[2][2]);
    }

    return 0;
}