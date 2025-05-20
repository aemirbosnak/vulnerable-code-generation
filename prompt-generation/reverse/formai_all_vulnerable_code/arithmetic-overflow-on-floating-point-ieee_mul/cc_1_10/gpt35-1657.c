//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: detailed
#include <stdio.h>
#include <math.h>

#define G 6.674e-11 // gravitational constant

// struct to store information of a planet
typedef struct {
    double mass;
    double position[3];
    double velocity[3];
} Planet;

// function to calculate the distance between two points in 3D space
double distance(double p1[], double p2[]) {
    return sqrt(pow(p2[0] - p1[0], 2) + pow(p2[1] - p1[1], 2) + pow(p2[2] - p1[2], 2));
}

// function to calculate the gravitational force between two planets
void gravitational_force(Planet p1, Planet p2, double* force) {
    double r = distance(p1.position, p2.position);
    double magnitude = G * p1.mass * p2.mass / pow(r, 2);
    for (int i = 0; i < 3; i++) {
        force[i] = magnitude * (p2.position[i] - p1.position[i]) / r;
    }
}

int main() {
    // initialize planets
    Planet earth = {5.972e24, {0, 0, 0}, {0, 0, 0}};
    Planet moon = {7.342e22, {384400000, 0, 0}, {0, 1023, 0}};

    // simulation parameters
    double timestep = 86400; // 1 day in seconds
    double simulation_time = timestep * 365; // 1 year simulation
    int steps = (int) (simulation_time / timestep);

    // simulation loop
    for (int i = 0; i < steps; i++) {

        // calculate gravitational force between earth and moon
        double force[3];
        gravitational_force(earth, moon, force);

        // update velocity and position of earth and moon
        for (int j = 0; j < 3; j++) {
            earth.velocity[j] += force[j] / earth.mass * timestep;
            earth.position[j] += earth.velocity[j] * timestep;
            moon.velocity[j] -= force[j] / moon.mass * timestep;
            moon.position[j] += moon.velocity[j] * timestep;
        }

        // print position of moon every full moon cycle
        if ((i + 1) % 29 == 0) {
            printf("%.1f days: Moon is at position (%.2f, %.2f, %.2f)\n", i * timestep, moon.position[0], moon.position[1], moon.position[2]);
        }
    }

    return 0;
}