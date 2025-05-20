//Falcon2-11B DATASET v1.0 Category: Planet Gravity Simulation ; Style: synchronous
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

struct Planet {
    float mass;
    float x;
    float y;
    float z;
    float vx;
    float vy;
    float vz;
};

int main() {
    struct Planet earth, mars;

    earth.mass = 5.972e24;
    earth.x = 0;
    earth.y = 0;
    earth.z = 0;
    earth.vx = 0;
    earth.vy = 0;
    earth.vz = 0;

    mars.mass = 6.4189e23;
    mars.x = 1.524e11;
    mars.y = 2.387e11;
    mars.z = 2.279e11;
    mars.vx = 0;
    mars.vy = 0;
    mars.vz = 0;

    int n = 1000;

    float dt = 1 / (n * (earth.mass + mars.mass));
    float accel[3] = {0, 0, 0};

    for (int i = 0; i < n; i++) {
        float f = (earth.mass * mars.mass) / (earth.mass + mars.mass + earth.mass * mars.mass * (earth.mass + mars.mass));

        accel[0] += (earth.mass + mars.mass * (earth.mass * mars.mass * (earth.mass + mars.mass) / (earth.mass + mars.mass))) * (earth.x - mars.x) * f / (earth.mass + mars.mass);
        accel[1] += (earth.mass + mars.mass * (earth.mass * mars.mass * (earth.mass + mars.mass) / (earth.mass + mars.mass))) * (earth.y - mars.y) * f / (earth.mass + mars.mass);
        accel[2] += (earth.mass + mars.mass * (earth.mass * mars.mass * (earth.mass + mars.mass) / (earth.mass + mars.mass))) * (earth.z - mars.z) * f / (earth.mass + mars.mass);

        earth.vx += dt * accel[0];
        earth.vy += dt * accel[1];
        earth.vz += dt * accel[2];

        earth.x += dt * earth.vx;
        earth.y += dt * earth.vy;
        earth.z += dt * earth.vz;

        mars.vx += dt * accel[0];
        mars.vy += dt * accel[1];
        mars.vz += dt * accel[2];

        mars.x += dt * mars.vx;
        mars.y += dt * mars.vy;
        mars.z += dt * mars.vz;

        printf("Iteration %d\n", i + 1);
        printf("Earth: x=%f, y=%f, z=%f\n", earth.x, earth.y, earth.z);
        printf("Mars: x=%f, y=%f, z=%f\n", mars.x, mars.y, mars.z);
    }

    return 0;
}