//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define ALIEN_THRESHOLD 0.75
#define MAX_SIGHTINGS 100
#define MAX_FACTORS 5

// Function to simulate alien sightings
void simulateAlienSightings(int sightings[], int num_sightings) {
    srand(time(0));
    for (int i = 0; i < num_sightings; i++) {
        sightings[i] = rand() % 2; // Randomly generating sightings: 0 (no) or 1 (yes)
    }
}

// Function to calculate the probability of an alien invasion
double calculateInvasionProbability(int sightings[], int num_sightings, double factors[]) {
    int alien_count = 0;

    for (int i = 0; i < num_sightings; i++) {
        if (sightings[i] == 1) {
            alien_count++;
        }
    }

    double base_probability = (double)alien_count / num_sightings;

    // Adjusting probability based on additional factors
    for (int i = 0; i < MAX_FACTORS; i++) {
        base_probability *= (1 + factors[i]); // Simple factor adjustment
    }

    // Ensure the probability does not exceed 1
    if (base_probability > 1.0) {
        base_probability = 1.0;
    }
    
    return base_probability;
}

// Function to interpret invasion probability
void interpretInvasionProbability(double probability) {
    if (probability >= ALIEN_THRESHOLD) {
        printf("Warning: Alien invasion is highly likely. Probability: %.2f\n", probability);
    } else {
        printf("All is calm. Alien invasion probability is low. Probability: %.2f\n", probability);
    }
}

// Main function
int main() {
    int num_sightings;
    int sightings[MAX_SIGHTINGS];
    double factors[MAX_FACTORS];

    // Introduction
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the number of alien sightings to simulate (up to %d): ", MAX_SIGHTINGS);
    scanf("%d", &num_sightings);

    // Safety check for input
    if (num_sightings > MAX_SIGHTINGS || num_sightings <= 0) {
        printf("Invalid number of sightings. Please restart the program and try again.\n");
        return 1;
    }

    // Get factors for invasion probability adjustment
    printf("Enter up to %d factors to consider (e.g., technological advancements, global unrest, etc.):\n", MAX_FACTORS);
    for (int i = 0; i < MAX_FACTORS; i++) {
        printf("Factor %d (as a decimal): ", i+1);
        scanf("%lf", &factors[i]);
    }

    // Simulate alien sightings
    simulateAlienSightings(sightings, num_sightings);

    // Calculate invasion probability
    double invasion_probability = calculateInvasionProbability(sightings, num_sightings, factors);

    // Output results
    printf("Simulated %d alien sightings.\n", num_sightings);
    printf("Calculated alien invasion probability: %.2f\n", invasion_probability);
    interpretInvasionProbability(invasion_probability);

    // Conclusion
    printf("Thank you for using the Alien Invasion Probability Calculator! Stay safe!\n");

    return 0;
}