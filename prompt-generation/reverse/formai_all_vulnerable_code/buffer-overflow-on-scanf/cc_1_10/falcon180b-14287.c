//Falcon-180B DATASET v1.0 Category: Physics simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // Gravitational constant
#define dt 0.001 // Time step
#define max_steps 10000 // Maximum number of steps

struct planet {
    double x, y, vx, vy;
    double mass;
};

void force(struct planet* p1, struct planet* p2) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double r = sqrt(dx*dx + dy*dy);
    double fx = -G*p1->mass*p2->mass*dx/r/r;
    double fy = -G*p1->mass*p2->mass*dy/r/r;
    p1->vx += fx*dt;
    p1->vy += fy*dt;
    p2->vx -= fx*dt;
    p2->vy -= fy*dt;
}

void move(struct planet* p) {
    p->x += p->vx*dt;
    p->y += p->vy*dt;
}

void print_planet(struct planet* p) {
    printf("Planet: (%f, %f) Mass: %f\n", p->x, p->y, p->mass);
}

int main() {
    int n_planets;
    scanf("%d", &n_planets);
    struct planet* planets = malloc(n_planets*sizeof(struct planet));
    for (int i=0; i<n_planets; i++) {
        planets[i].x = rand()%1000;
        planets[i].y = rand()%1000;
        planets[i].vx = 0;
        planets[i].vy = 0;
        planets[i].mass = rand()%100;
    }
    int steps = 0;
    while (steps < max_steps) {
        for (int i=0; i<n_planets; i++) {
            for (int j=i+1; j<n_planets; j++) {
                force(&planets[i], &planets[j]);
            }
        }
        for (int i=0; i<n_planets; i++) {
            move(&planets[i]);
        }
        steps++;
    }
    for (int i=0; i<n_planets; i++) {
        print_planet(&planets[i]);
    }
    free(planets);
    return 0;
}