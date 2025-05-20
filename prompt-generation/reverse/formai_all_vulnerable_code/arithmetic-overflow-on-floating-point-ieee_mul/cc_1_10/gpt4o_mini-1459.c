//GPT-4o-mini DATASET v1.0 Category: Planet Gravity Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11 // gravitational constant
#define PI 3.14159265358979323846

typedef struct {
    double mass; // mass of the planet
    double radius; // radius of the planet
    double x; // x position
    double y; // y position
} Planet;

typedef struct {
    double x; // x position of the object
    double y; // y position of the object
    double mass; // mass of the object
    double velocity_x; // velocity in x direction
    double velocity_y; // velocity in y direction
} Object;

void initialize_planet(Planet *planet, double mass, double radius, double x, double y) {
    planet->mass = mass;
    planet->radius = radius;
    planet->x = x;
    planet->y = y;
}

void initialize_object(Object *object, double mass, double x, double y, double velocity_x, double velocity_y) {
    object->mass = mass;
    object->x = x;
    object->y = y;
    object->velocity_x = velocity_x;
    object->velocity_y = velocity_y;
}

double calculate_gravitational_force(Planet *planet, Object *object) {
    double distance_x = object->x - planet->x;
    double distance_y = object->y - planet->y;
    double distance = sqrt(distance_x * distance_x + distance_y * distance_y);
    
    if (distance < planet->radius) {
        return 0.0; // Inside the planet, no gravitational force
    }

    double force = (G * planet->mass * object->mass) / (distance * distance);
    return force;
}

void update_object_position(Object *object, double dt) {
    object->x += object->velocity_x * dt;
    object->y += object->velocity_y * dt;
}

void update_object_velocity(Object *object, Planet *planet, double dt) {
    double force = calculate_gravitational_force(planet, object);

    if (force > 0) {
        double distance_x = object->x - planet->x;
        double distance_y = object->y - planet->y;
        double distance = sqrt(distance_x * distance_x + distance_y * distance_y);

        double acceleration = force / object->mass;
        double acceleration_x = -acceleration * (distance_x / distance);
        double acceleration_y = -acceleration * (distance_y / distance);

        object->velocity_x += acceleration_x * dt;
        object->velocity_y += acceleration_y * dt;
    }
}

void simulate(int steps, double dt, Planet *planet, Object *object) {
    for (int i = 0; i < steps; i++) {
        update_object_velocity(object, planet, dt);
        update_object_position(object, dt);

        printf("Step %d: Object Position (%.2f, %.2f) Velocity (%.2f, %.2f)\n",
                i, object->x, object->y, object->velocity_x, object->velocity_y);

        if (sqrt(pow(object->x - planet->x, 2) + pow(object->y - planet->y, 2)) < planet->radius) {
            printf("The object has collided with the planet!\n");
            break;
        }
    }
}

int main() {
    Planet earth;
    Object satellite;

    initialize_planet(&earth, 5.972e24, 6371000, 0.0, 0.0); // Earth
    initialize_object(&satellite, 1000, 0.0, 8000000, 7500, 0.0); // Satellite in low Earth orbit

    int steps = 1000; // Number of simulation steps
    double dt = 1.0; // Time step in seconds

    simulate(steps, dt, &earth, &satellite);

    return 0;
}