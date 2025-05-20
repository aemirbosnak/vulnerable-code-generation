//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 0.0000000000667 // gravitational constant

struct planet {
    double mass;
    double x, y;
    double vx, vy;
};

typedef struct planet Planet;

double distance(Planet p1, Planet p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double force(Planet p1, Planet p2) {
    double r_squared = pow(distance(p1, p2), 2);
    return G * p1.mass * p2.mass / r_squared;
}

void update_velocity(Planet *p, Planet *other, double time_step) {
    double f = force(*p, *other);
    double acceleration = f / p->mass;
    double dx = other->x - p->x;
    double dy = other->y - p->y;
    double angle = atan2(dy, dx);
    double fx = acceleration * cos(angle);
    double fy = acceleration * sin(angle);
    p->vx += fx * time_step;
    p->vy += fy * time_step;
}

void update_position(Planet *p, double time_step) {
    p->x += p->vx * time_step;
    p->y += p->vy * time_step;
}

void simulate(Planet *planets, int n, double time_step, int steps) {
    for (int step = 0; step < steps; step++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                update_velocity(&planets[i], &planets[j], time_step);
            }
        }
        for (int i = 0; i < n; i++) {
            update_position(&planets[i], time_step);
        }
    }
}

int main(void) {
    Planet planets[3] = {
        {1e10, 0, 0, 0, 0},
        {1e10, 1000, 0, 0, 100},
        {1e10, 0, 1000, -100, 0}
    };
    simulate(planets, 3, 0.001, 1000);
    for (int i = 0; i < 3; i++) {
        printf("Planet %d: x = %.2f, y = %.2f\n", i, planets[i].x, planets[i].y);
    }
    return 0;
}