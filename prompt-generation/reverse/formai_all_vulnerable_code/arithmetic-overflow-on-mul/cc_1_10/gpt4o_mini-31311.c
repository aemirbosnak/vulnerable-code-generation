//GPT-4o-mini DATASET v1.0 Category: Simulation of the Solar System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

// Constants for the solar system simulation
#define NUM_PLANETS 8
#define AU_TO_METERS 1.496e11 // 1 Astronomical Unit to meters
#define TIME_STEP 1e6 // Time step in seconds for simulation

// Structure to represent a planet
typedef struct {
    char name[20];
    double distance_from_sun; // in meters
    double orbital_period; // in seconds
    double current_angle; // angle in radians
} Planet;

// Function to initialize planets
void initialize_planets(Planet *planets) {
    // Define planets in the solar system
    strcpy(planets[0].name, "Mercury");
    planets[0].distance_from_sun = 0.39 * AU_TO_METERS; 
    planets[0].orbital_period = 88 * 24 * 3600; // in seconds
    planets[0].current_angle = 0.0;

    strcpy(planets[1].name, "Venus");
    planets[1].distance_from_sun = 0.72 * AU_TO_METERS; 
    planets[1].orbital_period = 225 * 24 * 3600;
    planets[1].current_angle = 0.0;

    strcpy(planets[2].name, "Earth");
    planets[2].distance_from_sun = 1.0 * AU_TO_METERS; 
    planets[2].orbital_period = 365 * 24 * 3600;
    planets[2].current_angle = 0.0;

    strcpy(planets[3].name, "Mars");
    planets[3].distance_from_sun = 1.52 * AU_TO_METERS; 
    planets[3].orbital_period = 687 * 24 * 3600;
    planets[3].current_angle = 0.0;

    strcpy(planets[4].name, "Jupiter");
    planets[4].distance_from_sun = 5.20 * AU_TO_METERS; 
    planets[4].orbital_period = 4333 * 24 * 3600;
    planets[4].current_angle = 0.0;

    strcpy(planets[5].name, "Saturn");
    planets[5].distance_from_sun = 9.58 * AU_TO_METERS; 
    planets[5].orbital_period = 10759 * 24 * 3600;
    planets[5].current_angle = 0.0;

    strcpy(planets[6].name, "Uranus");
    planets[6].distance_from_sun = 19.22 * AU_TO_METERS; 
    planets[6].orbital_period = 30687 * 24 * 3600;
    planets[6].current_angle = 0.0;

    strcpy(planets[7].name, "Neptune");
    planets[7].distance_from_sun = 30.05 * AU_TO_METERS; 
    planets[7].orbital_period = 60190 * 24 * 3600;
    planets[7].current_angle = 0.0;
}

// Function to update the planet's position based on time
void update_planets(Planet *planets, double time) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i].current_angle += (2 * M_PI * time) / planets[i].orbital_period;
        if (planets[i].current_angle >= 2 * M_PI) {
            planets[i].current_angle -= 2 * M_PI; // Normalize the angle
        }
    }
}

// Function to print the current positions of the planets
void print_planet_positions(Planet *planets) {
    printf("\nCurrent positions of planets:\n");
    for (int i = 0; i < NUM_PLANETS; i++) {
        double x = planets[i].distance_from_sun * cos(planets[i].current_angle);
        double y = planets[i].distance_from_sun * sin(planets[i].current_angle);
        printf("%s: (x: %.2e m, y: %.2e m)\n", planets[i].name, x, y);
    }
}

int main() {
    Planet planets[NUM_PLANETS];
    initialize_planets(planets);

    double total_time = 0.0;

    // Simulate for a set duration (e.g., 5 years)
    for (int year = 0; year < 5; year++) {
        printf("\nYear %d:\n", year + 1);
        for (int t = 0; t < 365; t++) {
            update_planets(planets, TIME_STEP);
            print_planet_positions(planets);
            usleep(500000); // Sleep for half a second to simulate time passing
        }
        total_time += 365 * TIME_STEP;
    }

    return 0;
}