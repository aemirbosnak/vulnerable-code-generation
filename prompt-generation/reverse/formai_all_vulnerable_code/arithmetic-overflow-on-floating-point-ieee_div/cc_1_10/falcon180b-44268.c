//Falcon-180B DATASET v1.0 Category: Planet Gravity Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define G 6.674e-11 // gravitational constant

// define the planet class
typedef struct {
    double x, y, vx, vy, ax, ay, mass;
} Planet;

// function to calculate the force between two planets
void calc_force(Planet* p1, Planet* p2) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double r = sqrt(dx*dx + dy*dy);
    double f = G * p1->mass * p2->mass / (r*r);
    p1->ax -= dx * f / r;
    p1->ay -= dy * f / r;
    p2->ax += dx * f / r;
    p2->ay += dy * f / r;
}

// function to update the position of a planet
void update_position(Planet* p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
}

// function to update the velocity of a planet
void update_velocity(Planet* p, double dt) {
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
}

// function to draw a planet
void draw_planet(Planet* p) {
    printf("%.2f, %.2f\n", p->x, p->y);
}

// main function
int main() {
    // initialize the planets
    Planet earth = {0, 0, 0, 0, 0, 0, 5.972e24};
    Planet moon = {384400, 0, 0, 0, 0, 0, 7.347e22};
    Planet sun = {0, 0, 0, 0, 0, 0, 1.988e30};

    // initialize the simulation
    double dt = 0.01;
    int steps = 1000;
    srand(time(NULL));

    // simulate the gravity
    for (int i = 0; i < steps; i++) {
        calc_force(&earth, &moon);
        calc_force(&earth, &sun);
        calc_force(&moon, &earth);
        calc_force(&moon, &sun);
        calc_force(&sun, &earth);
        calc_force(&sun, &moon);
        update_position(&earth, dt);
        update_position(&moon, dt);
        update_position(&sun, dt);
        update_velocity(&earth, dt);
        update_velocity(&moon, dt);
        update_velocity(&sun, dt);
    }

    // draw the planets
    draw_planet(&earth);
    draw_planet(&moon);
    draw_planet(&sun);

    return 0;
}