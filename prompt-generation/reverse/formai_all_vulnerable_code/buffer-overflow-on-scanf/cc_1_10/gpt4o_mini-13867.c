//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
double calculate_base_probability(int population, int technology_level);
double adjust_probability_for_location(double base_prob, const char *location);
void get_user_input(int *population, int *technology_level, char *location);
void display_results(double invasion_probability);

int main() {
    int population = 0;
    int technology_level = 0;
    char location[50];
    
    // Seed the random number generator
    srand(time(NULL));

    // Get user input for parameters
    get_user_input(&population, &technology_level, location);
    
    // Calculate the base probability of an alien invasion
    double base_probability = calculate_base_probability(population, technology_level);
    
    // Adjust the probability based on the user's location
    double invasion_probability = adjust_probability_for_location(base_probability, location);
    
    // Display the final results
    display_results(invasion_probability);
    
    return 0;
}

// Function to calculate base probability of alien invasion
double calculate_base_probability(int population, int technology_level) {
    // A simple model for base probability
    if (population <= 0 || technology_level < 0) {
        return 0.0; // Invalid input
    }

    // Base probability calculation
    double base_prob = (population * 0.0001) + (technology_level * 0.01);
    
    // Random factor to introduce variability
    base_prob *= ((double)rand() / RAND_MAX);
    
    return base_prob > 1.0 ? 1.0 : base_prob; // Cap at 1.0
}

// Function to adjust probability based on location
double adjust_probability_for_location(double base_prob, const char *location) {
    // Different adjustment values for different locations
    if (strcmp(location, "urban") == 0) {
        return base_prob * 1.5; // Higher risk in urban areas
    } else if (strcmp(location, "rural") == 0) {
        return base_prob * 0.75; // Lower risk in rural areas
    } else if (strcmp(location, "coastal") == 0) {
        return base_prob * 1.2; // Moderate increase for coastal areas
    }
    // Default if no specific location adjustment
    return base_prob;
}

// Function to get user input safely
void get_user_input(int *population, int *technology_level, char *location) {
    printf("Enter the world population (in millions): ");
    while (scanf("%d", population) != 1 || *population < 0) {
        printf("Invalid input. Please enter a positive integer: ");
        while(getchar() != '\n'); // Clear invalid input
    }

    printf("Enter technology level (1-10): ");
    while (scanf("%d", technology_level) != 1 || *technology_level < 1 || *technology_level > 10) {
        printf("Invalid input. Please enter a value between 1 and 10: ");
        while(getchar() != '\n'); // Clear invalid input
    }

    // Clear the buffer before reading string
    while(getchar() != '\n');

    printf("Enter your location (urban/rural/coastal): ");
    fgets(location, 50, stdin);
    location[strcspn(location, "\n")] = 0; // Remove newline character
}

// Function to display the results
void display_results(double invasion_probability) {
    printf("The probability of an alien invasion is: %.2f%%\n", invasion_probability * 100);
}