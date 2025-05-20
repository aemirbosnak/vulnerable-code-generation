//Falcon2-11B DATASET v1.0 Category: Simulation of the Solar System ; Style: authentic
#include <stdio.h>
#include <math.h>

int main() {
    const double PI = 3.14159;
    const double EARTH_RADIUS = 6371;
    const double SUN_MASS = 1.989e30;
    const double EARTH_MASS = 5.972e24;

    double x = 0.0;
    double y = 0.0;
    double z = 0.0;

    double dx = 0.0;
    double dy = 0.0;
    double dz = 0.0;

    double time = 0.0;
    double dt = 0.0;

    int steps = 0;

    double sun_x = 0.0;
    double sun_y = 0.0;
    double sun_z = 0.0;

    double earth_x = 0.0;
    double earth_y = 0.0;
    double earth_z = 0.0;

    printf("Solar System Simulation\n");

    while (x > -1e6 && x < 1e6 && y > -1e6 && y < 1e6 && z > -1e6 && z < 1e6) {
        steps++;

        sun_x = sin(x) * sin(y) * cos(z) + cos(x) * cos(y) * sin(z);
        sun_y = sin(x) * sin(y) * sin(z) - cos(x) * cos(y) * cos(z);
        sun_z = cos(x) * sin(y);

        earth_x = sin(x) * sin(y) * cos(z) + cos(x) * cos(y) * sin(z);
        earth_y = sin(x) * sin(y) * sin(z) - cos(x) * cos(y) * cos(z);
        earth_z = cos(x) * sin(y);

        dx = sun_x - earth_x;
        dy = sun_y - earth_y;
        dz = sun_z - earth_z;

        time += 1.0 / (sqrt(dx * dx + dy * dy + dz * dz) / (EARTH_MASS / SUN_MASS));
        dt = time - steps * 86400;

        x += dx * dt;
        y += dy * dt;
        z += dz * dt;

        printf("Step %d: %.6f, %.6f, %.6f | %.6f, %.6f, %.6f\n", steps, x, y, z, sun_x, sun_y, sun_z);
    }

    printf("Simulation completed in %d steps.\n", steps);

    return 0;
}