//GPT-4o-mini DATASET v1.0 Category: Planet Gravity Simulation ; Style: recursive
#include <stdio.h>
#include <math.h>

#define G 6.67430e-11 // Gravitational constant

typedef struct {
    char name[20];
    double mass;    // in kg
    double posX;    // x position in meters
    double posY;    // y position in meters
} Planet;

void calculateGravitationalForces(Planet *planets, int n, int index);
void printForce(double forceX, double forceY, Planet current);

int main() {
    Planet planets[] = {
        {"Earth", 5.972e24, 0, 0},
        {"Mars", 6.417e23, 225e9, 0},
        {"Venus", 4.867e24, 41.4e9, 108.2e9},
        {"Jupiter", 1.898e27, 778.5e9, 0}
    };
    
    int numPlanets = sizeof(planets) / sizeof(planets[0]);

    // Start the recursive calculation of forces for each planet
    for (int i = 0; i < numPlanets; i++) {
        calculateGravitationalForces(planets, numPlanets, i);
    }

    return 0;
}

void calculateGravitationalForces(Planet *planets, int n, int index) {
    // Base case for the recursion: if there are no other planets to compare, return
    if (index >= n) {
        return;
    }

    Planet current = planets[index];
    double totalForceX = 0.0;
    double totalForceY = 0.0;

    for (int i = 0; i < n; i++) {
        if (i != index) {
            double deltaX = planets[i].posX - current.posX;
            double deltaY = planets[i].posY - current.posY;
            double distance = sqrt(deltaX * deltaX + deltaY * deltaY);
            
            // Avoid division by zero
            if (distance > 0) {
                double force = (G * current.mass * planets[i].mass) / (distance * distance);
                totalForceX += force * (deltaX / distance);
                totalForceY += force * (deltaY / distance);
            }
        }
    }
    
    printForce(totalForceX, totalForceY, current);

    // Recursive call to the next planet
    calculateGravitationalForces(planets, n, index + 1);
}

void printForce(double forceX, double forceY, Planet current) {
    printf("Total gravitational force on %s: \n", current.name);
    printf("Force X component: %.2e N\n", forceX);
    printf("Force Y component: %.2e N\n", forceY);
    printf("-----------------------------\n");
}