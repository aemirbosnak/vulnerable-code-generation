//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 100

// Function prototypes
float calculate_probability(int technology_level, int population_density, int government_stability);
void get_user_input(int *technology_level, int *population_density, int *government_stability);
void display_probability(float probability);

int main() {
    int technology_level = 0, population_density = 0, government_stability = 0;
    float invasion_probability = 0.0;
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("--------------------------------------------------\n");
    
    get_user_input(&technology_level, &population_density, &government_stability);
    
    invasion_probability = calculate_probability(technology_level, population_density, government_stability);
    
    display_probability(invasion_probability);
    
    return 0;
}

// Function to calculate the invasion probability based on inputs
float calculate_probability(int technology_level, int population_density, int government_stability) {
    float base_probability = 0.02; // Base probability of invasion

    // Modifying the base probability using some simple calculations
    base_probability += (technology_level / 10.0) * 0.05; // Higher tech means higher chances
    base_probability += (population_density / 100.0) * 0.03; // Densely populated harbors more attention
    base_probability -= (government_stability / 10.0) * 0.04; // Stable governments reduce risk

    // Ensure probability is within bounds [0, 1]
    if (base_probability < 0) {
        return 0;
    } 
    else if (base_probability > 1) {
        return 1;
    }

    return base_probability;
}

// Function to get user input with validation
void get_user_input(int *technology_level, int *population_density, int *government_stability) {
    char input[MAX_INPUT_LENGTH];

    // Get technology level
    while (1) {
        printf("Enter your technology level (0-100): ");
        fgets(input, MAX_INPUT_LENGTH, stdin);
        if (sscanf(input, "%d", technology_level) == 1 && *technology_level >= 0 && *technology_level <= 100) {
            break;
        }
        printf("Invalid input. Please enter a number between 0 and 100.\n");
    }

    // Get population density
    while (1) {
        printf("Enter your population density (people per square km, 0-10000): ");
        fgets(input, MAX_INPUT_LENGTH, stdin);
        if (sscanf(input, "%d", population_density) == 1 && *population_density >= 0 && *population_density <= 10000) {
            break;
        }
        printf("Invalid input. Please enter a number between 0 and 10000.\n");
    }

    // Get government stability
    while (1) {
        printf("Enter your government stability scale (0-10): ");
        fgets(input, MAX_INPUT_LENGTH, stdin);
        if (sscanf(input, "%d", government_stability) == 1 && *government_stability >= 0 && *government_stability <= 10) {
            break;
        }
        printf("Invalid input. Please enter a number between 0 and 10.\n");
    }
}

// Function to display the calculated probability
void display_probability(float probability) {
    printf("--------------------------------------------------\n");
    printf("The calculated probability of an alien invasion is: %.2f%%\n", probability * 100);
    printf("--------------------------------------------------\n");

    if (probability < 0.1) {
        printf("Relax, you are quite safe! The aliens are not interested.\n");
    } else if (probability < 0.5) {
        printf("Caution advised! There might be alien activity in your vicinity.\n");
    } else {
        printf("High alert! Prepare for a possible alien invasion!\n");
    }
}