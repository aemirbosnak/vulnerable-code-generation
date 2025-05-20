//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ALIEN_CONTACT_PROBABILITY 0.0001  // Base probability of alien contact
#define DISASTER_MULTIPLIER 10.0            // Multiplier for disasters affecting probability
#define TECHNOLOGICAL_ADVANCE 0.00005      // Decrease in probability due to tech advance
#define POPULATION_MULTIPLIER 1.0           // Base population impact multiplier
#define YEARS_TO_SIMULATE 100                // Years to simulate for probability calculations

// Function to calculate the base probability of alien invasion
double calculate_base_probability(int year, double population, double disasters, double tech_advancements) {
    double base_probability = ALIEN_CONTACT_PROBABILITY;

    // Apply disaster multiplier
    base_probability *= (1.0 + (disasters * DISASTER_MULTIPLIER));

    // Apply technology advancement decrease
    base_probability *= (1.0 - (tech_advancements * TECHNOLOGICAL_ADVANCE));

    // Apply population impact
    base_probability *= (1.0 + (population * POPULATION_MULTIPLIER));

    // Adjust probability based on the year
    base_probability *= pow(1.0 + 0.01 * year, year / 10.0);

    return fmax(base_probability, 0.0);  // Ensure probability is always non-negative
}

// Function to gather input from the user
void gather_input(double *population, double *disasters, double *tech_advancements) {
    printf("Enter the current global population (in billions): ");
    scanf("%lf", population);
    *population *= 1e9;  // Convert to actual population    

    printf("Enter the number of natural disasters expected per year: ");
    scanf("%lf", disasters);

    printf("Enter the number of technological advancements expected per year (0 for none): ");
    scanf("%lf", tech_advancements);
}

// Function to display the result in a formatted manner
void display_result(int year, double probability) {
    printf("\nYear: %d\n", year);
    printf("Estimated probability of an alien invasion: %.10f\n", probability);
}

// Main logic to calculate the probability over the specified number of years
int main() {
    double population = 7.5;    // Example: Current population in billions
    double disasters = 0.05;     // Average number of disasters per year
    double tech_advancements = 0.15; // Average number of tech advancements

    printf("Welcome to the Alien Invasion Probability Calculator!\n");

    // Gather user inputs
    gather_input(&population, &disasters, &tech_advancements);

    printf("\nCalculating alien invasion probabilities for the next %d years...\n", YEARS_TO_SIMULATE);
    
    for (int year = 1; year <= YEARS_TO_SIMULATE; year++) {
        double invasion_probability = calculate_base_probability(year, population, disasters, tech_advancements);
        display_result(year, invasion_probability);
    }

    printf("\nSimulation complete! Keep your eyes to the skies!\n");
    return 0;
}