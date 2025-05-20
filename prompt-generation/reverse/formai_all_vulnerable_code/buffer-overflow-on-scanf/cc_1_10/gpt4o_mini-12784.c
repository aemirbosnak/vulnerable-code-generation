//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate the probability of alien invasion
double calculate_invasion_probability(int intelligence, int technology, int population) {
    double base_probability = 0.05; // A base probability of invasion
    double intelligence_factor = intelligence * 0.01; // Higher intelligence increases chance
    double technology_factor = technology * 0.02; // Higher technology raises its likelihood
    double population_factor = population * 0.001; // Larger population may attract more attention

    double total_probability = base_probability + intelligence_factor + technology_factor + population_factor;
    
    // Ensuring the probability does not exceed 1
    if (total_probability > 1.0) {
        total_probability = 1.0;
    }

    return total_probability * 100; // Return percentage
}

// Function to display a cheerful message based on invasion probability
void display_message(double probability) {
    printf("-------------------------------------------------\n");
    printf("🎉 Welcome to the Alien Invasion Probability Calculator! 🎉\n");
    printf("-------------------------------------------------\n");
    
    // Check the probability range and display corresponding messages
    if (probability == 0.0) {
        printf("🚀 Relax! Your planet is safe from alien invasions today!\n");
    } else if (probability < 25.0) {
        printf("🌎 Hmm, there’s a slight chance of alien invasion... but don’t worry too much!\n");
    } else if (probability < 50.0) {
        printf("👽 Uh-oh! There’s a moderate chance of an alien encounter! Stay vigilant!\n");
    } else if (probability < 75.0) {
        printf("🛸 Yikes! The invasion probability is getting high! Prepare your defenses!\n");
    } else {
        printf("💥 ALIEN INVASION IMMINENT! Time to gather the superheroes!\n");
    }

    printf("-------------------------------------------------\n");
}

int main() {
    int intelligence, technology, population;
    double invasion_probability;

    // Seed the random number generator
    srand(time(NULL));

    // Gather user input for planet characteristics
    printf("🌟 Let’s calculate the Alien Invasion Probability! 🌟\n");
    printf("Enter your planet's intelligence level (1-100): ");
    scanf("%d", &intelligence);
    printf("Enter your planet's technology level (1-100): ");
    scanf("%d", &technology);
    printf("Enter your planet's population size (1-1,000,000): ");
    scanf("%d", &population);

    // Validate user input
    if(intelligence < 1 || intelligence > 100 || technology < 1 || technology > 100 || population < 1 || population > 1000000) {
        printf("❗️ Invalid input! Please enter values within the specified ranges.\n");
        return 1; // Exit with an error code
    }

    // Calculate the probability of an alien invasion
    invasion_probability = calculate_invasion_probability(intelligence, technology, population);
    
    // Display the cheerful message
    display_message(invasion_probability);

    printf("✨ Thank you for using the Alien Invasion Probability Calculator! ✨\n");
    return 0; // Successful termination
}