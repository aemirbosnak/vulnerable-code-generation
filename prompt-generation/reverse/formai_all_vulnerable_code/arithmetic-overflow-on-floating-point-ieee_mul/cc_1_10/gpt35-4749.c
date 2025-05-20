//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

struct planet {
    double x, y, vx, vy, mass;
};

// Function to calculate the distance between two planets
double distance(struct planet p1, struct planet p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    // Initialize planets
    struct planet blue_planet = {.x = 0, .y = 0, .vx = 0, .vy = 0, .mass = 1000};
    struct planet red_planet = {.x = 100, .y = 100, .vx = 0, .vy = 0, .mass = 500};

    // Set up simulation
    double timestep = 0.1;
    double time = 0;
    double G = 6.6743e-11;

    // Main simulation loop
    while (1) {
        printf("Time: %.2f s, Distance: %.2f m\n", time, distance(blue_planet, red_planet));

        // Calculate gravitational force between planets
        double force = G * blue_planet.mass * red_planet.mass / pow(distance(blue_planet, red_planet), 2);

        // Calculate acceleration of each planet
        double acceleration_blue = force / blue_planet.mass;
        double acceleration_red = force / red_planet.mass;

        // Calculate angle between planets
        double theta = atan2(red_planet.y - blue_planet.y, red_planet.x - blue_planet.x);

        // Calculate x and y components of acceleration for each planet
        double ax_blue = acceleration_blue * cos(theta);
        double ay_blue = acceleration_blue * sin(theta);
        double ax_red = acceleration_red * cos(theta+PI);
        double ay_red = acceleration_red * sin(theta+PI);

        // Update velocities of each planet
        blue_planet.vx += ax_blue * timestep;
        blue_planet.vy += ay_blue * timestep;
        red_planet.vx += ax_red * timestep;
        red_planet.vy += ay_red * timestep;

        // Update positions of each planet
        blue_planet.x += blue_planet.vx * timestep;
        blue_planet.y += blue_planet.vy * timestep;
        red_planet.x += red_planet.vx * timestep;
        red_planet.y += red_planet.vy * timestep;

        // Increment time
        time += timestep;

        // Check for collision
        if (distance(blue_planet, red_planet) < 10) {
            printf("The planets have collided!\n");
            break;
        }
    }

    return 0;
}