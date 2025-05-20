//FormAI DATASET v1.0 Category: Physics simulation ; Style: satisfied
#include <stdio.h>
#include <math.h>

#define G 6.67e-11  // gravitational constant (m^3 / kg s^2)

typedef struct {
    double x;
    double y;
} Vector;

typedef struct {
    double mass;
    Vector position;
    Vector velocity;
} Body;

Body createBody(double mass, Vector position, Vector velocity) {
    Body b;
    b.mass = mass;
    b.position = position;
    b.velocity = velocity;
    return b;
}

Vector calculateForce(Body b1, Body b2) {
    double distance_squared = pow(b1.position.x - b2.position.x, 2) + pow(b1.position.y - b2.position.y, 2);
    double force_magnitude = G * b1.mass * b2.mass / distance_squared;
    Vector direction;
    direction.x = b2.position.x - b1.position.x;
    direction.y = b2.position.y - b1.position.y;
    double distance = sqrt(distance_squared);
    direction.x /= distance;
    direction.y /= distance;
    Vector force;
    force.x = force_magnitude * direction.x;
    force.y = force_magnitude * direction.y;
    return force;
}

void updateVeloctiyAndPosition(Body *b, Vector force, double time_step) {
    Vector acceleration;
    acceleration.x = force.x / b->mass;
    acceleration.y = force.y / b->mass;
    b->velocity.x += acceleration.x * time_step;
    b->velocity.y += acceleration.y * time_step;
    b->position.x += b->velocity.x * time_step;
    b->position.y += b->velocity.y * time_step;
}

int main() {
    // create bodies
    Body sun = createBody(1.989e30, (Vector) {0, 0}, (Vector) {0, 0});
    Body earth = createBody(5.972e24, (Vector) {1.496e11, 0}, (Vector) {0, 2.978e4});

    // simulate orbit for one year
    double time_step = 86400;  // one day
    double total_time = 365 * time_step;
    double current_time = 0;
    while (current_time < total_time) {
        Vector force = calculateForce(sun, earth);
        updateVeloctiyAndPosition(&earth, force, time_step);
        current_time += time_step;
    }

    // print final position of earth
    printf("Final position of Earth: (%f, %f)\n", earth.position.x, earth.position.y);

    return 0;
}