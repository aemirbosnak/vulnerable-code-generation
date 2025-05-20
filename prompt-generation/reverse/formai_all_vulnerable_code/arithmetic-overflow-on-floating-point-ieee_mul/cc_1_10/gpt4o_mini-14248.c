//GPT-4o-mini DATASET v1.0 Category: Simulation of the Solar System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define NUM_PLANETS 8
#define SIMULATION_STEPS 100
#define TIME_STEP 0.1 // in Earth's years
#define AU 149597870.7 // 1 Astronomical Unit in kilometers

typedef struct {
    char name[20];
    double distance; // distance from the sun in AU
    double radius; // radius in kilometers
    double orbit_period; // in Earth years
    double angle; // current angle in radians
} Planet;

void initializePlanets(Planet planets[]) {
    // Initializing planets with distance (in AU), radius (in km), and orbital period (in years)
    snprintf(planets[0].name, sizeof(planets[0].name), "Mercury");
    planets[0].distance = 0.39;
    planets[0].radius = 2439.7;
    planets[0].orbit_period = 0.241;

    snprintf(planets[1].name, sizeof(planets[1].name), "Venus");
    planets[1].distance = 0.72;
    planets[1].radius = 6051.8;
    planets[1].orbit_period = 0.615;

    snprintf(planets[2].name, sizeof(planets[2].name), "Earth");
    planets[2].distance = 1.0;
    planets[2].radius = 6371.0;
    planets[2].orbit_period = 1.0;

    snprintf(planets[3].name, sizeof(planets[3].name), "Mars");
    planets[3].distance = 1.52;
    planets[3].radius = 3389.5;
    planets[3].orbit_period = 1.881;

    snprintf(planets[4].name, sizeof(planets[4].name), "Jupiter");
    planets[4].distance = 5.2;
    planets[4].radius = 69911;
    planets[4].orbit_period = 11.861;

    snprintf(planets[5].name, sizeof(planets[5].name), "Saturn");
    planets[5].distance = 9.58;
    planets[5].radius = 58232;
    planets[5].orbit_period = 29.456;

    snprintf(planets[6].name, sizeof(planets[6].name), "Uranus");
    planets[6].distance = 19.18;
    planets[6].radius = 25362;
    planets[6].orbit_period = 84.018;

    snprintf(planets[7].name, sizeof(planets[7].name), "Neptune");
    planets[7].distance = 30.07;
    planets[7].radius = 24622;
    planets[7].orbit_period = 164.8;
}

void updatePlanetAngles(Planet planets[]) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i].angle += (2 * M_PI * TIME_STEP) / planets[i].orbit_period; // radians
        // Ensure the angle is within 0 to 2*PI
        if (planets[i].angle >= 2 * M_PI) {
            planets[i].angle -= 2 * M_PI;
        }
    }
}

void displaySolarSystem(Planet planets[], int step) {
    printf("Step %3d:\n", step);
    for (int i = 0; i < NUM_PLANETS; i++) {
        double x = planets[i].distance * AU * cos(planets[i].angle);
        double y = planets[i].distance * AU * sin(planets[i].angle);
        printf("  %s: Distance from Sun: %.2f AU (%.2f km), Position: (%.2f, %.2f)\n",
               planets[i].name, planets[i].distance, planets[i].distance * AU, x, y);
    }
    printf("\n");
}

int main() {
    Planet planets[NUM_PLANETS];
    initializePlanets(planets);

    for (int step = 0; step < SIMULATION_STEPS; step++) {
        displaySolarSystem(planets, step);
        updatePlanetAngles(planets);
        usleep(500000); // Sleep for half a second
    }

    return 0;
}