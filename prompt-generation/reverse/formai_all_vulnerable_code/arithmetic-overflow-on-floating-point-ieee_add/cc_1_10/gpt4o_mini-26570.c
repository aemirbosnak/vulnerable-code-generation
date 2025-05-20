//GPT-4o-mini DATASET v1.0 Category: Simulation of the Solar System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h> // For sleep function

#define PI 3.14159265358979323846
#define NUM_PLANETS 8
#define SIMULATION_TIME 60 // seconds
#define TIME_STEP 1 // seconds

typedef struct {
    char name[20];
    double distance; // distance from the Sun in AU (Astronomical Units)
    double speed;    // orbit speed in degrees per second
    double angle;    // current angle in degrees
} Planet;

void initializePlanets(Planet planets[]) {
    // Initializing the planets with their respective properties
    Planet planetData[NUM_PLANETS] = {
        {"Mercury", 0.39, 4.74, 0.0},
        {"Venus", 0.72, 1.97, 0.0},
        {"Earth", 1.0, 1.0, 0.0},
        {"Mars", 1.52, 0.53, 0.0},
        {"Jupiter", 5.2, 0.084, 0.0},
        {"Saturn", 9.58, 0.034, 0.0},
        {"Uranus", 19.22, 0.011, 0.0},
        {"Neptune", 30.05, 0.006, 0.0}
    };

    for(int i = 0; i < NUM_PLANETS; i++) {
        planets[i] = planetData[i];
    }
}

void updatePlanetPosition(Planet *planet) {
    planet->angle += planet->speed * TIME_STEP; // Update angle based on speed
    if(planet->angle >= 360.0) {
        planet->angle -= 360.0; // Wrap around if angle exceeds 360 degrees
    }
}

void printPlanetPositions(Planet planets[]) {
    // Print the current angle and distance of planets from the Sun
    printf("\n--- Current Planet Positions ---\n");
    for(int i = 0; i < NUM_PLANETS; i++) {
        printf("%s: Distance: %.2f AU, Angle: %.2f degrees\n",
               planets[i].name, planets[i].distance, planets[i].angle);
    }
    printf("--------------------------------\n");
}

int main() {
    Planet planets[NUM_PLANETS];
    initializePlanets(planets); // Initialize the planets

    for(int time = 0; time < SIMULATION_TIME; time += TIME_STEP) {
        printf("\nSimulation Time: %d seconds\n", time);
        
        // Update and print positions of each planet
        for(int i = 0; i < NUM_PLANETS; i++) {
            updatePlanetPosition(&planets[i]);
        }
        printPlanetPositions(planets);
        
        // Sleep for a second to simulate time passing
        sleep(1);
    }

    return 0;
}