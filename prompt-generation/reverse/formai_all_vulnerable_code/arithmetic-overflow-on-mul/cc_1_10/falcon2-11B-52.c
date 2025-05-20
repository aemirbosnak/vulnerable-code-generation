//Falcon2-11B DATASET v1.0 Category: Simulation of the Solar System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    FILE* file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    printf("Creating the Solar System...\n");

    // Initialize the planets
    int earth_radius = 6371;
    int mars_radius = 3390;
    int jupiter_radius = 71492;
    int sun_radius = 695700;

    double earth_mass = 5.972e24;
    double mars_mass = 6.4186e23;
    double jupiter_mass = 1.8986e27;
    double sun_mass = 1.9891e30;

    double earth_distance = 149.6e9;
    double mars_distance = 227.9e9;
    double jupiter_distance = 778.5e9;
    double sun_distance = 149.6e9;

    // Calculate the gravity force between planets
    double sun_gravity = 6.6743e-11;
    double earth_gravity = (sun_gravity * sun_mass) / (sun_distance * sun_distance);
    double mars_gravity = (sun_gravity * sun_mass) / (sun_distance * sun_distance);
    double jupiter_gravity = (sun_gravity * sun_mass) / (sun_distance * sun_distance);

    // Calculate the acceleration due to gravity
    double earth_acceleration = earth_gravity / (earth_radius * earth_radius);
    double mars_acceleration = mars_gravity / (mars_radius * mars_radius);
    double jupiter_acceleration = jupiter_gravity / (jupiter_radius * jupiter_radius);

    // Calculate the gravitational force between the Earth and Mars
    double earth_mars_gravity = (sun_gravity * earth_mass) / (earth_distance * earth_distance);
    double earth_mars_acceleration = earth_mars_gravity / (earth_radius * earth_radius);

    // Calculate the gravitational force between the Earth and Jupiter
    double earth_jupiter_gravity = (sun_gravity * earth_mass) / (earth_distance * earth_distance);
    double earth_jupiter_acceleration = earth_jupiter_gravity / (earth_radius * earth_radius);

    // Calculate the gravitational force between Mars and Jupiter
    double mars_jupiter_gravity = (sun_gravity * mars_mass) / (mars_distance * mars_distance);
    double mars_jupiter_acceleration = mars_jupiter_gravity / (mars_radius * mars_radius);

    // Write the results to the output file
    fprintf(file, "Gravity between the Earth and Mars: %.2f m/s^2\n", earth_mars_acceleration);
    fprintf(file, "Gravity between the Earth and Jupiter: %.2f m/s^2\n", earth_jupiter_acceleration);
    fprintf(file, "Gravity between Mars and Jupiter: %.2f m/s^2\n", mars_jupiter_acceleration);

    fclose(file);
    printf("The Solar System has been created!\n");
    return 0;
}