//Falcon-180B DATASET v1.0 Category: Simulation of the Solar System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define G 6.674e-11

// Define the solar system constants
#define SUN_MASS 1.989e30
#define SUN_RADIUS 6.957e8
#define EARTH_MASS 5.972e24
#define EARTH_RADIUS 6.371e6
#define EARTH_DISTANCE 1.496e11
#define EARTH_PERIOD 365.25
#define MOON_MASS 7.347e22
#define MOON_RADIUS 1.737e6
#define MOON_DISTANCE 3.844e8
#define MOON_PERIOD 27.32

// Define the planet structure
typedef struct {
    double mass;
    double radius;
    double distance;
    double period;
} Planet;

// Define the solar system planets
Planet planets[] = {
    {SUN_MASS, SUN_RADIUS, 0, 0},
    {EARTH_MASS, EARTH_RADIUS, EARTH_DISTANCE, EARTH_PERIOD},
    {MOON_MASS, MOON_RADIUS, MOON_DISTANCE, MOON_PERIOD}
};

// Define the number of planets
#define NUM_PLANETS 3

// Define the gravitational force function
double gravitational_force(double m1, double m2, double r) {
    return G * m1 * m2 / pow(r, 2);
}

// Define the main function
int main() {
    // Initialize the solar system
    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("Planet %d:\n", i+1);
        printf("Mass: %.2lf kg\n", planets[i].mass);
        printf("Radius: %.2lf m\n", planets[i].radius);
        printf("Distance from the Sun: %.2lf m\n", planets[i].distance);
        printf("Orbital period: %.2lf days\n\n", planets[i].period);
    }

    // Calculate the gravitational force between the Sun and Earth
    double force = gravitational_force(SUN_MASS, EARTH_MASS, EARTH_DISTANCE);
    printf("The gravitational force between the Sun and Earth is: %.2lf N\n", force);

    // Calculate the gravitational force between the Earth and the Moon
    force = gravitational_force(EARTH_MASS, MOON_MASS, MOON_DISTANCE);
    printf("The gravitational force between the Earth and the Moon is: %.2lf N\n", force);

    return 0;
}