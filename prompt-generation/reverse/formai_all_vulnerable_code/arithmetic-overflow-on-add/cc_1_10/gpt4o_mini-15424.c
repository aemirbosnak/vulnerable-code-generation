//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 50
#define ALIEN_STATISTICS 5

// Structure to hold various statistics about aliens
typedef struct {
    char name[20];
    double technology_level;
    double aggression_level;
    double population;
    double health_factor;
    double probability_of_invasion;
} AlienRace;

// Function to calculate the probability of invasion based on alien race's characteristics
double calculate_invasion_probability(AlienRace alien) {
    double base_probability = 0.0;

    // Weighted factors for different attributes
    base_probability += alien.technology_level * 0.3;
    base_probability += alien.aggression_level * 0.5;
    base_probability += alien.population * 0.2;
    base_probability *= alien.health_factor;

    // Clamp the probability to a maximum of 100%
    return (base_probability > 100.0) ? 100.0 : base_probability;
}

// Function to simulate alien encounters for a given planet
void simulate_planet_encounters(int planet_id) {
    AlienRace alien;
    srand(time(NULL) + planet_id);  // Random seed based on planet ID
    snprintf(alien.name, sizeof(alien.name), "Alien_%d", planet_id);
    alien.technology_level = (rand() % 100) / 100.0;  // Random technology between 0.0 and 1.0
    alien.aggression_level = (rand() % 100) / 100.0;   // Random aggression between 0.0 and 1.0
    alien.population = rand() % 10000;                 // Random population
    alien.health_factor = (rand() % 100) / 100.0 + 0.5; // Random factor between 0.5 and 1.5

    // Calculate invasion probability
    alien.probability_of_invasion = calculate_invasion_probability(alien);

    // Output the results
    printf("Planet ID: %d\n", planet_id);
    printf("Alien Race: %s\n", alien.name);
    printf("Technology Level: %.2f\n", alien.technology_level);
    printf("Aggression Level: %.2f\n", alien.aggression_level);
    printf("Population: %.0f\n", alien.population);
    printf("Health Factor: %.2f\n", alien.health_factor);
    printf("Invasion Probability: %.2f%%\n\n", alien.probability_of_invasion);
}

int main() {
    int num_planets;

    // Prompt user for the number of planets to simulate
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Enter the number of planets to simulate (1-%d): ", MAX_PLANETS);
    scanf("%d", &num_planets);

    // Validate input
    if(num_planets < 1 || num_planets > MAX_PLANETS) {
        printf("Invalid number of planets! Please enter a number between 1 and %d.\n", MAX_PLANETS);
        return 1;
    }

    // Simulate encounters for each planet
    for(int i = 0; i < num_planets; i++) {
        simulate_planet_encounters(i + 1);
    }

    printf("Thank you for using the Alien Invasion Probability Calculator!\n");

    return 0;
}