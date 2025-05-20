//GPT-4o-mini DATASET v1.0 Category: Simulation of the Solar System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NUM_PLANETS 8

typedef struct {
    char name[20];
    float distance_from_sun; // in million km
    float diameter;          // in km
    float orbital_period;    // in Earth days
} Planet;

void initialize_planets(Planet planets[]) {
    strcpy(planets[0].name, "Mercury");
    planets[0].distance_from_sun = 57.91;
    planets[0].diameter = 4878.0;
    planets[0].orbital_period = 88.0;
    
    strcpy(planets[1].name, "Venus");
    planets[1].distance_from_sun = 108.2;
    planets[1].diameter = 12104.0;
    planets[1].orbital_period = 225.0;
    
    strcpy(planets[2].name, "Earth");
    planets[2].distance_from_sun = 149.6;
    planets[2].diameter = 12756.0;
    planets[2].orbital_period = 365.0;
    
    strcpy(planets[3].name, "Mars");
    planets[3].distance_from_sun = 227.9;
    planets[3].diameter = 6787.0;
    planets[3].orbital_period = 687.0;
    
    strcpy(planets[4].name, "Jupiter");
    planets[4].distance_from_sun = 778.5;
    planets[4].diameter = 139822.0;
    planets[4].orbital_period = 4331.0;
    
    strcpy(planets[5].name, "Saturn");
    planets[5].distance_from_sun = 1433.5;
    planets[5].diameter = 116464.0;
    planets[5].orbital_period = 10747.0;
    
    strcpy(planets[6].name, "Uranus");
    planets[6].distance_from_sun = 2872.5;
    planets[6].diameter = 50724.0;
    planets[6].orbital_period = 30589.0;

    strcpy(planets[7].name, "Neptune");
    planets[7].distance_from_sun = 4495.1;
    planets[7].diameter = 49244.0;
    planets[7].orbital_period = 59800.0;
}

void print_planet_info(Planet planets) {
    printf("\nPlanet: %s\n", planets.name);
    printf("Distance from Sun: %.2f million km\n", planets.distance_from_sun);
    printf("Diameter: %.2f km\n", planets.diameter);
    printf("Orbital Period: %.2f Earth days\n", planets.orbital_period);
}

void simulate_orbit(Planet planets[]) {
    int days;
    printf("Enter the number of days to simulate: ");
    scanf("%d", &days);

    for (int i = 0; i < NUM_PLANETS; i++) {
        float orbits_completed = days / planets[i].orbital_period;
        printf("\n%s has completed %.2f orbits around the Sun in %d days.\n", 
               planets[i].name, orbits_completed, days);
    }
}

int main() {
    Planet planets[NUM_PLANETS];
    initialize_planets(planets);

    printf("Welcome to the Solar System Simulation!\n");
    printf("Below is the list of planets in our solar system:\n");

    for (int i = 0; i < NUM_PLANETS; i++) {
        print_planet_info(planets[i]);
    }

    simulate_orbit(planets);

    printf("\nThank you for using the Solar System Simulation!\n");
    return 0;
}