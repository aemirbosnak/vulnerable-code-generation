//Falcon2-11B DATASET v1.0 Category: Simulation of the Solar System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct planet {
    int id;
    double x, y, z;
    double mass;
    double radius;
    double period;
    double inclination;
    double eccentricity;
};

int main() {
    struct planet earth = {1, 0.0, 0.0, 1.0, 6378.1, 23.4393, 0.0167};
    struct planet moon = {2, 0.0, 0.0, 0.0, 1737.0, 0.0, 0.0};
    struct planet sun = {0, 0.0, 0.0, 1.989e30, 695700.0, 0.0, 0.0};
    struct planet mars = {3, 0.0, 0.0, 0.1, 3396.2, 25.19, 1.849};
    struct planet mercury = {4, 0.0, 0.0, 0.06, 2440.0, 87.0, 0.2056};
    struct planet venus = {5, 0.0, 0.0, 0.82, 6052.8, 107.4, 0.0067};
    struct planet jupiter = {6, 0.0, 0.0, 1.899e27, 69911.0, 1.303, 0.0485};
    struct planet saturn = {7, 0.0, 0.0, 5.685e26, 58232.0, 2.485, 0.0557};
    struct planet uranus = {8, 0.0, 0.0, 8.681e25, 25559.0, 97.8, 0.0479};
    struct planet neptune = {9, 0.0, 0.0, 1.024e26, 24764.0, 28.3, 0.0088};

    double dt;

    int i;

    dt = 1.0;

    while (dt < 100000.0) {
        for (i = 0; i < 10; i++) {
            earth.x += dt * (0.0 + (earth.mass / earth.radius) * (earth.x - sun.x) / earth.radius);
            earth.y += dt * (0.0 + (earth.mass / earth.radius) * (earth.y - sun.y) / earth.radius);
            earth.z += dt * (0.0 + (earth.mass / earth.radius) * (earth.z - sun.z) / earth.radius);

            moon.x += dt * (0.0 + (moon.mass / moon.radius) * (moon.x - earth.x) / moon.radius);
            moon.y += dt * (0.0 + (moon.mass / moon.radius) * (moon.y - earth.y) / moon.radius);
            moon.z += dt * (0.0 + (moon.mass / moon.radius) * (moon.z - earth.z) / moon.radius);

            mars.x += dt * (0.0 + (mars.mass / mars.radius) * (mars.x - sun.x) / mars.radius);
            mars.y += dt * (0.0 + (mars.mass / mars.radius) * (mars.y - sun.y) / mars.radius);
            mars.z += dt * (0.0 + (mars.mass / mars.radius) * (mars.z - sun.z) / mars.radius);

            mercury.x += dt * (0.0 + (mercury.mass / mercury.radius) * (mercury.x - sun.x) / mercury.radius);
            mercury.y += dt * (0.0 + (mercury.mass / mercury.radius) * (mercury.y - sun.y) / mercury.radius);
            mercury.z += dt * (0.0 + (mercury.mass / mercury.radius) * (mercury.z - sun.z) / mercury.radius);

            venus.x += dt * (0.0 + (venus.mass / venus.radius) * (venus.x - sun.x) / venus.radius);
            venus.y += dt * (0.0 + (venus.mass / venus.radius) * (venus.y - sun.y) / venus.radius);
            venus.z += dt * (0.0 + (venus.mass / venus.radius) * (venus.z - sun.z) / venus.radius);

            jupiter.x += dt * (0.0 + (jupiter.mass / jupiter.radius) * (jupiter.x - sun.x) / jupiter.radius);
            jupiter.y += dt * (0.0 + (jupiter.mass / jupiter.radius) * (jupiter.y - sun.y) / jupiter.radius);
            jupiter.z += dt * (0.0 + (jupiter.mass / jupiter.radius) * (jupiter.z - sun.z) / jupiter.radius);

            saturn.x += dt * (0.0 + (saturn.mass / saturn.radius) * (saturn.x - sun.x) / saturn.radius);
            saturn.y += dt * (0.0 + (saturn.mass / saturn.radius) * (saturn.y - sun.y) / saturn.radius);
            saturn.z += dt * (0.0 + (saturn.mass / saturn.radius) * (saturn.z - sun.z) / saturn.radius);

            uranus.x += dt * (0.0 + (uranus.mass / uranus.radius) * (uranus.x - sun.x) / uranus.radius);
            uranus.y += dt * (0.0 + (uranus.mass / uranus.radius) * (uranus.y - sun.y) / uranus.radius);
            uranus.z += dt * (0.0 + (uranus.mass / uranus.radius) * (uranus.z - sun.z) / uranus.radius);

            neptune.x += dt * (0.0 + (neptune.mass / neptune.radius) * (neptune.x - sun.x) / neptune.radius);
            neptune.y += dt * (0.0 + (neptune.mass / neptune.radius) * (neptune.y - sun.y) / neptune.radius);
            neptune.z += dt * (0.0 + (neptune.mass / neptune.radius) * (neptune.z - sun.z) / neptune.radius);
        }

        printf("%d %d %d %f %f %f %f %f %f %f %f %f %f %f %f\n", earth.id, moon.id, mars.id, earth.x, earth.y, earth.z, moon.x, moon.y, moon.z, mars.x, mars.y, mars.z, mercury.x, mercury.y, mercury.z, venus.x, venus.y, venus.z);
        printf("%d %d %d %f %f %f %f %f %f %f %f %f %f %f %f\n", jupiter.id, saturn.id, uranus.id, jupiter.x, jupiter.y, jupiter.z, saturn.x, saturn.y, saturn.z, uranus.x, uranus.y, uranus.z, neptune.x, neptune.y, neptune.z);

        dt *= 0.98;
    }

    return 0;
}