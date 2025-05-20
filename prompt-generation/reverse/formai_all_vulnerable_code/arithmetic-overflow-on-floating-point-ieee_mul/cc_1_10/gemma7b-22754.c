//Gemma-7B DATASET v1.0 Category: Simulation of the Solar System ; Style: happy
#include <stdio.h>
#include <math.h>

#define NUM_PLANETS 9

typedef struct Planet {
    char name[20];
    double mass;
    double x;
    double y;
    double z;
    double dx;
    double dy;
    double dz;
} Planet;

Planet planets[NUM_PLANETS] = {
    {"Mercury", 0.055, 0.25, 0.0, 0.0, 0.01, 0.0, 0.0},
    {"Venus", 0.815, -1.0, 0.0, 0.0, 0.02, 0.0, 0.0},
    {"Earth", 1.0, 1.0, 0.0, 0.0, 0.01, 0.0, 0.0},
    {"Mars", 0.643, 1.5, 0.0, 0.0, 0.01, 0.0, 0.0},
    {"Jupiter", 5.97e24, -5.2, 0.0, 0.0, 0.01, 0.0, 0.0},
    {"Saturn", 5.89e24, -8.0, 0.0, 0.0, 0.01, 0.0, 0.0},
    {"Uranus", 1.05e24, -11.0, 0.0, 0.0, 0.01, 0.0, 0.0},
    {"Neptune", 1.03e24, -14.0, 0.0, 0.0, 0.01, 0.0, 0.0},
    {"Pluto", 0.002, -15.0, 0.0, 0.0, 0.01, 0.0, 0.0}
};

void update_positions(void) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i].x += planets[i].dx * 0.01;
        planets[i].y += planets[i].dy * 0.01;
        planets[i].z += planets[i].dz * 0.01;
    }
}

void update_velocities(void) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i].dx += 0.001 * planets[i].mass * planets[i].dy;
        planets[i].dy += 0.001 * planets[i].mass * planets[i].dx;
    }
}

int main(void) {
    int t = 0;
    while (t < 1000) {
        update_positions();
        update_velocities();
        t++;
    }

    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("%s: x = %.2f, y = %.2f, z = %.2f\n", planets[i].name, planets[i].x, planets[i].y, planets[i].z);
    }

    return 0;
}