//GPT-4o-mini DATASET v1.0 Category: Planet Gravity Simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_PLANETS 5
#define G 6.67430e-11 // Gravitational constant

typedef struct {
    char name[50];
    double mass;     // in kilograms
    double radius;   // in meters
    double distance; // from the observer in meters
} Planet;

void initializePlanets(Planet *planets, int count) {
    const char* names[MAX_PLANETS] = {"Neo-Terra", "Byteworld", "Cyberion", "Dark Matrix", "Synth-4"};
    srand(time(0));

    for (int i = 0; i < count; i++) {
        snprintf(planets[i].name, sizeof(planets[i].name), "%s", names[i]);
        planets[i].mass = (rand() % 100 + 10) * 1e24; // mass between 10e24kg to 110e24kg
        planets[i].radius = (rand() % 60 + 10) * 1e6;  // radius between 10e6m to 70e6m
        planets[i].distance = (rand() % 100 + 1) * 1e9; // distance between 1e9m to 101e9m
    }
}

double calculateGravity(double mass, double radius) {
    return G * mass / (radius * radius);
}

void displayPlanets(Planet *planets, int count) {
    printf("Welcome to the Cyberpunk Planet Gravity Simulation!\n");
    printf("---------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        double gravity = calculateGravity(planets[i].mass, planets[i].radius);
        printf("Planet: %s\n", planets[i].name);
        printf("Mass: %.2e kg\n", planets[i].mass);
        printf("Radius: %.2e m\n", planets[i].radius);
        printf("Distance from observer: %.2e m\n", planets[i].distance);
        printf("Surface Gravity: %.2f m/s²\n", gravity);
        printf("---------------------------------------------------\n");
    }
}

void simulateGravityEffect(Planet *planets, int count) {
    printf("Simulating gravitational interactions...\n");
    
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            double force = (G * planets[i].mass * planets[j].mass) / (planets[i].distance - planets[j].distance);
            printf("Gravitational force between %s and %s: %.2e N\n",
                   planets[i].name, planets[j].name, force);
        }
    }
}

int main() {
    Planet planets[MAX_PLANETS];
    initializePlanets(planets, MAX_PLANETS);
    displayPlanets(planets, MAX_PLANETS);
    simulateGravityEffect(planets, MAX_PLANETS);
    
    printf("End of simulation. Probing deeper into the unknown...\n");
    return 0;
}