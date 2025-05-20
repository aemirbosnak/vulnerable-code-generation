//GPT-4o-mini DATASET v1.0 Category: Planet Gravity Simulation ; Style: realistic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define G 6.67430e-11 // Universal gravitational constant
#define PI 3.14159265358979323846
#define EARTH_MASS 5.972e24 // kg
#define SUN_MASS 1.989e30   // kg

typedef struct {
    double x; // x position
    double y; // y position
    double z; // z position
    double mass; // mass of the body
    double vx; // velocity in x direction
    double vy; // velocity in y direction
    double vz; // velocity in z direction
} CelestialBody;

void display_position(CelestialBody body) {
    printf("Position - X: %.2e, Y: %.2e, Z: %.2e\n", body.x, body.y, body.z);
}

double calculate_gravity(CelestialBody body1, CelestialBody body2) {
    double distance = sqrt(pow(body2.x - body1.x, 2) +
                           pow(body2.y - body1.y, 2) +
                           pow(body2.z - body1.z, 2));
    
    if (distance == 0) return 0; // Avoid division by zero

    return G * body1.mass * body2.mass / (distance * distance);
}

void update_velocity(CelestialBody *body, CelestialBody *other, double dt) {
    double force = calculate_gravity(*body, *other);
    double distance_x = other->x - body->x;
    double distance_y = other->y - body->y;
    double distance_z = other->z - body->z;
    double distance = sqrt(pow(distance_x, 2) + pow(distance_y, 2) + pow(distance_z, 2));
    
    if (distance != 0) {
        // Normalize the direction
        double ax = force * distance_x / (body->mass * distance);
        double ay = force * distance_y / (body->mass * distance);
        double az = force * distance_z / (body->mass * distance);

        body->vx += ax * dt;
        body->vy += ay * dt;
        body->vz += az * dt;
    }
}

void update_position(CelestialBody *body, double dt) {
    body->x += body->vx * dt;
    body->y += body->vy * dt;
    body->z += body->vz * dt;
}

void simulate(double total_time, double time_step) {
    CelestialBody earth = {1.496e11, 0, 0, EARTH_MASS, 0, 29780, 0}; // Earth's orbit around the sun
    CelestialBody sun = {0, 0, 0, SUN_MASS, 0, 0, 0}; // sun at the center

    double elapsed_time = 0;

    while (elapsed_time < total_time) {
        update_velocity(&earth, &sun, time_step);
        update_position(&earth, time_step);

        printf("Time: %.2f seconds\n", elapsed_time);
        display_position(earth);

        elapsed_time += time_step;
    }
}

int main() {
    srand(time(NULL));
    double total_time = 365 * 24 * 3600; // simulate 1 year in seconds
    double time_step = 60; // 1 minute time step

    printf("Simulating the orbit of Earth around the Sun:\n");
    simulate(total_time, time_step);

    return 0;
}