//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Ada Lovelace
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Definitions
#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.01 // in kilometers
#define AU_IN_KM 149597870.700 // astronomical unit in kilometers
#define SPEED_OF_LIGHT 299792458.0 // in kilometers per second

// Function prototypes
double calculate_sphere_volume(double radius);
double calculate_sphere_surface_area(double radius);
double calculate_distance_between_earth_and_sun();
double calculate_probability_of_alien_invasion(double sphere_volume, double sphere_surface_area, double distance_to_sun, double speed_of_light);

int main() {
    // Calculate the volume of a sphere with the radius of the Earth
    double sphere_volume = calculate_sphere_volume(EARTH_RADIUS);

    // Calculate the surface area of a sphere with the radius of the Earth
    double sphere_surface_area = calculate_sphere_surface_area(EARTH_RADIUS);

    // Calculate the distance between the Earth and the Sun
    double distance_to_sun = calculate_distance_between_earth_and_sun();

    // Calculate the probability of an alien invasion
    double probability_of_alien_invasion = calculate_probability_of_alien_invasion(sphere_volume, sphere_surface_area, distance_to_sun, SPEED_OF_LIGHT);

    // Print the results
    printf("The volume of the Earth is: %.2f cubic kilometers\n", sphere_volume);
    printf("The surface area of the Earth is: %.2f square kilometers\n", sphere_surface_area);
    printf("The distance between the Earth and the Sun is: %.2f kilometers\n", distance_to_sun);
    printf("The probability of an alien invasion is: %.2f%%\n", probability_of_alien_invasion * 100);

    return 0;
}

// Function definitions

double calculate_sphere_volume(double radius) {
    return (4.0 / 3.0) * PI * pow(radius, 3);
}

double calculate_sphere_surface_area(double radius) {
    return 4.0 * PI * pow(radius, 2);
}

double calculate_distance_between_earth_and_sun() {
    return 1.0 * AU_IN_KM;
}

double calculate_probability_of_alien_invasion(double sphere_volume, double sphere_surface_area, double distance_to_sun, double speed_of_light) {
    // Calculate the volume of a sphere with the radius of the distance between the Earth and the Sun
    double sphere_volume_with_distance_to_sun = calculate_sphere_volume(distance_to_sun);

    // Calculate the probability of an alien invasion as the ratio of the volume of the sphere with the radius of the distance between the Earth and the Sun to the volume of the sphere with the radius of the Earth
    return sphere_volume_with_distance_to_sun / sphere_volume;
}