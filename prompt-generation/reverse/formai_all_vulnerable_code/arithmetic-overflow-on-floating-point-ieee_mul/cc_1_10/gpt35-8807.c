//FormAI DATASET v1.0 Category: Physics simulation ; Style: high level of detail
#include <stdio.h>
#include <math.h>

#define G 6.67430e-11 // gravitational constant

typedef struct {
    double x, y; // position coordinates
    double vx, vy; // velocity components
    double ax, ay; // acceleration components
    double mass; // mass of object
} Body;

// returns the distance between two bodies
double dist(Body body1, Body body2) {
    return sqrt(pow((body2.x - body1.x), 2) + pow((body2.y - body1.y), 2));
}

// calculates the gravitational force between two bodies
void force(Body *body1, Body *body2) {
    double r = dist(*body1, *body2);
    double f = (G * body1->mass * body2->mass) / pow(r, 2);
    double theta = atan2((body2->y - body1->y), (body2->x - body1->x));
    body1->ax += f * cos(theta) / body1->mass;
    body1->ay += f * sin(theta) / body1->mass;
    body2->ax -= f * cos(theta) / body2->mass;
    body2->ay -= f * sin(theta) / body2->mass;
}

// updates the velocities and positions of the bodies
void update(Body *body, double dt) {
    body->vx += body->ax * dt;
    body->vy += body->ay * dt;
    body->x += body->vx * dt;
    body->y += body->vy * dt;
    body->ax = 0; // reset acceleration for next iteration
    body->ay = 0;
}

int main() {
    // initialize bodies
    Body sun = {.mass = 1.9885e30, .x = 0, .y = 0, .vx = 0, .vy = 0};
    Body earth = {.mass = 5.972e24, .x = 1.49598e11, .y = 0, .vx = 0, .vy = 29784.8};
    double dt = 86400; // time step in seconds

    // simulation loop
    for (int i = 0; i < 365; i++) {
        force(&sun, &earth);
        update(&sun, dt);
        update(&earth, dt);
        printf("Day %d: Earth position: (%.2f, %.2f)\n", i+1, earth.x, earth.y);
    }
    return 0;
}