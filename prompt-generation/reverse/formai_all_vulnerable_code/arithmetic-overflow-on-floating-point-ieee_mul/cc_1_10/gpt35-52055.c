//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: introspective
#include <stdio.h>
#include <math.h>

#define SIZE 8   // Number of celestial objects
#define G 6.6743E-11   // Gravitational constant

// Structure to store information of each planet
struct planet {
    char name[10];
    double mass;          // in kg
    double radius;        // in m
    double position[3];   // in m
    double velocity[3];   // in m/s
};

int main() {

    // Initialize all planets
    struct planet planets[SIZE] = {
        {"Sun", 1.989E+30, 696340000, {0, 0, 0}, {0, 0, 0}},
        {"Mercury", 3.301E+23, 2439700, {-5.791E+10, 0, 0}, {0, 47400, 0}},
        {"Venus", 4.867E+24, 6051800, {0, 1.082E+11, 0}, {-35020, 0, 0}},
        {"Earth", 5.972E+24, 6371000, {1.495E+11, 0, 0}, {0, 29783, 0}},
        {"Mars", 6.417E+23, 3396200, {0, -2.279E+11, 0}, {24007, 0, 0}},
        {"Jupiter", 1.898E+27, 69911000, {0, 0, 7.785E+11}, {0, 13070, 0}},
        {"Saturn", 5.683E+26, 58232000, {0, 0, -1.434E+12}, {0, -9690, 0}},
        {"Uranus", 8.681E+25, 25362000, {0, 0, 2.869E+12}, {0, 6835, 0}},
        {"Neptune", 1.024E+26, 24622000, {0, 0, -4.507E+12}, {0, -5477, 0}}
    };

    double time = 0, dt = 3600;   // in s

    // Simulation loop
    while (1) {

        // Calculate gravitational forces and update velocities
        for (int i = 0; i < SIZE; i++) {
            double force[3] = {0, 0, 0};
            for (int j = 0; j < SIZE; j++) {
                if (i == j) continue;
                double distance[3] = {
                    planets[j].position[0] - planets[i].position[0],
                    planets[j].position[1] - planets[i].position[1],
                    planets[j].position[2] - planets[i].position[2]
                };
                double r = sqrt(pow(distance[0], 2) + pow(distance[1], 2) + pow(distance[2], 2));
                double F = G * planets[i].mass * planets[j].mass / pow(r, 2);
                force[0] += F / planets[i].mass * distance[0] / r;
                force[1] += F / planets[i].mass * distance[1] / r;
                force[2] += F / planets[i].mass * distance[2] / r;
            }
            planets[i].velocity[0] += force[0] * dt;
            planets[i].velocity[1] += force[1] * dt;
            planets[i].velocity[2] += force[2] * dt;
        }

        // Update positions according to velocities
        for (int i = 0; i < SIZE; i++) {
            planets[i].position[0] += planets[i].velocity[0] * dt;
            planets[i].position[1] += planets[i].velocity[1] * dt;
            planets[i].position[2] += planets[i].velocity[2] * dt;
        }

        // Print positions and velocities of all planets for every 1000 seconds
        if ((int)time % 1000 == 0) {
            printf("Time: %.2f s\n", time);
            for (int i = 0; i < SIZE; i++) {
                printf("%-10s P(%10.2f, %10.2f, %10.2f) V(%10.2f, %10.2f, %10.2f)\n",
                    planets[i].name,
                    planets[i].position[0], planets[i].position[1], planets[i].position[2],
                    planets[i].velocity[0], planets[i].velocity[1], planets[i].velocity[2]);
            }
        }

        time += dt;
    }

    return 0;
}