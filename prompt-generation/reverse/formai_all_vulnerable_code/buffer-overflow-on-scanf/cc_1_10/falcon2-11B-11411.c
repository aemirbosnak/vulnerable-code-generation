//Falcon2-11B DATASET v1.0 Category: Simulation of the Solar System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

struct Planet {
    char name[20];
    double mass;
    double radius;
    double period;
};

struct SolarSystem {
    char name[20];
    struct Planet earth;
    struct Planet jupiter;
};

struct SolarSystem earth_sun_system = {"Earth-Sun System", {.name = "Earth",.mass = 5.972e24,.radius = 6371,.period = 365.25 * 24 * 60 * 60}, {.name = "Sun",.mass = 1.989e30,.radius = 695500,.period = 0}};

void print_planet(struct Planet planet) {
    printf("Name: %s\n", planet.name);
    printf("Mass: %.2f kg\n", planet.mass);
    printf("Radius: %.2f km\n", planet.radius);
    printf("Period: %.2f s\n", planet.period);
}

void print_solar_system(struct SolarSystem solar_system) {
    printf("Name: %s\n", solar_system.name);
    print_planet(solar_system.earth);
    print_planet(solar_system.jupiter);
}

int main() {
    struct SolarSystem solar_system;

    printf("Enter the name of the Solar System: ");
    scanf("%s", solar_system.name);

    printf("Enter the mass of the Earth: ");
    scanf("%lf", &solar_system.earth.mass);

    printf("Enter the radius of the Earth: ");
    scanf("%lf", &solar_system.earth.radius);

    printf("Enter the period of the Earth's orbit: ");
    scanf("%lf", &solar_system.earth.period);

    printf("Enter the mass of the Sun: ");
    scanf("%lf", &solar_system.jupiter.mass);

    printf("Enter the radius of the Sun: ");
    scanf("%lf", &solar_system.jupiter.radius);

    printf("Enter the period of the Sun's orbit: ");
    scanf("%lf", &solar_system.jupiter.period);

    print_solar_system(solar_system);

    return 0;
}