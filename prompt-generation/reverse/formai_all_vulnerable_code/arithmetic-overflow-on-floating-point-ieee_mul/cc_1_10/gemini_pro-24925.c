//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.0 // in km
#define LIGHT_SPEED 299792.458 // in km/s
#define AU_TO_KM 149597870.7 // in km

// Function to calculate the volume of a sphere
double sphere_volume(double radius) {
    return (4.0 / 3.0) * PI * pow(radius, 3);
}

// Function to calculate the surface area of a sphere
double sphere_surface_area(double radius) {
    return 4.0 * PI * pow(radius, 2);
}

// Function to calculate the probability of an alien invasion
double alien_invasion_probability(double num_stars_galaxy, double avg_num_planets_star, double avg_num_intelligent_species_planet, double avg_num_years_to_develop_spaceflight, double avg_speed_of_alien_spaceships) {
    // Calculate the number of planets in the galaxy
    double num_planets_galaxy = num_stars_galaxy * avg_num_planets_star;

    // Calculate the number of intelligent species in the galaxy
    double num_intelligent_species_galaxy = num_planets_galaxy * avg_num_intelligent_species_planet;

    // Calculate the number of years for all intelligent species to develop spaceflight
    double total_years_to_develop_spaceflight = num_intelligent_species_galaxy * avg_num_years_to_develop_spaceflight;

    // Calculate the total distance traveled by all alien spaceships
    double total_distance_traveled = total_years_to_develop_spaceflight * avg_speed_of_alien_spaceships;

    // Calculate the probability of an alien invasion
    double probability = total_distance_traveled / (4.0 * PI * pow(EARTH_RADIUS, 2));

    return probability;
}

int main() {
    // Define the input parameters
    double num_stars_galaxy = 1000000000000;
    double avg_num_planets_star = 10;
    double avg_num_intelligent_species_planet = 0.01;
    double avg_num_years_to_develop_spaceflight = 1000000;
    double avg_speed_of_alien_spaceships = 0.1 * LIGHT_SPEED;

    // Calculate the probability of an alien invasion
    double probability = alien_invasion_probability(num_stars_galaxy, avg_num_planets_star, avg_num_intelligent_species_planet, avg_num_years_to_develop_spaceflight, avg_speed_of_alien_spaceships);

    // Print the probability
    printf("Probability of an alien invasion: %e\n", probability);

    return 0;
}