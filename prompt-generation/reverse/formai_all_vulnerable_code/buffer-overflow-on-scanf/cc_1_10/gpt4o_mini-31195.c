//GPT-4o-mini DATASET v1.0 Category: Simulation of the Solar System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define NUM_PLANETS 8
#define PI 3.14159265358979323846

// Planet structure
typedef struct {
    char name[20];
    double distance;  // in millions of kilometers
    double orbitalPeriod;  // in Earth days
    double angle;  // current angle in degrees
} Planet;

// Function to initialize the planets
void initializePlanets(Planet planets[]) {
    // Setting up the planets
    snprintf(planets[0].name, sizeof(planets[0].name), "Mercury");
    planets[0].distance = 57.91; // Million km
    planets[0].orbitalPeriod = 88;

    snprintf(planets[1].name, sizeof(planets[1].name), "Venus");
    planets[1].distance = 108.2; // Million km
    planets[1].orbitalPeriod = 225;

    snprintf(planets[2].name, sizeof(planets[2].name), "Earth");
    planets[2].distance = 149.6; // Million km
    planets[2].orbitalPeriod = 365;

    snprintf(planets[3].name, sizeof(planets[3].name), "Mars");
    planets[3].distance = 227.9; // Million km
    planets[3].orbitalPeriod = 687;

    snprintf(planets[4].name, sizeof(planets[4].name), "Jupiter");
    planets[4].distance = 778.5; // Million km
    planets[4].orbitalPeriod = 4333;

    snprintf(planets[5].name, sizeof(planets[5].name), "Saturn");
    planets[5].distance = 1427; // Million km
    planets[5].orbitalPeriod = 10759;

    snprintf(planets[6].name, sizeof(planets[6].name), "Uranus");
    planets[6].distance = 2871; // Million km
    planets[6].orbitalPeriod = 30687;

    snprintf(planets[7].name, sizeof(planets[7].name), "Neptune");
    planets[7].distance = 4497; // Million km
    planets[7].orbitalPeriod = 60190;
}

// Function to update the angle based on time
void updatePlanets(Planet planets[], int days) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i].angle += (360.0 / planets[i].orbitalPeriod) * days;
        if (planets[i].angle >= 360.0) {
            planets[i].angle -= 360.0;
        }
    }
}

// Function to display current positions of the planets
void displayPositions(Planet planets[]) {
    printf("\nCurrent Positions of Planets:\n");
    for (int i = 0; i < NUM_PLANETS; i++) {
        double radianAngle = planets[i].angle * (PI / 180.0);
        double x = planets[i].distance * cos(radianAngle);
        double y = planets[i].distance * sin(radianAngle);
        printf("Planet: %-10s | Distance: %.2f million km | Position (x,y): (%.2f, %.2f)\n",
                planets[i].name, planets[i].distance, x, y);
    }
}

int main() {
    Planet planets[NUM_PLANETS];
    initializePlanets(planets);

    int days;
    printf("Welcome to the Solar System Simulation!\n");

    while (1) {
        printf("\nEnter number of days to simulate (0 to exit): ");
        scanf("%d", &days);
        
        if (days <= 0) {
            break;
        }

        updatePlanets(planets, days);
        displayPositions(planets);

        // Sleep for a while before next iteration to simulate time passing
        sleep(1);
    }

    printf("Exiting Solar System Simulation. Goodbye!\n");
    return 0;
}