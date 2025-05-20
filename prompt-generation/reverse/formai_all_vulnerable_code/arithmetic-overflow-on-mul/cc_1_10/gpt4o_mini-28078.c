//GPT-4o-mini DATASET v1.0 Category: Simulation of the Solar System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define SUN_MASS          1.989e30 // kg
#define AU                1.496e11  // meters
#define SIMULATION_TIME   365 * 24 * 3600 // 1 year in seconds
#define TIME_STEP         24 * 3600 // 1 day in seconds
#define NUM_PLANETS       8

typedef struct {
    char name[20];
    float distance; // Distance from the sun in AU
    float radius;   // Radius in km
    float mass;     // Mass in kg
    float angle;    // Current angle in radians
    float angular_velocity; // Angular velocity in rad/s
} Planet;

void initialize_planets(Planet planets[]) {
    // Define the planets
    Planet mercury = {"Mercury", 0.39, 2439.7, 3.285e23, 0, 2 * M_PI / (88 * 24 * 3600)};
    Planet venus = {"Venus", 0.72, 6051.8, 4.867e24, 0, 2 * M_PI / (225 * 24 * 3600)};
    Planet earth = {"Earth", 1.0, 6371.0, 5.972e24, 0, 2 * M_PI / (365 * 24 * 3600)};
    Planet mars = {"Mars", 1.52, 3389.5, 6.417e23, 0, 2 * M_PI / (687 * 24 * 3600)};
    Planet jupiter = {"Jupiter", 5.2, 69911.0, 1.898e27, 0, 2 * M_PI / (4333 * 24 * 3600)};
    Planet saturn = {"Saturn", 9.58, 58232.0, 5.683e26, 0, 2 * M_PI / (10759 * 24 * 3600)};
    Planet uranus = {"Uranus", 19.22, 25362.0, 8.681e25, 0, 2 * M_PI / (30687 * 24 * 3600)};
    Planet neptune = {"Neptune", 30.07, 24622.0, 1.024e26, 0, 2 * M_PI / (60190 * 24 * 3600)};

    planets[0] = mercury;
    planets[1] = venus;
    planets[2] = earth;
    planets[3] = mars;
    planets[4] = jupiter;
    planets[5] = saturn;
    planets[6] = uranus;
    planets[7] = neptune;
}

void simulate_orbits(Planet planets[]) {
    float time_elapsed = 0.0;

    while (time_elapsed < SIMULATION_TIME) {
        printf("\nTime: %.2f days\n", time_elapsed / (24 * 3600));
        for (int i = 0; i < NUM_PLANETS; i++) {
            planets[i].angle += planets[i].angular_velocity * TIME_STEP;
            if (planets[i].angle >= 2 * M_PI) {
                planets[i].angle -= 2 * M_PI; // Keep the angle in range [0, 2π]
            }
            float x = planets[i].distance * AU * cos(planets[i].angle);
            float y = planets[i].distance * AU * sin(planets[i].angle);
            printf("%s: x = %.2f km, y = %.2f km\n", planets[i].name, x / 1000, y / 1000);
        }
        time_elapsed += TIME_STEP;
        sleep(1); // To slow down the output
    }
}

int main() {
    Planet planets[NUM_PLANETS];
    initialize_planets(planets);
    simulate_orbits(planets);
    return 0;
}