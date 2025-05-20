//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define G 6.67430e-11  // gravitational constant
#define TIME_STEP 1    // time step for the simulation
#define NUM_STEPS 100  // number of steps for simulation

typedef struct {
    double mass;      // mass of the body
    double x, y;     // position of the body
    double vx, vy;   // velocity of the body
} Body;

void initializeBody(Body *body, double mass, double x, double y, double vx, double vy) {
    body->mass = mass;
    body->x = x;
    body->y = y;
    body->vx = vx;
    body->vy = vy;
}

double calculateDistance(Body *a, Body *b) {
    return sqrt(pow(b->x - a->x, 2) + pow(b->y - a->y, 2));
}

void updatePosition(Body *body) {
    body->x += body->vx * TIME_STEP;
    body->y += body->vy * TIME_STEP;
}

void updateVelocity(Body *a, Body *b) {
    double distance = calculateDistance(a, b);
    if (distance == 0) return;  // to avoid division by zero

    double force = (G * a->mass * b->mass) / (distance * distance);

    double ax = force / a->mass * (b->x - a->x) / distance; 
    double ay = force / a->mass * (b->y - a->y) / distance;

    a->vx += ax * TIME_STEP;
    a->vy += ay * TIME_STEP;

    // Update b's velocity as well (action-reaction)
    double bx_acc = -force / b->mass * (b->x - a->x) / distance;
    double by_acc = -force / b->mass * (b->y - a->y) / distance;

    b->vx += bx_acc * TIME_STEP;
    b->vy += by_acc * TIME_STEP;
}

void printBodyState(const Body *body, int step) {
    printf("Step %d: Body mass=%.2e, Position=(%.3f, %.3f), Velocity=(%.3f, %.3f)\n", 
           step, body->mass, body->x, body->y, body->vx, body->vy);
}

int main() {
    // Create two bodies
    Body body1, body2;
    
    initializeBody(&body1, 5.0e24, -1.0e11, 0.0, 0.0, 30000.0); // Earth-like body
    initializeBody(&body2, 7.0e22, 1.0e11, 0.0, 0.0, -20000.0);  // Smaller body

    // Simulation loop
    for (int step = 0; step < NUM_STEPS; step++) {
        printBodyState(&body1, step);
        printBodyState(&body2, step);
        
        // Update velocities due to gravitational attraction
        updateVelocity(&body1, &body2);
        
        // Update positions of both bodies
        updatePosition(&body1);
        updatePosition(&body2);
        
        // Sleep to simulate time passing
        usleep(100000); // 100 ms
    }

    return 0;
}