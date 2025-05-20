//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159
#define G 0.0000000000674 // Gravitational constant
#define AU 149597870700.0 // Astronomical unit
#define DAY 86400 // Number of seconds in a day

// Structure for holding planets' data
typedef struct planet {
    char name[50];
    double mass; // in kg
    double radius; // in km
    double x, y; // in km
    double vx, vy; // in km/s
    double fx, fy; // in N
} planet_t;

// Function prototypes
void calculate_forces(planet_t* p, int n);
void update_positions(planet_t* p, int n, double dt);
double calculate_distance(planet_t a, planet_t b);
void print_planets(planet_t* p, int n);

int main(void) {
    // Seed random number generator
    srand(time(NULL));

    // Initialize planets
    planet_t planets[9] = {
        {"Mercury", 3.3011e23, 2439.7, -0.3871*AU, 0, 47.87, 0, 0}, // kg, km, km/s
        {"Venus", 4.8675e24, 6051.8, -0.7233*AU, 0, 35.02, 0, 0},
        {"Earth", 5.9724e24, 6371.0, -1.0*AU, 0, 29.78, 0, 0},
        {"Mars", 6.4171e23, 3389.5, -1.5237*AU, 0, 24.077, 0, 0},
        {"Jupiter", 1.8982e27, 69911, -5.2026*AU, 0, 13.07, 0, 0},
        {"Saturn", 5.6834e26, 58232, -9.5443*AU, 0, 9.69, 0, 0},
        {"Uranus", 8.6810e25, 25362, -19.2184*AU, 0, 6.80, 0, 0},
        {"Neptune", 1.0243e26, 24622, -30.1104*AU, 0, 5.43, 0, 0},
        {"Pluto", 1.303e22, 1151, -39.4817*AU, 0, 4.67, 0, 0}
    };
    int num_planets = sizeof(planets) / sizeof(planets[0]);

    // Calculate initial forces acting on planets
    calculate_forces(planets, num_planets);

    // Print initial state
    printf("Initial state of the solar system:\n\n");
    print_planets(planets, num_planets);
    printf("\n\n");

    // Simulate solar system for one year, with timestep of one day
    double t = 0, dt = 1.0;
    while (t <= 365) {
        update_positions(planets, num_planets, dt);
        calculate_forces(planets, num_planets);
        t += dt;
    }

    // Print final state
    printf("Final state of the solar system after one year:\n\n");
    print_planets(planets, num_planets);

    return 0;
}

// Function to calculate gravitational forces between planets
void calculate_forces(planet_t* planets, int num_planets) {
    for (int i = 0; i < num_planets; i++) {
        for (int j = i+1; j < num_planets; j++) {
            double distance = calculate_distance(planets[i], planets[j]);
            double force = (G * planets[i].mass * planets[j].mass) / (distance * distance);
            double fx = force * (planets[j].x - planets[i].x) / distance;
            double fy = force * (planets[j].y - planets[i].y) / distance;
            planets[i].fx += fx;
            planets[i].fy += fy;
            planets[j].fx -= fx;
            planets[j].fy -= fy;
        }
    }
}

// Function to update positions and velocities of planets
void update_positions(planet_t* planets, int num_planets, double dt) {
    for (int i = 0; i < num_planets; i++) {
        // Update velocities
        planets[i].vx += planets[i].fx / planets[i].mass * dt;
        planets[i].vy += planets[i].fy / planets[i].mass * dt;

        // Update positions
        planets[i].x += planets[i].vx * dt;
        planets[i].y += planets[i].vy * dt;

        // Reset forces
        planets[i].fx = 0;
        planets[i].fy = 0;
    }
}

// Function to calculate distance between two planets
double calculate_distance(planet_t a, planet_t b) {
    return sqrt(pow((b.x - a.x),2) + pow((b.y - a.y),2));
}

// Function to print state of all planets
void print_planets(planet_t* planets, int num_planets) {
    for (int i = 0; i < num_planets; i++) {
        printf("%s:\n", planets[i].name);
        printf("  Position: (%.2f, %.2f) km\n", planets[i].x, planets[i].y);
        printf("  Velocity: (%.2f, %.2f) km/s\n", planets[i].vx, planets[i].vy);
    }
}