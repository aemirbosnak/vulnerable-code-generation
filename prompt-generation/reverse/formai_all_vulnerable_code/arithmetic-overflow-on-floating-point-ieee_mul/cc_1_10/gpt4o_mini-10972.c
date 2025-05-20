//GPT-4o-mini DATASET v1.0 Category: Planet Gravity Simulation ; Style: cheerful
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define NUM_PLANETS 5

// Define a structure to hold planet information
typedef struct {
    char name[20];    // Name of the planet
    double mass;      // Mass of the planet in kg
    double radius;    // Radius of the planet in meters
} Planet;

// Function to calculate the gravitational force
double calculate_gravity(double mass, double radius) {
    const double G = 6.67430e-11; // Gravitational constant
    return (G * mass) / (radius * radius); // Gravity formula
}

// Function to display the planets
void display_planets(Planet planets[]) {
    printf("🌍 Welcome to our Planet Gravity Simulation! 🌌\n");
    printf("Let's explore the gravity of different planets!\n");
    printf("---------------------------------------------------\n");

    for(int i = 0; i < NUM_PLANETS; i++) {
        printf("Planet: %s\n", planets[i].name);
        printf("Mass: %.2e kg\n", planets[i].mass);
        printf("Radius: %.2f m\n", planets[i].radius);
        printf("Gravity: %.2f m/s²\n", calculate_gravity(planets[i].mass, planets[i].radius));
        printf("---------------------------------------------------\n");
    }
}

// Function to simulate gravity effects on objects
void simulate_gravity_effects(Planet planet) {
    double mass_of_object;
    
    printf("Enter the mass of your object (in kg): ");
    scanf("%lf", &mass_of_object);
    
    double gravity = calculate_gravity(planet.mass, planet.radius);
    
    // Calculate the weight of the object on the specific planet
    double weight = mass_of_object * gravity;
    
    printf("On planet %s, an object with mass %.2f kg weighs %.2f N due to gravity!\n\n", planet.name, mass_of_object, weight);
}

// Main function
int main() {
    // Setup of planets with name, mass, radius
    Planet planets[NUM_PLANETS] = {
        {"Earth", 5.972e24, 6.371e6},
        {"Mars", 6.417e23, 3.3895e6},
        {"Jupiter", 1.898e27, 6.9911e7},
        {"Saturn", 5.683e26, 5.8232e7},
        {"Venus", 4.867e24, 6.0518e6}
    };

    display_planets(planets);
    
    int choice;
    printf("Which planet would you like to explore? Enter 1 for Earth, 2 for Mars, 3 for Jupiter, 4 for Saturn, 5 for Venus: ");
    scanf("%d", &choice);

    // Check for valid planet choice
    if(choice < 1 || choice > NUM_PLANETS) {
        printf("Oops! That's not a valid choice. 🤭 Let's restart!\n");
        return 1;
    }

    // Simulate gravity effects for the chosen planet
    simulate_gravity_effects(planets[choice - 1]);
    
    printf("Thank you for exploring the cosmos with us! 🚀\n");
    return 0;
}