//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

#define G 6.67e-11 // gravitational constant

struct planet {
    char name[20];
    double mass, radius, posX, posY, velX, velY, forceX, forceY;
};

void calculateForce(struct planet *p1, struct planet *p2) {
    double dx = p2->posX - p1->posX;
    double dy = p2->posY - p1->posY;
    double dist = sqrt(dx*dx + dy*dy);
    double force = G * p1->mass * p2->mass / (dist*dist);
    p1->forceX += force * dx / dist;
    p1->forceY += force * dy / dist;
    p2->forceX -= force * dx / dist;
    p2->forceY -= force * dy / dist;
}

void updateVelocity(struct planet *p, double dt) {
    p->velX += p->forceX / p->mass * dt;
    p->velY += p->forceY / p->mass * dt;
}

void updatePosition(struct planet *p, double dt) {
    p->posX += p->velX * dt;
    p->posY += p->velY * dt;
}

void printStatus(struct planet *planets, int len) {
    for (int i = 0; i < len; i++) {
        printf("%s: pos(%e, %e) vel(%e, %e)\n", planets[i].name, planets[i].posX, planets[i].posY, planets[i].velX, planets[i].velY);
    }
}

int main() {
    struct planet planets[3] = {
        {"Earth", 5.97e24, 6.37e6, 0, 0, 0, 0, 0, 0},
        {"Moon", 7.35e22, 1.74e6, 3.84e8, 0, 0, 1024, 0, 0},
        {"Sun", 1.99e30, 6.96e8, 0, 0, 0, 0, 0, 0}
    };
    int numPlanets = sizeof(planets)/sizeof(struct planet);
    double dt = 3600; // timestep, one hour
    int numSteps = 24*365*10; // simulate 10 years
    for (int step = 0; step < numSteps; step++) {
        for (int i = 0; i < numPlanets; i++) {
            planets[i].forceX = 0;
            planets[i].forceY = 0;
            for (int j = 0; j < numPlanets; j++) {
                if (i != j) {
                    calculateForce(&planets[i], &planets[j]);
                }
            }
        }
        for (int i = 0; i < numPlanets; i++) {
            updateVelocity(&planets[i], dt);
            updatePosition(&planets[i], dt);
        }
        printf("Step %d\n", step+1);
        printStatus(planets, numPlanets);
        printf("\n");
    }
    return 0;
}