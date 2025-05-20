//GPT-4o-mini DATASET v1.0 Category: Simulation of the Solar System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define MAX_PLANETS 10
#define SIMULATION_STEPS 100

typedef struct {
    char name[30];
    double distance_from_sun; // in million km
    double size;              // in km
    double orbit_speed;       // in km/s
} Planet;

void initialize_planets(Planet* planets);
void print_planet_info(Planet* planet);
void simulate_orbits(Planet* planets, int steps);

int main() {
    Planet planets[MAX_PLANETS];
    initialize_planets(planets);

    printf("Simulating the Solar System:\n");
    for (int i = 0; i < MAX_PLANETS; i++) {
        print_planet_info(&planets[i]);
    }

    printf("\nStarting orbit simulation...\n");
    simulate_orbits(planets, SIMULATION_STEPS);

    return 0;
}

void initialize_planets(Planet* planets) {
    strcpy(planets[0].name, "Mercury");
    planets[0].distance_from_sun = 57.91;
    planets[0].size = 2439.7;
    planets[0].orbit_speed = 47.87;

    strcpy(planets[1].name, "Venus");
    planets[1].distance_from_sun = 108.21;
    planets[1].size = 6051.8;
    planets[1].orbit_speed = 35.02;

    strcpy(planets[2].name, "Earth");
    planets[2].distance_from_sun = 149.60;
    planets[2].size = 6371.0;
    planets[2].orbit_speed = 29.78;

    strcpy(planets[3].name, "Mars");
    planets[3].distance_from_sun = 227.92;
    planets[3].size = 3389.5;
    planets[3].orbit_speed = 24.07;

    strcpy(planets[4].name, "Jupiter");
    planets[4].distance_from_sun = 778.57;
    planets[4].size = 69911.0;
    planets[4].orbit_speed = 13.07;

    strcpy(planets[5].name, "Saturn");
    planets[5].distance_from_sun = 1433.5;
    planets[5].size = 58232.0;
    planets[5].orbit_speed = 9.69;

    strcpy(planets[6].name, "Uranus");
    planets[6].distance_from_sun = 2872.5;
    planets[6].size = 25362.0;
    planets[6].orbit_speed = 6.81;

    strcpy(planets[7].name, "Neptune");
    planets[7].distance_from_sun = 4495.1;
    planets[7].size = 24622.0;
    planets[7].orbit_speed = 5.43;

    // Add more planets if necessary
}

void print_planet_info(Planet* planet) {
    printf("Planet Name: %s\n", planet->name);
    printf("Distance from Sun: %.2f million km\n", planet->distance_from_sun);
    printf("Size: %.1f km\n", planet->size);
    printf("Orbit Speed: %.2f km/s\n\n", planet->orbit_speed);
}

void simulate_orbits(Planet* planets, int steps) {
    for (int step = 0; step < steps; step++) {
        printf("Step %d:\n", step + 1);
        for (int i = 0; i < MAX_PLANETS; i++) {
            double distance_traveled = planets[i].orbit_speed * (60 * 60 * 24); // per day
            double new_distance = planets[i].distance_from_sun + distance_traveled / 1000; // convert to million km
            printf("%s has traveled to %.2f million km from the Sun.\n", planets[i].name, new_distance);
        }
        printf("\n");
        sleep(1);
    }
}