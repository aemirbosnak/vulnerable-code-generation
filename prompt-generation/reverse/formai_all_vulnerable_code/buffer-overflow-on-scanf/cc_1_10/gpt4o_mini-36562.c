//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_PLANETS 8
#define MARS_DISTANCE 227.9   // million km from the sun
#define JUPITER_DISTANCE 778.6 // million km from the sun
#define SPACE_FUEL_COST_PER_KM 0.005 // cost to traverse 1 km in space

// Galactic constants
const float LIGHT_SPEED = 299792; // km/s
const int DAYS_IN_YEAR = 365;

// Structure for planets
typedef struct {
    char name[50];
    float distance; // in million kilometers
    float fuel_required; // in liters
    float travel_time; // in hours
} Planet;

// Function to calculate fuel required to travel to a planet
float calculate_fuel(float distance) {
    return distance * SPACE_FUEL_COST_PER_KM;
}

// Function to calculate travel time to a planet at light speed
float calculate_travel_time(float distance) {
    return (distance * 1e6) / LIGHT_SPEED; // converting million km to km
}

// Function to display planet information
void display_planet_info(Planet p) {
    printf("\n===================================\n");
    printf("Planet: %s\n", p.name);
    printf("Distance from Sun: %.2f million km\n", p.distance);
    printf("Fuel Required: %.2f liters\n", p.fuel_required);
    printf("Travel Time: %.2f hours or %.2f days\n", p.travel_time, p.travel_time / 24);
    printf("===================================\n");
}

// Function to perform calculations for all planets
void calculate_planets(Planet planets[]) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i].fuel_required = calculate_fuel(planets[i].distance);
        planets[i].travel_time = calculate_travel_time(planets[i].distance);
    }
}

// Atmospheric conditions simulation
void atmospheric_conditioning_simulation() {
    srand(time(NULL));
    int condition = rand() % 5;

    switch (condition) {
        case 0:
            printf("Simulation Report: Atmosphere stable, ready for interstellar jump!\n");
            break;
        case 1:
            printf("Warning: Minor turbulence detected, securing all systems!\n");
            break;
        case 2:
            printf("Alert: High radiation levels detected, activating shields!\n");
            break;
        case 3:
            printf("Notice: Proceeding with caution, gravitational anomalies found!\n");
            break;
        case 4:
            printf("All clear: Proceeding to destination.\n");
            break;
        default:
            printf("Unknown atmospheric condition!\n");
            break;
    }
}

int main() {
    Planet planets[NUM_PLANETS] = {
        {"Mercury", 57.9, 0, 0},
        {"Venus", 108.2, 0, 0},
        {"Earth", 149.6, 0, 0},
        {"Mars", 227.9, 0, 0},
        {"Jupiter", 778.6, 0, 0},
        {"Saturn", 1427, 0, 0},
        {"Uranus", 2871, 0, 0},
        {"Neptune", 4497.1, 0, 0}
    };

    printf("Welcome to the Galactic Travel Program!\n");
    printf("Calculating fuel requirements and travel times...\n");

    // Perform calculations for all defined planets
    calculate_planets(planets);

    // Display information for each planet
    for (int i = 0; i < NUM_PLANETS; i++) {
        display_planet_info(planets[i]);
    }

    // Simulate atmospheric conditions before jump
    atmospheric_conditioning_simulation();

    // Travel decision
    char choice;
    printf("Would you like to travel to a specific planet? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        char planet_name[50];
        printf("Enter the name of the planet: ");
        scanf(" %[^\n]%*c", planet_name);

        int found = 0;
        for (int i = 0; i < NUM_PLANETS; i++) {
            if (strcasecmp(planets[i].name, planet_name) == 0) {
                printf("Initiating travel to %s...\n", planets[i].name);
                printf("Fuel needed: %.2f liters\n", planets[i].fuel_required);
                printf("Estimated travel time: %.2f hours\n", planets[i].travel_time);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Planet not found in the galactic directory!\n");
        }
    } else {
        printf("Thank you for using the Galactic Travel Program. Safe travels!\n");
    }

    return 0;
}