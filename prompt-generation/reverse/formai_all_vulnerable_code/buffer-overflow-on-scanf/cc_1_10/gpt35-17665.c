//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: authentic
#include <stdio.h>
#include <math.h>

#define G 6.67384e-11 // gravitational constant

struct Planet {
    double x, y; // position of planet
    double vx, vy; // velocity of planet
    double mass; // mass of planet
};

void velocity_update(struct Planet *p1, struct Planet *p2) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double distance = sqrt(dx*dx + dy*dy);
    
    double force = G * p1->mass * p2->mass / (distance * distance);

    double fx = force * dx / distance;
    double fy = force * dy / distance;

    p1->vx += fx / p1->mass;
    p1->vy += fy / p1->mass;
    p2->vx -= fx / p2->mass;
    p2->vy -= fy / p2->mass;
}

void position_update(struct Planet *p, double time_step) {
    p->x += p->vx * time_step;
    p->y += p->vy * time_step;
}

int main() {
    int num_planets;
    printf("Enter number of planets: ");
    scanf("%d", &num_planets);

    struct Planet planets[num_planets];
    for (int i = 0; i < num_planets; i++) {
        printf("Enter mass and initial position (x, y) for planet %d: ", i+1);
        scanf("%lf %lf %lf", &planets[i].mass, &planets[i].x, &planets[i].y);
        printf("Enter initial velocity (vx, vy) for planet %d: ", i+1);
        scanf("%lf %lf", &planets[i].vx, &planets[i].vy);
    }

    double time_step;
    printf("Enter time step for simulation: ");
    scanf("%lf", &time_step);

    int num_steps;
    printf("Enter number of simulation steps: ");
    scanf("%d", &num_steps);

    for (int step = 0; step < num_steps; step++) {
        for (int i = 0; i < num_planets; i++) {
            for (int j = i+1; j < num_planets; j++) {
                velocity_update(&planets[i], &planets[j]);
            }
        }
        for (int i = 0; i < num_planets; i++) {
            position_update(&planets[i], time_step);
        }
    }

    printf("Final positions:\n");
    for (int i = 0; i < num_planets; i++) {
        printf("Planet %d: (%.3lf, %.3lf)\n", i+1, planets[i].x, planets[i].y);
    }

    return 0;
}