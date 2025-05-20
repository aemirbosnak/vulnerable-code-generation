//GPT-4o-mini DATASET v1.0 Category: Planet Gravity Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11 // Universal gravitational constant

typedef struct {
    const char *name;
    double mass; // in kg
    double radius; // in meters
} Planet;

void displayPlanets(Planet planets[], int size) {
    printf("Choose a planet to calculate gravitational force:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s\n", i + 1, planets[i].name);
    }
    printf("Enter your choice (1 to %d): ", size);
}

double calculateGravitationalForce(double mass) {
    return (G * mass) / (mass * mass);
}

void simulateGravityOnPlanet(Planet planets[], int choice) {
    if (choice < 1 || choice > 8) {
        printf("Invalid choice! Please select a valid planet.\n");
        return;
    }
    
    Planet selectedPlanet = planets[choice - 1];
    double gravity = G * selectedPlanet.mass / (selectedPlanet.radius * selectedPlanet.radius);
    
    printf("On %s, the gravitational force is: %.2f m/s^2\n", selectedPlanet.name, gravity);
}

int main() {
    Planet planets[] = {
        {"Mercury", 3.285e23, 2.4397e6},
        {"Venus", 4.867e24, 6.0518e6},
        {"Earth", 5.972e24, 6.3710e6},
        {"Mars", 6.417e23, 3.3895e6},
        {"Jupiter", 1.898e27, 6.9911e7},
        {"Saturn", 5.683e26, 5.8232e7},
        {"Uranus", 8.681e25, 2.5362e7},
        {"Neptune", 1.024e26, 2.4622e7}
    };
    
    int planetCount = sizeof(planets) / sizeof(planets[0]);
    int choice;

    // Display available planets
    displayPlanets(planets, planetCount);
    
    // Get user choice
    scanf("%d", &choice);

    // Simulate gravity
    simulateGravityOnPlanet(planets, choice);
    
    return 0;
}