//MISTRAL-7B DATASET v1.0 Category: Planet Gravity Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846

typedef struct {
    double x, y, vx, vy, mass;
} planet;

void gravity(planet *p1, planet *p2, double G) {
    double dx = p2->x - p1->x, dy = p2->y - p1->y;
    double distance = sqrt(dx*dx + dy*dy);

    double force_x = dx / distance * G * p2->mass;
    double force_y = dy / distance * G * p2->mass;

    p1->vx += force_x / p1->mass;
    p1->vy += force_y / p1->mass;
}

void update_position(planet *p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
}

int main() {
    int n;
    printf("Enter the number of planets: ");
    scanf("%d", &n);

    planet *planets = (planet *) malloc(n * sizeof(planet));

    double G = 6.67430e-11; // Gravitational constant
    double dt = 0.01; // Time step

    for(int i = 0; i < n; i++) {
        printf("\nEnter planet %d's coordinates (x, y), mass, initial vx and vy: ", i+1);
        scanf("%lf %lf %lf %lf %lf", &planets[i].x, &planets[i].y, &planets[i].mass, &planets[i].vx, &planets[i].vy);
    }

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            gravity(&planets[i], &planets[j], G);
        }
    }

    int steps = 10000; // Number of time steps to simulate

    for(int step = 0; step < steps; step++) {
        for(int i = 0; i < n; i++) {
            update_position(&planets[i], dt);
            for(int j = i+1; j < n; j++) {
                gravity(&planets[i], &planets[j], G);
            }
        }
    }

    printf("\nFinal positions of the planets:\n");
    for(int i = 0; i < n; i++) {
        printf("\nPlanet %d: (%.2f, %.2f)", i+1, planets[i].x, planets[i].y);
    }

    free(planets);

    return 0;
}