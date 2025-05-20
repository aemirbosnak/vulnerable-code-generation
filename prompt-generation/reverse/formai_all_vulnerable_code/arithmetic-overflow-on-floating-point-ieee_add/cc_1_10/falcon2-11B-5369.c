//Falcon2-11B DATASET v1.0 Category: Planet Gravity Simulation ; Style: curious
#include <stdio.h>
#include <math.h>

#define G 6.67408e-11

int main() {
    double x, y, r, vx, vy, m1, m2;
    double accel[2];

    printf("Welcome to the C Planet Gravity Simulation!\n");
    printf("Enter the distance between the two planets in meters: ");
    scanf("%lf", &r);

    printf("Enter the masses of the two planets in kilograms: ");
    scanf("%lf %lf", &m1, &m2);

    x = 0;
    y = r;

    printf("Planet 1: (%lf, %lf)\n", x, y);
    printf("Planet 2: (%lf, %lf)\n", x, y - r);

    printf("Enter the initial velocities of the two planets in meters per second: ");
    scanf("%lf %lf", &vx, &vy);

    printf("Calculating the acceleration due to gravity...\n");

    accel[0] = -G * m1 * (x + r);
    accel[1] = -G * m2 * (x + r - 2 * y);

    printf("Acceleration: (%lf, %lf)\n", accel[0], accel[1]);

    printf("Updating the positions...\n");

    x += vx;
    y += vy;

    printf("Planet 1: (%lf, %lf)\n", x, y);
    printf("Planet 2: (%lf, %lf)\n", x, y - r);

    printf("Calculating the next velocities...\n");

    vx += accel[0] / m1;
    vy += accel[1] / m2;

    printf("Planet 1: (%lf, %lf)\n", x, y);
    printf("Planet 2: (%lf, %lf)\n", x, y - r);

    printf("Running the simulation...\n");

    while (1) {
        printf("Planet 1: (%lf, %lf)\n", x, y);
        printf("Planet 2: (%lf, %lf)\n", x, y - r);

        printf("Enter the new velocities of the two planets in meters per second: ");
        scanf("%lf %lf", &vx, &vy);

        printf("Calculating the next velocities...\n");

        vx += accel[0] / m1;
        vy += accel[1] / m2;

        printf("Planet 1: (%lf, %lf)\n", x, y);
        printf("Planet 2: (%lf, %lf)\n", x, y - r);

        x += vx;
        y += vy;
    }

    return 0;
}