//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate probability of alien invasion based on input factors
double calculate_probability(int technology_level, int defense_strength, int population_density) {
    // Constants to influence calculation
    const double BASE_PROBABILITY = 0.05; // base probability of invasion
    const double TECH_MULTIPLIER = 0.02; // influence of technology
    const double DEFENSE_MULTIPLIER = 0.01; // influence of defense
    const double DENSITY_MULTIPLIER = 0.03; // influence of population density

    // Calculate adjusted probability
    double probability = BASE_PROBABILITY + 
                        (technology_level * TECH_MULTIPLIER) - 
                        (defense_strength * DEFENSE_MULTIPLIER) + 
                        (population_density * DENSITY_MULTIPLIER);

    // Clamp probability between 0 and 1
    if (probability < 0) probability = 0;
    if (probability > 1) probability = 1;

    return probability;
}

// Function to generate a random integer between min and max
int random_integer(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to run the alien invasion simulation
void run_simulation() {
    int technology_level;
    int defense_strength;
    int population_density;
    double invasion_probability;

    // Prompt user for input parameters
    printf("Enter technology level (1-10): ");
    scanf("%d", &technology_level);
    printf("Enter defense strength (1-10): ");
    scanf("%d", &defense_strength);
    printf("Enter population density (1-10): ");
    scanf("%d", &population_density);

    // Validate input
    if (technology_level < 1 || technology_level > 10 ||
        defense_strength < 1 || defense_strength > 10 ||
        population_density < 1 || population_density > 10) {
        printf("Error: All inputs must be between 1 and 10.\n");
        return;
    }

    // Calculate invasion probability
    invasion_probability = calculate_probability(technology_level, defense_strength, population_density);
    printf("The calculated probability of an alien invasion is: %.2f\n", invasion_probability);

    // Determine outcome based on probability
    double random_value = (double)rand() / RAND_MAX; // Generate random float between 0 and 1
    if (random_value < invasion_probability) {
        printf("Alert! An alien invasion is imminent!\n");
    } else {
        printf("All clear! No alien invasion in sight.\n");
    }
}

// Main function
int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Run the alien invasion simulation
    run_simulation();

    return 0;
}