//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITATIONAL_CONSTANT 6.6743e-11

typedef struct
{
    double x, y, z; // position
    double m;        // mass
    double fx, fy, fz; // force
    double ax, ay, az; // acceleration
    double vx, vy, vz; // velocity
} body;

void calculate_force(body *a, body *b)
{
    double dx = (b->x - a->x);
    double dy = (b->y - a->y);
    double dz = (b->z - a->z);
    double r = sqrt(dx*dx + dy*dy + dz*dz);
    double f = GRAVITATIONAL_CONSTANT * a->m * b->m / (r*r);
    a->fx += f * dx / r;
    a->fy += f * dy / r;
    a->fz += f * dz / r;
}

void update(body *b, double dt)
{
    b->ax = b->fx / b->m;
    b->ay = b->fy / b->m;
    b->az = b->fz / b->m;
    b->vx += b->ax * dt;
    b->vy += b->ay * dt;
    b->vz += b->az * dt;
    b->x += b->vx * dt;
    b->y += b->vy * dt;
    b->z += b->vz * dt;
    b->fx = b->fy = b->fz = 0.0;
}

int main()
{
    int n; // number of bodies
    double t; // simulation duration
    printf("Enter number of bodies: ");
    scanf("%d", &n);
    body *B = (body*) malloc(n * sizeof(body));
    printf("Enter simulation duration (in seconds): ");
    scanf("%lf", &t);
    double dt = 0.001; // time step
    printf("Enter initial positions (x, y, z) and mass of each body:\n");
    for(int i = 0; i < n; i++)
        scanf("%lf %lf %lf %lf", &B[i].x, &B[i].y, &B[i].z, &B[i].m);
    for(double time = 0; time < t; time += dt)
    {
        // calculate forces
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                calculate_force(&B[i], &B[j]);
        // update positions and velocities
        for(int i = 0; i < n; i++)
            update(&B[i], dt);
    }
    printf("Simulation completed.\n");
    free(B);
    return 0;
}