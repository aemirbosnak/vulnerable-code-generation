//FormAI DATASET v1.0 Category: Physics simulation ; Style: expert-level
#include <stdio.h>
#include <math.h>

#define GRAV_CONST 6.6743e-11 // gravitational constant (unit: m^3/kg.s^2)
#define TIME_STEP 0.1 // time step for simulation (unit: s)

// structure to define a point in 3D space
typedef struct {
    double x;
    double y;
    double z;
} point;

// structure to define an object with mass and position
typedef struct {
    double mass;
    point pos;
    point vel;
} object;

// function to calculate the distance between two objects
double distance(object obj1, object obj2) {
    double dx = obj1.pos.x - obj2.pos.x;
    double dy = obj1.pos.y - obj2.pos.y;
    double dz = obj1.pos.z - obj2.pos.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

// function to calculate the gravitational force between two objects
point gravitational_force(object obj1, object obj2) {
    double force_mag = GRAV_CONST * obj1.mass * obj2.mass / pow(distance(obj1, obj2), 2);
    double dx = obj2.pos.x - obj1.pos.x;
    double dy = obj2.pos.y - obj1.pos.y;
    double dz = obj2.pos.z - obj1.pos.z;
    point force = {force_mag * dx/distance(obj1, obj2), force_mag * dy/distance(obj1, obj2), force_mag * dz/distance(obj1, obj2)};
    return force;
}

int main() {
    // define two objects with mass and initial positions
    object obj1 = {5.97e24, {0, 0, 0}, {0, 0, 0}};
    object obj2 = {7.34e22, {3.84e8, 0, 0}, {0, 1022, 0}};

    // simulate the objects for one day
    for (int i = 1; i <= 86400/TIME_STEP; i++) {
        // calculate the gravitational force between the two objects
        point force_1_on_2 = gravitational_force(obj1, obj2);
        point force_2_on_1 = {-force_1_on_2.x, -force_1_on_2.y, -force_1_on_2.z};

        // update the velocities of the objects based on the forces
        obj1.vel.x += force_2_on_1.x/obj1.mass * TIME_STEP;
        obj1.vel.y += force_2_on_1.y/obj1.mass * TIME_STEP;
        obj1.vel.z += force_2_on_1.z/obj1.mass * TIME_STEP;
        obj2.vel.x += force_1_on_2.x/obj2.mass * TIME_STEP;
        obj2.vel.y += force_1_on_2.y/obj2.mass * TIME_STEP;
        obj2.vel.z += force_1_on_2.z/obj2.mass * TIME_STEP;

        // update the positions of the objects based on their velocities
        obj1.pos.x += obj1.vel.x * TIME_STEP;
        obj1.pos.y += obj1.vel.y * TIME_STEP;
        obj1.pos.z += obj1.vel.z * TIME_STEP;
        obj2.pos.x += obj2.vel.x * TIME_STEP;
        obj2.pos.y += obj2.vel.y * TIME_STEP;
        obj2.pos.z += obj2.vel.z * TIME_STEP;
    }

    // print the final positions of the objects
    printf("Object 1 final position: (%.2f, %.2f, %.2f)\n", obj1.pos.x, obj1.pos.y, obj1.pos.z);
    printf("Object 2 final position: (%.2f, %.2f, %.2f)\n", obj2.pos.x, obj2.pos.y, obj2.pos.z);

    return 0;
}