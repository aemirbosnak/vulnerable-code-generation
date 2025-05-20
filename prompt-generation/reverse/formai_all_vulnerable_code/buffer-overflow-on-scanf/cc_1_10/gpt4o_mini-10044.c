//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate the probability of a successful alien invasion
double calculate_invasion_probability(int alien_technology_level, int human_defense_level, int alien_numbers) {
    double base_probability = 0.25; // Base probability for alien invasion success
    double technology_factor = 1.0; // Technology factor affecting probability

    // Adjust the probability based on alien technology vs human defense levels
    if (alien_technology_level > human_defense_level) {
        technology_factor += 0.05 * (alien_technology_level - human_defense_level);
    } else {
        technology_factor -= 0.05 * (human_defense_level - alien_technology_level);
    }

    // Modify base probability with the numbers of aliens in the invasion
    base_probability *= (1 + (0.01 * alien_numbers)); 

    // Final probability calculation
    double final_probability = base_probability * technology_factor;
    
    // Ensure the probability is within 0 and 1
    if (final_probability > 1.0) {
        final_probability = 1.0;
    } else if (final_probability < 0.0) {
        final_probability = 0.0;
    }
    
    return final_probability;
}

// Function to simulate an invasion event
void simulate_invasion(int alien_technology_level, int human_defense_level, int alien_numbers) {
    double invasion_probability = calculate_invasion_probability(alien_technology_level, human_defense_level, alien_numbers);
    double random_value = (double)rand() / RAND_MAX; // Generate a random number between 0 and 1

    printf("Invasion Probability: %.2f%%\n", invasion_probability * 100);
    
    if (random_value <= invasion_probability) {
        printf("The aliens have successfully invaded!\n");
    } else {
        printf("The invasion was repelled successfully by human forces!\n");
    }
}

// Main function
int main() {
    srand(time(0)); // Seed the random number generator
    int alien_technology_level, human_defense_level, alien_numbers;

    // Prompt the user for input
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Enter the alien technology level (1-10): ");
    scanf("%d", &alien_technology_level);
    printf("Enter the human defense level (1-10): ");
    scanf("%d", &human_defense_level);
    printf("Enter the number of aliens invading: ");
    scanf("%d", &alien_numbers);

    // Validate user inputs
    if (alien_technology_level < 1 || alien_technology_level > 10) {
        printf("Invalid alien technology level! Please enter a value between 1 and 10.\n");
        return 1;
    }
    if (human_defense_level < 1 || human_defense_level > 10) {
        printf("Invalid human defense level! Please enter a value between 1 and 10.\n");
        return 1;
    }
    if (alien_numbers < 1) {
        printf("Invalid number of aliens! Please enter a positive integer.\n");
        return 1;
    }

    // Simulate the invasion
    simulate_invasion(alien_technology_level, human_defense_level, alien_numbers);
    
    // Display a summary of the input
    printf("\n--- Invasion Summary ---\n");
    printf("Alien Technology Level: %d\n", alien_technology_level);
    printf("Human Defense Level: %d\n", human_defense_level);
    printf("Number of Aliens: %d\n", alien_numbers);
    printf("------------------------\n");
    
    return 0;
}