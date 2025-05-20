//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UNIVERSE_SIZE 1000000000000
#define ALIENS_PER_GALAXY 1000000

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the variables
    int num_galaxies = 0;
    int num_aliens = 0;
    int num_planets = 0;
    int num_invaded_planets = 0;
    double invasion_probability = 0.0;

    // Get the number of galaxies
    printf("Enter the number of galaxies: ");
    scanf("%d", &num_galaxies);

    // Get the number of aliens per galaxy
    printf("Enter the number of aliens per galaxy: ");
    scanf("%d", &num_aliens);

    // Get the number of planets per galaxy
    printf("Enter the number of planets per galaxy: ");
    scanf("%d", &num_planets);

    // Calculate the number of aliens
    num_aliens = num_galaxies * num_aliens;

    // Calculate the number of planets
    num_planets = num_galaxies * num_planets;

    // Calculate the invasion probability
    invasion_probability = (double)num_aliens / (double)num_planets;

    // Print the results
    printf("Number of galaxies: %d\n", num_galaxies);
    printf("Number of aliens: %d\n", num_aliens);
    printf("Number of planets: %d\n", num_planets);
    printf("Invasion probability: %f\n", invasion_probability);

    // Check if the invasion probability is greater than 0.5
    if (invasion_probability > 0.5) {
        printf("The probability of an alien invasion is high.\n");
    } else {
        printf("The probability of an alien invasion is low.\n");
    }

    return 0;
}