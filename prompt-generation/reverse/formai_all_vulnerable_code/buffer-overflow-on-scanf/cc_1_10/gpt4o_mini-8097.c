//GPT-4o-mini DATASET v1.0 Category: Planet Gravity Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a structure for a Planet
typedef struct {
    char name[30];
    double mass;  // in kilograms
    double radius; // in meters
} Planet;

// Function to calculate gravitational force
double calculateGravity(double mass, double radius) {
    const double G = 6.67430e-11; // Gravitational constant
    return (G * mass) / (radius * radius);
}

// Function to calculate weight on the planet
double calculateWeight(double gravity, double objectMass) {
    return gravity * objectMass;
}

// Function to display information about the planet
void displayPlanetInfo(Planet planet, double gravity) {
    printf("Name: %s\n", planet.name);
    printf("Mass: %.2e kg\n", planet.mass);
    printf("Radius: %.2f meters\n", planet.radius);
    printf("Surface Gravity: %.2f m/s²\n\n", gravity);
}

int main() {
    printf("Welcome to the Planet Gravity Simulation!\n");
    printf("--------------------------------------------\n");
    printf("We are grateful to have you here today!\n\n");

    // Define a few planets
    Planet planets[3] = {
        {"Earth", 5.972e24, 6371000},
        {"Mars", 6.417e23, 3389500},
        {"Jupiter", 1.898e27, 69911000}
    };

    // Calculate and display gravity for each planet
    printf("Planet Information:\n");
    printf("--------------------\n");

    for (int i = 0; i < 3; i++) {
        double gravity = calculateGravity(planets[i].mass, planets[i].radius);
        displayPlanetInfo(planets[i], gravity);
    }

    // User input for object mass
    double objectMass;
    printf("Enter the mass of your object in kilograms: ");
    scanf("%lf", &objectMass);

    // Display weight on each planet
    printf("Weight of the object on different planets:\n");
    printf("--------------------------------------------\n");

    for (int i = 0; i < 3; i++) {
        double gravity = calculateGravity(planets[i].mass, planets[i].radius);
        double weight = calculateWeight(gravity, objectMass);
        printf("On %s: %.2f N\n", planets[i].name, weight);
    }

    printf("\nThank you for using the Planet Gravity Simulation!\n");
    printf("We appreciate your curiosity about the universe!\n");
    printf("Keep exploring and stay grateful!\n");

    return 0;
}