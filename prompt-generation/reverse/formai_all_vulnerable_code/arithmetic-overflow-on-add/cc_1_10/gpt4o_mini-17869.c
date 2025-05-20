//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate the probability of an alien invasion based on various parameters
double calculate_invasion_probability(int sightings, int technology_level, int human_morality, int climate_stability) {
    // The formula to calculate the probability is purely speculative and for entertainment
    // Purpose: Probability = (sightings * technology_factor) / (morality_factor * climate_factor)
    const double technology_factor = (technology_level / 10.0) + 1; // 1 to 11
    const double morality_factor = (human_morality / 10.0) + 1; // 1 to 11
    const double climate_factor = (climate_stability / 10.0) + 1; // 1 to 11

    double probability = (sightings * technology_factor) / (morality_factor * climate_factor);
    return probability < 1.0 ? probability : 1.0; // Cap at 1.0
}

// Function to simulate random alien sightings for a given year range
int simulate_alien_sightings(int start_year, int end_year) {
    srand(time(NULL)); // Seed random number generator with current time
    int years = end_year - start_year + 1;
    return rand() % (years * 5); // Assume 0 to 5 sightings per year on average
}

// Function to get user input for parameters
void get_user_input(int *sightings, int *technology_level, int *human_morality, int *climate_stability) {
    printf("Enter the number of alien sightings in the last year: ");
    scanf("%d", sightings);
    printf("Rate technology level (1 to 10): ");
    scanf("%d", technology_level);
    printf("Rate human morality (1 to 10): ");
    scanf("%d", human_morality);
    printf("Rate climate stability (1 to 10): ");
    scanf("%d", climate_stability);
}

// Function to display the invasion probability analysis
void display_analysis(double probability) {
    printf("Based on your inputs, the calculated probability of an alien invasion is: %.2f\n", probability * 100);
    if (probability > 0.8) {
        printf("Warning: High risk of alien invasion! Take precautions.\n");
    } else if (probability > 0.5) {
        printf("Caution: Moderate risk of alien invasion. Stay alert.\n");
    } else {
        printf("Low risk of alien invasion. You may carry on with your life.\n");
    }
}

// Main function to run the calculator
int main() {
    int sightings;
    int technology_level;
    int human_morality;
    int climate_stability;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Let's gather some information to determine the threat level of an alien invasion.\n");
    
    // Get user parameters
    get_user_input(&sightings, &technology_level, &human_morality, &climate_stability);
    
    // Simulate sightings for a given year range
    int simulated_sightings = simulate_alien_sightings(2020, 2023);
    printf("Simulated alien sightings from 2020 to 2023: %d\n", simulated_sightings);
    
    // Calculate the probability of invasion
    double invasion_probability = calculate_invasion_probability(sightings + simulated_sightings, 
                                                                technology_level, 
                                                                human_morality,
                                                                climate_stability);

    // Display analysis to the user
    display_analysis(invasion_probability);

    return 0;
}