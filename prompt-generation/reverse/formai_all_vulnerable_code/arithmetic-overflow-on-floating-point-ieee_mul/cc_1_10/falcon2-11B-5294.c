//Falcon2-11B DATASET v1.0 Category: Planet Gravity Simulation ; Style: optimized
#include <stdio.h>
#include <math.h>

int main() {
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;

    printf("Enter the mass of the planet: ");
    scanf("%lf", &mass);
    printf("Enter the x, y, and z coordinates of the planet: ");
    scanf("%lf %lf %lf", &x, &y, &z);
    printf("Enter the initial velocity components: ");
    scanf("%lf %lf %lf", &vx, &vy, &vz);

    double g = 9.81;

    while(1) {
        double dx = vx;
        double dy = vy;
        double dz = vz;

        double a = g * mass;
        double dt = 0.01;

        dx += a * dt * dx / 2;
        dy += a * dt * dy / 2;
        dz += a * dt * dz / 2;

        vx += dx * dt;
        vy += dy * dt;
        vz += dz * dt;

        x += vx * dt;
        y += vy * dt;
        z += vz * dt;

        if(fabs(x) > 10000 || fabs(y) > 10000 || fabs(z) > 10000) {
            break;
        }
    }

    printf("Final position of the planet: (%lf, %lf, %lf)\n", x, y, z);
    printf("Final velocity of the planet: (%lf, %lf, %lf)\n", vx, vy, vz);

    return 0;
}