//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G_CONST 6.674e-11

typedef struct planet {
    double mass;
    double x, y;
    double vx, vy;
} planet;

int main() {
    int numPlanets;
    printf("Enter number of planets: ");
    scanf("%d", &numPlanets);

    planet *planets = malloc(numPlanets * sizeof(planet));

    for (int i = 0; i < numPlanets; i++) {
        printf("Enter mass, initial x, y, vx, and vy coordinates for planet %d: ", i+1);
        scanf("%lf %lf %lf %lf %lf", &planets[i].mass, &planets[i].x, &planets[i].y, &planets[i].vx, &planets[i].vy);
    }

    double timeStep;
    printf("Enter time step: ");
    scanf("%lf", &timeStep);

    double timeScale;
    printf("Enter time scale: ");
    scanf("%lf", &timeScale);

    double maxTime;
    printf("Enter maximum time: ");
    scanf("%lf", &maxTime);

    double elapsedTime = 0;

    while (elapsedTime < maxTime) {
        for (int i = 0; i < numPlanets; i++) {
            double fx = 0, fy = 0;

            for (int j = 0; j < numPlanets; j++) {
                if (j == i) continue;

                double dx = planets[j].x - planets[i].x;
                double dy = planets[j].y - planets[i].y;
                double distance = sqrt(dx*dx + dy*dy);

                double force = G_CONST * planets[i].mass * planets[j].mass / (distance*distance);
                fx += force * dx / distance;
                fy += force * dy / distance;
            }

            double ax = fx / planets[i].mass;
            double ay = fy / planets[i].mass;

            planets[i].vx += ax * timeStep / timeScale;
            planets[i].vy += ay * timeStep / timeScale;

            planets[i].x += planets[i].vx * timeStep / timeScale;
            planets[i].y += planets[i].vy * timeStep / timeScale;

            printf("At time %lf: Planet %d is at (%lf, %lf)\n", elapsedTime, i+1, planets[i].x, planets[i].y);
        }

        elapsedTime += timeStep / timeScale;
    }

    free(planets);

    return 0;
}