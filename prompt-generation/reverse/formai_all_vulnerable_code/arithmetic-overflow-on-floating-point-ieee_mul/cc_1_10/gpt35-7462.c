//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: unmistakable
#include <stdio.h>
#include <math.h>

#define G 6.67408e-11     // Gravitational constant
#define DT 3600.0          // Time increment in seconds
#define YEAR 31536000.0    // One year in seconds

// Define a struct for a celestial body
typedef struct {
    double mass;          // mass in kg
    double radius;        // radius in meters
    double position[3];   // x, y, z position in meters
    double velocity[3];   // x, y, z velocity in meters per second
} Body;

// Calculate the gravitational force between two bodies
void calculate_force(Body *body1, Body *body2, double force[]) {
    double distance, magnitude;
    int i;

    distance = sqrt(pow(body2->position[0] - body1->position[0], 2) +
                    pow(body2->position[1] - body1->position[1], 2) +
                    pow(body2->position[2] - body1->position[2], 2));

    magnitude = G * body1->mass * body2->mass / pow(distance, 2);

    for (i = 0; i < 3; i++) {
        force[i] = magnitude * (body2->position[i] - body1->position[i]) / distance;
    }
}

int main() {
    int i, j, steps;
    double time, force[3], acceleration[3];

    // Initialize the celestial bodies
    Body sun = {1.989e30, 6.96e8, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};
    Body earth = {5.97e24, 6.371e6, {1.496e11, 0.0, 0.0}, {0.0, 2.978e4, 0.0}};
    Body mars = {6.39e23, 3.39e6, {2.279e11, 0.0, 0.0}, {0.0, 2.41e4, 0.0}};
    Body venus = {4.87e24, 6.052e6, {1.082e11, 0.0, 0.0}, {0.0, 3.502e4, 0.0}};
    Body moon = {7.342e22, 1.737e6, {1.496e11 + 3.844e8, 0.0, 0.0}, {0.0, 2.978e4 + 1.022e3, 0.0}};

    // Set the number of simulation steps
    steps = (int)(YEAR / DT);

    // Run the simulation
    for (i = 0; i < steps; i++) {
        // Calculate the gravitational forces on each body
        calculate_force(&sun, &earth, force);
        for (j = 0; j < 3; j++) {
            acceleration[j] = force[j] / earth.mass;
            earth.velocity[j] += acceleration[j] * DT;
            earth.position[j] += earth.velocity[j] * DT;
        }

        calculate_force(&sun, &mars, force);
        for (j = 0; j < 3; j++) {
            acceleration[j] = force[j] / mars.mass;
            mars.velocity[j] += acceleration[j] * DT;
            mars.position[j] += mars.velocity[j] * DT;
        }

        calculate_force(&sun, &venus, force);
        for (j = 0; j < 3; j++) {
            acceleration[j] = force[j] / venus.mass;
            venus.velocity[j] += acceleration[j] * DT;
            venus.position[j] += venus.velocity[j] * DT;
        }

        calculate_force(&earth, &moon, force);
        for (j = 0; j < 3; j++) {
            acceleration[j] = force[j] / moon.mass;
            moon.velocity[j] += acceleration[j] * DT;
            moon.position[j] += moon.velocity[j] * DT;
        }

        // Update the time
        time += DT;
    }

    // Output the final positions and velocities of each body
    printf("Earth:\n");
    printf("Position: x=%f m, y=%f m, z=%f m\n", earth.position[0], earth.position[1], earth.position[2]);
    printf("Velocity: x=%f m/s, y=%f m/s, z=%f m/s\n", earth.velocity[0], earth.velocity[1], earth.velocity[2]);

    printf("Mars:\n");
    printf("Position: x=%f m, y=%f m, z=%f m\n", mars.position[0], mars.position[1], mars.position[2]);
    printf("Velocity: x=%f m/s, y=%f m/s, z=%f m/s\n", mars.velocity[0], mars.velocity[1], mars.velocity[2]);

    printf("Venus:\n");
    printf("Position: x=%f m, y=%f m, z=%f m\n", venus.position[0], venus.position[1], venus.position[2]);
    printf("Velocity: x=%f m/s, y=%f m/s, z=%f m/s\n", venus.velocity[0], venus.velocity[1], venus.velocity[2]);

    printf("Moon:\n");
    printf("Position: x=%f m, y=%f m, z=%f m\n", moon.position[0], moon.position[1], moon.position[2]);
    printf("Velocity: x=%f m/s, y=%f m/s, z=%f m/s\n", moon.velocity[0], moon.velocity[1], moon.velocity[2]);

    return 0;
}