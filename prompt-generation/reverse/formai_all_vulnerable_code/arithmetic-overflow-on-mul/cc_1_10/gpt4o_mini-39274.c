//GPT-4o-mini DATASET v1.0 Category: Simulation of the Solar System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SOLAR_SYSTEM_SIZE 8

typedef enum {
    MERCURY, VENUS, EARTH, MARS, JUPITER, SATURN, URANUS, NEPTUNE
} Planet;

typedef struct {
    Planet name;
    double distanceFromSun; // in millions of kilometers
    double orbitalSpeed;    // in km/s
    double angle;           // angle position in orbit in degrees
} PlanetaryBody;

void initializeSolarSystem(PlanetaryBody solarSystem[]) {
    solarSystem[MERCURY] = (PlanetaryBody) {MERCURY, 57.91, 47.87, 0.0};
    solarSystem[VENUS]   = (PlanetaryBody) {VENUS, 108.2, 35.02, 0.0};
    solarSystem[EARTH]   = (PlanetaryBody) {EARTH, 149.6, 29.78, 0.0};
    solarSystem[MARS]    = (PlanetaryBody) {MARS, 227.9, 24.07, 0.0};
    solarSystem[JUPITER] = (PlanetaryBody) {JUPITER, 778.5, 13.07, 0.0};
    solarSystem[SATURN]  = (PlanetaryBody) {SATURN, 1427, 9.69, 0.0};
    solarSystem[URANUS]  = (PlanetaryBody) {URANUS, 2871, 6.81, 0.0};
    solarSystem[NEPTUNE] = (PlanetaryBody) {NEPTUNE, 4497, 5.43, 0.0};
}

void printPlanetInfo(PlanetaryBody planet) {
    const char *planetNames[] = { "Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune" };
    printf("Planet: %s\n", planetNames[planet.name]);
    printf("Distance from Sun: %.2f million km\n", planet.distanceFromSun);
    printf("Orbital Speed: %.2f km/s\n", planet.orbitalSpeed);
    printf("Current Angle: %.2f degrees\n", planet.angle);
    printf("-----------------------------------\n");
}

void updatePlanetAngles(PlanetaryBody solarSystem[]) {
    for (int i = 0; i < SOLAR_SYSTEM_SIZE; i++) {
        solarSystem[i].angle += (solarSystem[i].orbitalSpeed / 1000) * (1.0 / 60 * 60); // Update based on time
        if (solarSystem[i].angle >= 360.0) {
            solarSystem[i].angle -= 360.0; // Wrap around the angle
        }
    }
}

void displaySolarSystem(PlanetaryBody solarSystem[]) {
    printf("Current Solar System Status:\n");
    printf("-----------------------------------\n");
    for (int i = 0; i < SOLAR_SYSTEM_SIZE; i++) {
        printPlanetInfo(solarSystem[i]);
    }
}

int main() {
    // Prepare to "launch" the solar system simulation!
    printf("🚀 Welcome to the Solar System Simulation! 🌌\n");
    printf("Let’s see the planets in motion!\n\n");

    PlanetaryBody solarSystem[SOLAR_SYSTEM_SIZE];
    initializeSolarSystem(solarSystem);

    int simulationTime; // in hours
    printf("Enter the simulation time in hours: ");
    scanf("%d", &simulationTime);

    int totalSteps = simulationTime * 3600; // Total update steps (theoretical seconds)
    time_t startTime = time(NULL);

    for (int i = 0; i < totalSteps; i++) {
        updatePlanetAngles(solarSystem);
        if (i % 3600 == 0) { // Print status every hour
            printf("\nTime elapsed: %d hours\n", i / 3600);
            displaySolarSystem(solarSystem);
        }
    }

    time_t endTime = time(NULL);
    double elapsedTime = difftime(endTime, startTime);
    printf("Simulation completed in %.2f seconds!\n", elapsedTime);
    printf("🌟 Thank you for exploring the Solar System with us! 🌟\n");

    return 0;
}