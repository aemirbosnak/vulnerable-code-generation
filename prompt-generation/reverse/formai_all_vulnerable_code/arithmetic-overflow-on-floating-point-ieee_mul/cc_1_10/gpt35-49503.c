//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: happy
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define G 6.67430e-11

// Define a Planet struct to represent a planet
typedef struct Planet {
    double mass, radius, pos_x, pos_y, vel_x, vel_y;
    char* name;
} Planet;

// Calculate the distance between two points
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Calculate the force between two planets
double force(double mass1, double mass2, double dist) {
    return G * mass1 * mass2 / pow(dist, 2);
}

// Calculate the acceleration of a planet due to a force
double acceleration(double force, double mass) {
    return force / mass;
}

int main() {
    // Initialize an array of three planets
    Planet planets[3] = {
        {
            .mass = 5.972e24,
            .radius = 6371e3,
            .pos_x = 0,
            .pos_y = 0,
            .vel_x = 0,
            .vel_y = 0,
            .name = "Earth"
        },
        {
            .mass = 7.3477e22,
            .radius = 1737.5e3,
            .pos_x = 384.4e6,
            .pos_y = 0,
            .vel_x = 0,
            .vel_y = 1022,
            .name = "Moon"
        },
        {
            .mass = 1.989e30,
            .radius = 695508e3,
            .pos_x = -147.1e9,
            .pos_y = 0,
            .vel_x = 0,
            .vel_y = -29.78e3,
            .name = "Sun"
        }
    };

    // Simulate the system for 1 year
    double timestep = 60 * 60 * 24; // 1 day in seconds
    double num_steps = 365; // 1 year, in days
    for (int step = 0; step < num_steps; step++) {
        // Print out the positions of each planet
        for (int i = 0; i < 3; i++) {
            printf("%s: (%.2f, %.2f)\n", planets[i].name, planets[i].pos_x, planets[i].pos_y);
        }
        printf("\n");

        // Calculate the forces on each planet
        double forces[3][3] = {{0}};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;
                double dist = distance(planets[i].pos_x, planets[i].pos_y, planets[j].pos_x, planets[j].pos_y);
                double f = force(planets[i].mass, planets[j].mass, dist);
                double theta = atan2(planets[j].pos_y - planets[i].pos_y, planets[j].pos_x - planets[i].pos_x);
                forces[i][0] += f * cos(theta);
                forces[i][1] += f * sin(theta);
            }
        }

        // Calculate the accelerations of each planet
        double accelerations[3][2] = {{0}};
        for (int i = 0; i < 3; i++) {
            accelerations[i][0] = acceleration(forces[i][0], planets[i].mass);
            accelerations[i][1] = acceleration(forces[i][1], planets[i].mass);
        }

        // Update the velocities and positions of each planet
        for (int i = 0; i < 3; i++) {
            planets[i].vel_x += accelerations[i][0] * timestep;
            planets[i].vel_y += accelerations[i][1] * timestep;
            planets[i].pos_x += planets[i].vel_x * timestep;
            planets[i].pos_y += planets[i].vel_y * timestep;
        }
    }

    return 0;
}