//GPT-4o-mini DATASET v1.0 Category: Planet Gravity Simulation ; Style: retro
#include <stdio.h>
#include <math.h>

#define G 6.67430e-11 // Gravitational constant in m^3 kg^-1 s^-2

// Function to calculate gravitational acceleration
double calculate_gravity(double mass, double radius) {
    return G * mass / (radius * radius);
}

// Function to display the welcome message
void display_welcome() {
    printf("===================================\n");
    printf("  Welcome to the Gravity Simulator  \n");
    printf("===================================\n");
}

// Function to display the instructions
void display_instructions() {
    printf("Enter the mass of the planet in kilograms:\n");
    printf("Enter the radius of the planet in meters:\n");
    printf("We will calculate the gravitational acceleration!\n");
}

int main() {
    double mass, radius, gravity;

    // Display welcome message
    display_welcome();
    display_instructions();

    // Read user input for mass and radius
    printf("Mass: ");
    if (scanf("%lf", &mass) != 1 || mass <= 0) {
        printf("Invalid mass input. Please enter a positive number.\n");
        return 1;
    }
    
    printf("Radius: ");
    if (scanf("%lf", &radius) != 1 || radius <= 0) {
        printf("Invalid radius input. Please enter a positive number.\n");
        return 1;
    }

    // Calculate gravitational acceleration
    gravity = calculate_gravity(mass, radius);

    // Display the results
    printf("\n===================================\n");
    printf("  Gravitational Acceleration       \n");
    printf("===================================\n");
    printf("For a planet with:\n");
    printf("Mass: %.2e kg\n", mass);
    printf("Radius: %.2f m\n", radius);
    printf("The gravitational acceleration is: %.2f m/s²\n", gravity);
    printf("===================================\n");

    // Display retro styled exit message
    printf("Thank you for using the Gravity Simulator!\n");
    printf("Created by Your Retro Developer!\n");
    printf("===================================\n");

    return 0;
}