//GPT-4o-mini DATASET v1.0 Category: Planet Gravity Simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_PLANETS 8

typedef struct {
    char name[20];
    double mass; // in kg
    double radius; // in meters
} Planet;

typedef struct {
    double gravitational_force; // in N
    double weight_on_planet; // in N
} GravityStats;

Planet planets[NUM_PLANETS] = {
    {"Mercury", 3.285e23, 2.4397e6},
    {"Venus", 4.867e24, 6.0518e6},
    {"Earth", 5.972e24, 6.371e6},
    {"Mars", 6.417e23, 3.3895e6},
    {"Jupiter", 1.898e27, 6.9911e7},
    {"Saturn", 5.683e26, 5.8232e7},
    {"Uranus", 8.681e25, 2.5362e7},
    {"Neptune", 1.024e26, 2.4622e7}
};

double calculate_gravitational_force(double mass, double radius) {
    const double G = 6.67430e-11; // gravitational constant in m^3 kg^-1 s^-2
    return G * mass / (radius * radius);
}

double calculate_weight_on_planet(double gravitational_force, double object_mass) {
    return gravitational_force * object_mass;
}

void print_gravity_stats(GravityStats stats[], double object_mass) {
    printf("\nGravitational Force and Weight Stats:\n");
    printf("----------------------------------------------------------\n");
    printf("| Planet      | Gravitational Force (m/s^2) | Weight (N) |\n");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("| %-11s | %-26.5f | %-10.5f |\n", planets[i].name, 
               stats[i].gravitational_force, stats[i].weight_on_planet);
    }
    printf("----------------------------------------------------------\n");
}

int main() {
    double object_mass;
    GravityStats stats[NUM_PLANETS];

    printf("Enter the mass of the object (in kg): ");
    if (scanf("%lf", &object_mass) != 1 || object_mass <= 0) {
        fprintf(stderr, "Invalid mass input. Please enter a positive number.\n");
        return 1;
    }

    // Calculate gravitational force and weight on each planet
    for (int i = 0; i < NUM_PLANETS; i++) {
        stats[i].gravitational_force = calculate_gravitational_force(planets[i].mass, planets[i].radius);
        stats[i].weight_on_planet = calculate_weight_on_planet(stats[i].gravitational_force, object_mass);
    }

    print_gravity_stats(stats, object_mass);

    return 0;
}