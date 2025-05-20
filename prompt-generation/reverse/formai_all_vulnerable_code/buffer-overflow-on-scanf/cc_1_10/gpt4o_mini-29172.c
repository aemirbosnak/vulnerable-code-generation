//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to compute alien invasion probability based on various factors
double calculate_invasion_probability(int population, double technological_level, double environmental_conditions) {
    // Basic probability model
    double base_probability = 0.05; // 5% base chance
    // Modify the base probability based on input factors

    // Larger populations attract attention
    double population_factor = (population / 1000000.0) * 0.02; // Influences by factor of 0.02 per million people
    // Better technology may deter or attract aliens
    double tech_factor = (technological_level / 10.0) * 0.03; // Influences by factor of 0.03 per tech level
    // Poor environmental conditions may increase vulnerability
    double env_factor = (1 - environmental_conditions) * 0.04; // Influences by factor of 0.04

    // Total invasion probability
    double total_probability = base_probability + population_factor - tech_factor + env_factor;

    // Ensure probability stays within 0 to 1
    if (total_probability < 0) total_probability = 0;
    if (total_probability > 1) total_probability = 1;

    return total_probability;
}

// Function to simulate future scenarios
void simulate_future_scenarios() {
    int years = 10;
    for (int year = 1; year <= years; year++) {
        int population = 8000000000 + year * 10000000; // annual population growth
        double technological_level = 5.0 + year * 0.1; // technological progress
        double environmental_conditions = 0.6 - year * 0.01; // slight degradation

        // Calculate the invasion probability
        double probability = calculate_invasion_probability(population, technological_level, environmental_conditions);
        printf("Year %d: Population = %d, Tech Level = %.2f, Env Cond = %.2f, Invasion Probability = %.2f%%\n",
               year + 2020, population, technological_level, environmental_conditions, probability * 100);
    }
}

// Function to get user inputs for the model
void get_user_inputs() {
    int population;
    double technological_level, environmental_conditions;

    printf("Enter the current population of your area (in millions): ");
    scanf("%d", &population);
    printf("Enter the technological advancement level (0 to 10): ");
    scanf("%lf", &technological_level);
    printf("Enter the environmental condition factor (0: poor, 1: excellent): ");
    scanf("%lf", &environmental_conditions);

    // Calculate probability based on user input
    double probability = calculate_invasion_probability(population * 1000000, technological_level, environmental_conditions);
    printf("The calculated alien invasion probability for your area is: %.2f%%\n", probability * 100);

    // Simulate future scenarios based on user input
    printf("\nSimulating future scenarios...\n");
    simulate_future_scenarios();
}

int main() {
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Let's explore the possibility of an alien invasion based on human factors.\n");
  
    get_user_inputs();

    printf("\nThank you for using the probability calculator. Stay alert!\n");
    return 0;
}