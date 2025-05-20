//GPT-4o-mini DATASET v1.0 Category: Planet Gravity Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11 // Gravitational Constant
#define PI 3.14159265358979323846
#define MAX_PLANETS 10

typedef struct {
    char name[50];
    double mass; // in kilograms
    double radius; // in kilometers
    double distance; // distance from the Sun in kilometers
    double x; // x coordinate
    double y; // y coordinate
} Planet;

void initializePlanets(Planet *planets, int count);
void calculateGravityForces(Planet *planets, int count);
void printPlanetInfo(Planet *planets, int count);

int main() {
    int planetCount;
    Planet planets[MAX_PLANETS];
    
    printf("Welcome to the C Planet Gravity Simulation!\n");
    printf("How many planets do you wish to simulate? (Max %d): ", MAX_PLANETS);
    scanf("%d", &planetCount);

    if (planetCount <= 0 || planetCount > MAX_PLANETS) {
        printf("Oh no! Invalid number of planets. Please restart the simulation.\n");
        return 1;
    }

    initializePlanets(planets, planetCount);
    calculateGravityForces(planets, planetCount);
    printPlanetInfo(planets, planetCount);

    return 0;
}

void initializePlanets(Planet *planets, int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter the name of planet %d: ", i + 1);
        scanf("%s", planets[i].name);
        printf("Enter the mass (in kg) of %s: ", planets[i].name);
        scanf("%lf", &planets[i].mass);
        printf("Enter the radius (in km) of %s: ", planets[i].name);
        scanf("%lf", &planets[i].radius);
        printf("Enter the distance from the Sun (in km) of %s: ", planets[i].name);
        scanf("%lf", &planets[i].distance);

        // Calculate x, y coordinates assuming planets are on a circular orbit
        planets[i].x = planets[i].distance * cos(2 * PI * i / count);
        planets[i].y = planets[i].distance * sin(2 * PI * i / count);
        
        printf("\n%s initialized with position (%.2f, %.2f)\n\n", planets[i].name, planets[i].x, planets[i].y);
    }
}

void calculateGravityForces(Planet *planets, int count) {
    printf("Calculating gravitational forces between the planets...\n\n");
    for (int i = 0; i < count; i++) {
        double totalForce = 0.0;
        for (int j = 0; j < count; j++) {
            if (i != j) {
                double dx = planets[j].x - planets[i].x;
                double dy = planets[j].y - planets[i].y;
                double distance = sqrt(dx * dx + dy * dy);
                double force = (G * planets[i].mass * planets[j].mass) / (distance * distance);
                totalForce += force;
                printf("Force between %s and %s: %.2e N\n", planets[i].name, planets[j].name, force);
            }
        }
        printf("Total gravitational force on %s: %.2e N\n\n", planets[i].name, totalForce);
    }
}

void printPlanetInfo(Planet *planets, int count) {
    printf("Planet Information:\n");
    printf("%-10s | %-10s | %-10s | %-10s | %-20s\n", "Name", "Mass (kg)", "Radius (km)", "Distance (km)", "Gravitational Force");
    printf("------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-10s | %-10.2e | %-10.2f | %-10.2f | -\n", planets[i].name, planets[i].mass, planets[i].radius, planets[i].distance);
    }
}