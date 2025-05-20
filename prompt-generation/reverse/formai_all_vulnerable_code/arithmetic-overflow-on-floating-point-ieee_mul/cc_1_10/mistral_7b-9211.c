//MISTRAL-7B DATASET v1.0 Category: Planet Gravity Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979323846
#define G 6.6743e-11 // gravitational constant

typedef struct {
    double x, y, mass, vx, vy;
} planet;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void update_velocities(planet *p1, planet *p2) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;

    double mag = G * (p1->mass * p2->mass) / pow(dist(p1->x, p1->y, p2->x, p2->y), 2);

    p1->vx -= mag * dx / dist(p1->x, p1->y, p2->x, p2->y);
    p1->vy -= mag * dy / dist(p1->x, p1->y, p2->x, p2->y);

    p2->vx += mag * dx / dist(p1->x, p1->y, p2->x, p2->y);
    p2->vy += mag * dy / dist(p1->x, p1->y, p2->x, p2->y);
}

void update_positions(planet *p1, planet *p2, double dt) {
    double old_x1 = p1->x;
    double old_y1 = p1->y;

    p1->x += p1->vx * dt;
    p1->y += p1->vy * dt;

    p2->x += p2->vx * dt;
    p2->y += p2->vy * dt;

    update_velocities(p1, p2);
}

void print_planets(planet p1, planet p2) {
    printf("Planet 1: (%lf, %lf) vx=%lf vy=%lf mass=%lf\n", p1.x, p1.y, p1.vx, p1.vy, p1.mass);
    printf("Planet 2: (%lf, %lf) vx=%lf vy=%lf mass=%lf\n", p2.x, p2.y, p2.vx, p2.vy, p2.mass);
}

int main() {
    planet p1 = { 0, 0, 1e24, 0, 0 };
    planet p2 = { 5e11, 0, 5e24, 0, 0 };

    double dt = 1e6;
    int steps = 10;

    for (int i = 0; i < steps; ++i) {
        printf("\nStep %d:\n", i);
        print_planets(p1, p2);
        update_positions(&p1, &p2, dt);
    }

    return 0;
}