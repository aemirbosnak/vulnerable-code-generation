//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the probability of alien invasion
double calculate_invasion_probability(int sightings, int total_population, double species_coef) {
    if (total_population <= 0) {
        fprintf(stderr, "Error: Total population must be greater than zero.\n");
        exit(EXIT_FAILURE);
    }

    double base_prob = (double)sightings / (double)total_population;
    double invasion_prob = base_prob * species_coef;
    return invasion_prob > 1.0 ? 1.0 : invasion_prob; // Probability cannot exceed 1
}

// Function to display the results
void display_results(double invasion_prob) {
    printf("The estimated probability of an alien invasion is: %.4f\n", invasion_prob);
    if (invasion_prob > 0.5) {
        printf("Warning: The probability is quite high! Prepare your defenses!\n");
    } else {
        printf("The probability is low. No immediate action is needed.\n");
    }
}

// Function to gather user inputs
void input_data(int *sightings, int *total_population, double *species_coef) {
    printf("Enter the number of alien sightings (integer): ");
    scanf("%d", sightings);
    
    printf("Enter the total population of the area (greater than zero): ");
    scanf("%d", total_population);
    
    printf("Enter the species coefficient (a floating number indicating the level of threat): ");
    scanf("%lf", species_coef);
}

// Main function
int main() {
    int sightings = 0;
    int total_population = 0;
    double species_coef = 0.0;
    
    printf("Alien Invasion Probability Calculator\n");
    printf("=====================================\n");
    
    // Input data from the user
    input_data(&sightings, &total_population, &species_coef);
    
    // Calculate the invasion probability
    double invasion_prob = calculate_invasion_probability(sightings, total_population, species_coef);
    
    // Display the results
    display_results(invasion_prob);
    
    // Additional analysis
    printf("\nAdditional Analysis:\n");
    printf("====================\n");
    
    // Analyze the effect of increased sightings
    for (int i = 1; i <= 5; i++) {
        double new_invasion_prob = calculate_invasion_probability(sightings + i, total_population, species_coef);
        printf("Probability with %d additional sighting(s): %.4f\n", i, new_invasion_prob);
    }
    
    // Analyze the effect of a changing species coefficient
    printf("\nEffect of changing species coefficient:\n");
    printf("========================================\n");
    for (double coef = 1.0; coef <= 3.0; coef += 0.5) {
        double new_invasion_prob = calculate_invasion_probability(sightings, total_population, coef);
        printf("Probability with species coefficient of %.1f: %.4f\n", coef, new_invasion_prob);
    }
    
    // Final message
    printf("\nThank you for using the Alien Invasion Probability Calculator!\n");
    printf("Stay vigilant and keep watching the skies!\n");

    return 0;
}