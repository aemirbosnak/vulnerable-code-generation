//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ALERT_LEVEL 100

// Function prototypes
void display_intro();
int calculate_probability(int population, int technology_level, int alert_level);
int simulate_extraterrestrial_event(int base_probability);
void display_results(int probability, int alien_invasion_occurrence);

int main() {
    int population, technology_level, alert_level;
    int invasion_probability, alien_invasion_occurrence;

    display_intro();

    // Collect inputs from the user
    printf("Enter the total population on Earth: ");
    scanf("%d", &population);
    
    printf("Enter the current technology level (0-10): ");
    scanf("%d", &technology_level);
    
    printf("Enter the alert level (0-100): ");
    scanf("%d", &alert_level);

    // Validate inputs
    if (population <= 0 || technology_level < 0 || technology_level > 10 || alert_level < 0 || alert_level > MAX_ALERT_LEVEL) {
        printf("Invalid input data. Please ensure all inputs are in the correct range.\n");
        return 1;
    }

    // Calculate invasion probability
    invasion_probability = calculate_probability(population, technology_level, alert_level);

    // Simulate if an alien invasion occurs based on the calculated probability
    alien_invasion_occurrence = simulate_extraterrestrial_event(invasion_probability);

    // Display the results
    display_results(invasion_probability, alien_invasion_occurrence);

    return 0;
}

// Function to display introduction
void display_intro() {
    printf("========================================\n");
    printf("      Alien Invasion Probability       \n");
    printf("           Calculator                  \n");
    printf("========================================\n");
    printf("Evaluate the possibility of an alien invasion\n");
}

// Function to calculate the invasion probability
int calculate_probability(int population, int technology_level, int alert_level) {
    // Applying a basic formula to calculate invasion probability
    int base_probability = (population / 1000000) * (10 - technology_level) * (alert_level / 10);
    if (base_probability > 100) base_probability = 100; // Cap the probability at 100%
    return base_probability;
}

// Function to simulate the alien invasion occurrence
int simulate_extraterrestrial_event(int base_probability) {
    srand(time(NULL)); // Seed the random number generator
    int random_value = rand() % 100; // Generate a random number between 0 and 99

    // If the random value is less than the base probability, invasion occurs
    return (random_value < base_probability) ? 1 : 0;
}

// Function to display the results
void display_results(int probability, int alien_invasion_occurrence) {
    printf("\n========================================\n");
    printf("Invasion Probability: %d%%\n", probability);
    
    if (alien_invasion_occurrence) {
        printf("Warning: An alien invasion is likely to occur!\n");
    } else {
        printf("Good news: An alien invasion is unlikely at this moment.\n");
    }
    
    printf("========================================\n");
}