//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOOING_COWS 3
#define SPACESHIPS 2
#define DAYS 30
#define ALIEN_VISITS 1.5 // average number of alien visits per day

// Function to calculate the expected number of alien visits
double calculate_expected_visits(int days, double visits_per_day) {
    return days * visits_per_day;
}

// Function to simulate alien invasion probability based on number of friendly factors
double calculate_probability_of_invasion(int friendly_cows, double expected_visits) {
    // The more friendly cows, the higher the probability of a peaceful interaction
    double base_probability = 0.1; // 10% base chance
    double friendly_factor = (double)friendly_cows / (MOOING_COWS + SPACESHIPS);
    double invasion_probability = base_probability * (1 - friendly_factor) * expected_visits;

    if (invasion_probability < 0) {
        invasion_probability = 0;
    } else if (invasion_probability > 1) {
        invasion_probability = 1;
    }

    return invasion_probability;
}

// Function to simulate and display the friendly alien contact based on probability
void simulate_alien_contact(double invasion_probability) {
    double random_value = (double)rand() / RAND_MAX; // Generate a random value between 0 and 1

    if (random_value < invasion_probability) {
        printf("An alien invasion was detected! Be kind and peaceful!\n");
    } else {
        printf("The aliens decided to be friendly and went back to space peacefully.\n");
    }
}

// Entry point for the Alien Invasion Probability Calculator
int main() {
    printf("==== Welcome to the Peaceful Alien Invasion Probability Calculator ====\n\n");
    
    srand(time(NULL)); // Seed the random number generator

    // Step 1: Calculate expected alien visits
    double expected_visits = calculate_expected_visits(DAYS, ALIEN_VISITS);
    printf("Expected alien visits over %d days: %.2f\n\n", DAYS, expected_visits);

    // Step 2: Gather information about the number of friendly cows
    int friendly_cows = 0;
    printf("How many friendly cows do you have? (0-%d): ", MOOING_COWS);
    scanf("%d", &friendly_cows);
    
    // Ensure friendly cows are within a valid range
    if (friendly_cows < 0 || friendly_cows > MOOING_COWS) {
        printf("You entered a wrong number of friendly cows. Setting it to 0.\n");
        friendly_cows = 0;
    }

    // Step 3: Calculate invasion probability
    double invasion_probability = calculate_probability_of_invasion(friendly_cows, expected_visits);
    printf("Calculated invasion probability based on friendly cows (%d): %.2f\n\n", friendly_cows, invasion_probability);

    // Step 4: Simulate potential alien contact
    simulate_alien_contact(invasion_probability);

    printf("\nThank you for using the Peaceful Alien Invasion Probability Calculator.\n");
    return 0;
}