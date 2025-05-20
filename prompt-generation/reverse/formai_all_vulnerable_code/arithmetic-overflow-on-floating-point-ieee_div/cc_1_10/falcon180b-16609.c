//Falcon-180B DATASET v1.0 Category: Simulation of the Solar System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11

struct planet {
    char name[20];
    double mass;
    double x, y, z;
    double vx, vy, vz;
};

double distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}

void advance(struct planet *planet, double dt) {
    double ax, ay, az;
    double vx1, vy1, vz1;

    vx1 = planet->vx;
    vy1 = planet->vy;
    vz1 = planet->vz;

    ax = 0;
    ay = 0;
    az = G * planet->mass / distance(0, 0, 0, planet->x, planet->y, planet->z);

    planet->vx = vx1 + ax * dt;
    planet->vy = vy1 + ay * dt;
    planet->vz = vz1 + az * dt;

    planet->x += planet->vx * dt;
    planet->y += planet->vy * dt;
    planet->z += planet->vz * dt;
}

int main() {
    struct planet planets[] = {{"Sun", 1.9885e30, 0, 0, 0},
                             {"Mercury", 3.303e23, 4.880e10, 0, 0},
                             {"Venus", 4.869e24, 1.082e11, 0, 0},
                             {"Earth", 5.976e24, 1.496e11, 0, 0},
                             {"Mars", 6.421e23, 2.279e11, 0, 0},
                             {"Jupiter", 1.898e27, 5.202e11, 0, 0},
                             {"Saturn", 5.688e26, 9.582e11, 0, 0},
                             {"Uranus", 8.686e25, 1.783e12, 0, 0},
                             {"Neptune", 1.024e26, 2.793e12, 0, 0}};

    int i, j;
    double dt = 86400;  // one day

    for (i = 0; i < sizeof(planets) / sizeof(planets[0]); i++) {
        for (j = i + 1; j < sizeof(planets) / sizeof(planets[0]); j++) {
            advance(&planets[i], dt);
            advance(&planets[j], dt);
        }
    }

    return 0;
}