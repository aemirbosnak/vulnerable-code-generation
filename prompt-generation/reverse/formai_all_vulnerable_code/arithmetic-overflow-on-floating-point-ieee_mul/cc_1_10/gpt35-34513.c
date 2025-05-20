//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: energetic
#include <stdio.h>
#include <math.h>

#define G 6.67408e-11 // gravitational constant

struct planet {
    char name[20];
    double mass; // in kg
    double x, y, z; // position vector in m
    double vx, vy, vz; // velocity vector in m/s
};

int main() {
    struct planet planets[3] = {
        {"Earth", 5.97e24, 0, 0, 0, 0, 0, 0},
        {"Moon", 7.35e22, 384400000, 0, 0, 0, 1022, 0},
        {"Mars", 6.39e23, 0, 227939200000, 0, -24130, 0, 0}
    };

    double time_step = 3600; // in seconds
    double total_time = 86400 * 365; // in seconds
    double t = 0; // current time
    double d, F; // distance between planets and force between them

    while (t < total_time) {
        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 3; j++) {
                d = sqrt(pow(planets[i].x - planets[j].x, 2) + pow(planets[i].y - planets[j].y, 2) + pow(planets[i].z - planets[j].z, 2));
                F = G * planets[i].mass * planets[j].mass / pow(d, 2);
                planets[i].vx -= F * (planets[i].x - planets[j].x) / (d * planets[i].mass) * time_step;
                planets[i].vy -= F * (planets[i].y - planets[j].y) / (d * planets[i].mass) * time_step;
                planets[i].vz -= F * (planets[i].z - planets[j].z) / (d * planets[i].mass) * time_step;
                planets[j].vx += F * (planets[i].x - planets[j].x) / (d * planets[j].mass) * time_step;
                planets[j].vy += F * (planets[i].y - planets[j].y) / (d * planets[j].mass) * time_step;
                planets[j].vz += F * (planets[i].z - planets[j].z) / (d * planets[j].mass) * time_step;
            }
        }

        for (int i = 0; i < 3; i++) {
            planets[i].x += planets[i].vx * time_step;
            planets[i].y += planets[i].vy * time_step;
            planets[i].z += planets[i].vz * time_step;
            printf("%s: (%.2f, %.2f, %.2f)\n", planets[i].name, planets[i].x, planets[i].y, planets[i].z);
        }

        t += time_step;
    }

    return 0;
}