//GPT-4o-mini DATASET v1.0 Category: Planet Gravity Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 9.81 // Gravitational acceleration (m/s^2)
#define PLANET_COUNT 3 // Total number of planets

typedef struct {
    char name[20];
    double mass; // mass in kg
    double radius; // radius in meters
} Planet;

void calculate_gravity(Planet planet, double distance, int steps);

int main() {
    Planet planets[PLANET_COUNT] = {
        {"Earth", 5.972e24, 6371000},
        {"Mars", 0.64171e24, 3389500},
        {"Venus", 4.867e24, 6051800}
    };

    printf("Welcome to the Planet Gravity Simulation!\n");
    for (int i = 0; i < PLANET_COUNT; i++) {
        printf("%d. %s\n", i + 1, planets[i].name);
    }

    int choice;
    printf("Select a planet (1-%d): ", PLANET_COUNT);
    scanf("%d", &choice);

    if (choice < 1 || choice > PLANET_COUNT) {
        printf("Invalid choice.\n");
        return 1;
    }

    double distance;
    printf("Enter the distance from the center of planet %s (in meters): ", planets[choice - 1].name);
    scanf("%lf", &distance);

    if (distance < planets[choice - 1].radius) {
        printf("You are inside the planet. Please choose a distance greater than its radius.\n");
        return 1;
    }

    printf("Calculating gravitational force at %.2f m from the center of %s...\n", distance, planets[choice - 1].name);
    calculate_gravity(planets[choice - 1], distance, 0);

    return 0;
}

void calculate_gravity(Planet planet, double distance, int steps) {
    if (distance <= planet.radius) {
        printf("You've reached the surface of %s. The gravitational force is %.2f N.\n",
               planet.name, (G * planet.mass) / (planet.radius * planet.radius));
        return;
    }

    double force = (G * planet.mass) / (distance * distance);
    printf("Step %d: Distance = %.2f m, Gravitational Force = %.2f N\n",
           steps + 1, distance, force);

    // Recur with reduced distance
    calculate_gravity(planet, distance - (planet.radius / 10), steps + 1);
}