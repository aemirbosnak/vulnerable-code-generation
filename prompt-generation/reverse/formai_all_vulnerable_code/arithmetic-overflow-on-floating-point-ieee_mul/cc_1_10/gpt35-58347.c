//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Alan Touring
#include <stdio.h>
#include <math.h>

#define G 6.67408e-11       // gravitational constant
#define TIMESTEP 60         // simulation timestep in seconds

typedef struct {
    double x, y;            // position
    double vx, vy;          // velocity
    double ax, ay;          // acceleration
    double mass;            // mass
} Planet;

void accelerate(Planet *p1, Planet *p2) {
    double dist = sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
    double f = G * p1->mass * p2->mass / pow(dist, 2);
    double theta = atan2(p2->y - p1->y, p2->x - p1->x);
    p1->ax += f * cos(theta) / p1->mass;
    p1->ay += f * sin(theta) / p1->mass;
}

void move(Planet *p) {
    p->vx += p->ax * TIMESTEP;
    p->vy += p->ay * TIMESTEP;
    p->x += p->vx * TIMESTEP;
    p->y += p->vy * TIMESTEP;
    p->ax = 0;
    p->ay = 0;
}

int main() {
    Planet sun = {0, 0, 0, 0, 0, 1.989e30};   // mass of the Sun is 1.989 x 10^30 kg
    
    Planet planets[] = {
        {-6.9816e10, 0, 0, -29781, 5.97e24},  // Earth
        {-1.496e11, 0, 0, -10730, 6.39e23},   // Mars
        {-7.78e11, 0, 0, -34290, 1.898e27},   // Jupiter
        {-1.4297e12, 0, 0, -30560, 5.68e26}   // Saturn
    };
    
    int n = sizeof(planets) / sizeof(Planet);
    
    for (int i = 0; i < n; i++) {
        accelerate(&planets[i], &sun);
    }
    
    for (int i = 0; i < n; i++) {
        move(&planets[i]);
        printf("Planet %d: x = %.2f y = %.2f\n", i+1, planets[i].x, planets[i].y);
    }
    
    return 0;
}