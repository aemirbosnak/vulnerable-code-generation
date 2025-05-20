//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to compute the probability of alien invasion
double calculate_probability(int year, int sightings, int tech_level) {
    double base_probability = 0.01; // Base probability of invasion
    double year_factor = (double)year / 2050; // Scale based on year
    double sightings_factor = (double)sightings / 100; // Scale based on sightings
    double tech_factor = (double)tech_level / 10; // Scale based on technology

    // Calculate the total probability
    double total_probability = base_probability * year_factor * sightings_factor * tech_factor;

    // Clamp the probability to a maximum of 1.0
    if (total_probability > 1.0) {
        total_probability = 1.0;
    }
    
    return total_probability;
}

// Function to get user input safely
int get_user_input(const char* prompt) {
    int value;
    printf("%s", prompt);
    scanf("%d", &value);
    return value;
}

// Function to display the invasion probability
void display_probability(double probability) {
    printf("The probability of alien invasion is: %.2f%%\n", probability * 100);
}

// Main function
int main() {
    int year, sightings, tech_level;
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    
    // Get the current year
    year = get_user_input("Please enter the current year (e.g., 2023): ");
    
    // Get the number of UFO sightings
    sightings = get_user_input("Please enter the number of UFO sightings reported this year: ");
    
    // Get the technology level on a scale of 1 to 10
    tech_level = get_user_input("On a scale of 1 to 10, how advanced is the technology (1 = primitive, 10 = highly advanced)? ");
    
    // Validate inputs
    if (year < 2000 || year > 2050) {
        fprintf(stderr, "Year must be between 2000 and 2050.\n");
        return EXIT_FAILURE;
    }
    
    if (sightings < 0) {
        fprintf(stderr, "Number of sightings cannot be negative.\n");
        return EXIT_FAILURE;
    }
    
    if (tech_level < 1 || tech_level > 10) {
        fprintf(stderr, "Technology level must be between 1 and 10.\n");
        return EXIT_FAILURE;
    }
    
    // Calculate probability
    double invasion_probability = calculate_probability(year, sightings, tech_level);
    
    // Display result
    display_probability(invasion_probability);
    
    printf("Thank you for using the Alien Invasion Probability Calculator. Stay safe!\n");
    
    return EXIT_SUCCESS;
}