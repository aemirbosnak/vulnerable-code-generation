//GPT-4o-mini DATASET v1.0 Category: Planet Gravity Simulation ; Style: surprised
#include <stdio.h>
#include <math.h>

#define G 6.67430e-11 // Universal gravitational constant

// Structure to represent a planet
typedef struct {
    char name[50];
    double mass;  // in kilograms
    double distance;  // distance from a reference point in meters
} Planet;

// Function to calculate gravitational force
double calculateGravitationalForce(Planet p1, Planet p2) {
    double distanceBetween = fabs(p1.distance - p2.distance);
    if (distanceBetween == 0) {
        printf("Oh no! The planets are in the same position! Infinite force!\n");
        return HUGE_VAL; // Return infinity to indicate the situation
    }
    return (G * p1.mass * p2.mass) / (distanceBetween * distanceBetween);
}

// Function to display planet information
void displayPlanetInfo(Planet planet) {
    printf("Planet Name: %s\n", planet.name);
    printf("Mass: %.2e kg\n", planet.mass);
    printf("Distance from reference point: %.2f m\n", planet.distance);
}

int main() {
    printf("Welcome to the Planet Gravity Simulation!\n");

    Planet planet1, planet2;

    // Input for Planet 1
    printf("Enter the name of Planet 1: ");
    scanf("%s", planet1.name);
    
    printf("Enter the mass of %s (in kg): ", planet1.name);
    scanf("%lf", &planet1.mass);
    
    printf("Enter the distance of %s from the reference point (in meters): ", planet1.name);
    scanf("%lf", &planet1.distance);

    // Input for Planet 2
    printf("Enter the name of Planet 2: ");
    scanf("%s", planet2.name);
    
    printf("Enter the mass of %s (in kg): ", planet2.name);
    scanf("%lf", &planet2.mass);
    
    printf("Enter the distance of %s from the reference point (in meters): ", planet2.name);
    scanf("%lf", &planet2.distance);

    // Display planet information
    printf("\n--- Planet Information ---\n");
    displayPlanetInfo(planet1);
    printf("\n");
    displayPlanetInfo(planet2);
    
    // Calculate gravitational force
    double gravitationalForce = calculateGravitationalForce(planet1, planet2);
    printf("\nThe gravitational force between %s and %s is: %.2e N\n", planet1.name, planet2.name, gravitationalForce);

    // Check for special situations
    if (gravitationalForce == HUGE_VAL) {
        printf("Watch out! You have created a massive collision zone!\n");
    } else if (gravitationalForce < 1e-6) {
        printf("The gravitational force is negligibly small. These planets are far apart!\n");
    } else {
        printf("The gravitational intensity is significant; planets are feeling each other's pull!\n");
    }

    printf("\nThanks for using the simulation! Explore the cosmos responsibly!\n");
    return 0;
}