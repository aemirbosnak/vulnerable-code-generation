//GEMINI-pro DATASET v1.0 Category: Simulation of the Solar System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Cyberpunk style variables
#define CYBERPUNK_STYLE 1

// Constants
#define G 6.674e-11 // Gravitational constant (N m^2 / kg^2)
#define AU 1.496e11 // Astronomical unit (m)
#define DAY 86400.0 // Seconds in a day
#define YEAR 31557600.0 // Seconds in a year
#define NUM_PLANETS 8 // Number of planets

// Planet data
typedef struct {
    char *name;
    double mass; // kg
    double radius; // m
    double semi_major_axis; // AU
    double eccentricity;
    double inclination; // degrees
    double longitude_of_ascending_node; // degrees
    double argument_of_periapsis; // degrees
    double mean_anomaly; // degrees
} Planet;

Planet planets[] = {
    { "Mercury", 3.30e23, 2.44e6, 0.39, 0.206, 7.00, 48.33, 77.46, 252.25 },
    { "Venus", 4.87e24, 6.05e6, 0.72, 0.007, 3.39, 76.68, 131.54, 181.98 },
    { "Earth", 5.97e24, 6.37e6, 1.00, 0.017, 0.00, 0.00, 102.93, 356.04 },
    { "Mars", 6.42e23, 3.39e6, 1.52, 0.093, 1.85, 49.56, 336.04, 18.60 },
    { "Jupiter", 1.89e27, 71.4e6, 5.20, 0.048, 1.30, 100.46, 14.76, 11.36 },
    { "Saturn", 5.68e26, 60.3e6, 9.54, 0.056, 2.48, 113.70, 92.56, 317.99 },
    { "Uranus", 8.68e25, 25.4e6, 19.22, 0.047, 0.77, 74.25, 170.96, 96.68 },
    { "Neptune", 1.02e26, 24.8e6, 30.11, 0.009, 1.77, 131.72, 44.97, 265.13 }
};

// Function prototypes
double distance(Planet *p1, Planet *p2);
void update_positions(Planet *planets, double dt);
void print_positions(Planet *planets);

int main() {
    // Set up the initial conditions
    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i].mean_anomaly = fmod(planets[i].mean_anomaly, 360.0);
    }

    // Cyberpunk style message
    if (CYBERPUNK_STYLE) {
        printf("Welcome to the Cyberpunk Solar System Simulation.\n");
        printf("You are now the master of the universe.\n");
        printf("Use the following commands to control the simulation:\n");
        printf("  - 'p' to print the positions of the planets\n");
        printf("  - 'u' to update the positions of the planets\n");
        printf("  - 'q' to quit\n");
    }

    // Main loop
    char command;
    do {
        // Prompt the user for a command
        if (CYBERPUNK_STYLE) {
            printf("> ");
        }
        scanf(" %c", &command);

        // Update the positions of the planets
        if (command == 'u') {
            update_positions(planets, 1.0);
        }

        // Print the positions of the planets
        if (command == 'p') {
            print_positions(planets);
        }
    } while (command != 'q');

    return 0;
}

// Calculate the distance between two planets
double distance(Planet *p1, Planet *p2) {
    double dx = p2->semi_major_axis * cos(p2->mean_anomaly) - p1->semi_major_axis * cos(p1->mean_anomaly);
    double dy = p2->semi_major_axis * sin(p2->mean_anomaly) - p1->semi_major_axis * sin(p1->mean_anomaly);
    double dz = p2->semi_major_axis * tan(p2->inclination) * cos(p2->mean_anomaly) - p1->semi_major_axis * tan(p1->inclination) * cos(p1->mean_anomaly);
    return sqrt(dx * dx + dy * dy + dz * dz);
}

// Update the positions of the planets
void update_positions(Planet *planets, double dt) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        // Calculate the gravitational force on planet i
        double fx = 0.0;
        double fy = 0.0;
        double fz = 0.0;
        for (int j = 0; j < NUM_PLANETS; j++) {
            if (i != j) {
                double r = distance(&planets[i], &planets[j]);
                fx += G * planets[i].mass * planets[j].mass * (planets[j].semi_major_axis * cos(planets[j].mean_anomaly) - planets[i].semi_major_axis * cos(planets[i].mean_anomaly)) / (r * r * r);
                fy += G * planets[i].mass * planets[j].mass * (planets[j].semi_major_axis * sin(planets[j].mean_anomaly) - planets[i].semi_major_axis * sin(planets[i].mean_anomaly)) / (r * r * r);
                fz += G * planets[i].mass * planets[j].mass * (planets[j].semi_major_axis * tan(planets[j].inclination) * cos(planets[j].mean_anomaly) - planets[i].semi_major_axis * tan(planets[i].inclination) * cos(planets[i].mean_anomaly)) / (r * r * r);
            }
        }

        // Update the position of planet i
        planets[i].semi_major_axis += fx * dt / planets[i].mass;
        planets[i].semi_major_axis += fy * dt / planets[i].mass;
        planets[i].semi_major_axis += fz * dt / planets[i].mass;

        // Update the mean anomaly of planet i
        planets[i].mean_anomaly += sqrt(G * planets[i].mass / pow(planets[i].semi_major_axis, 3)) * dt;
    }
}

// Print the positions of the planets
void print_positions(Planet *planets) {
    printf("\nPositions of the planets:\n");
    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("  %s: (%f, %f, %f) AU\n", planets[i].name, planets[i].semi_major_axis * cos(planets[i].mean_anomaly), planets[i].semi_major_axis * sin(planets[i].mean_anomaly), planets[i].semi_major_axis * tan(planets[i].inclination) * cos(planets[i].mean_anomaly));
    }
}