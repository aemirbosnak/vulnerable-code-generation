//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIGHTINGS 100
#define MAX_HISTORY 50

// Structure to hold invasion parameters
typedef struct {
    int sightings;
    int historicalEvents;
    int environmentalChanges;
} AlienData;

// Function prototypes
void gatherAlienData(AlienData *data);
float computeInvasionProbability(AlienData data);
void displayInvasionChance(float probability);
void simulateInvasionAttempt(float probability);

int main() {
    displayInvasionChance(-1.0);  // Show initial screen
    AlienData data;
    gatherAlienData(&data);  // Gather user input data
    float probability = computeInvasionProbability(data);  // Compute invasion probability

    displayInvasionChance(probability);  // Display the computed probability
    simulateInvasionAttempt(probability); // Simulate an invasion attempt

    return 0;
}

// Gather alien-related data from the user
void gatherAlienData(AlienData *data) {
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the number of alien sightings (up to %d): ", MAX_SIGHTINGS);
    scanf("%d", &data->sightings);
    
    printf("Please enter the number of historical invasion events (up to %d): ", MAX_HISTORY);
    scanf("%d", &data->historicalEvents);
    
    printf("Please enter the number of significant environmental changes (e.g. climate events): ");
    scanf("%d", &data->environmentalChanges);
}

// Compute the probability of an alien invasion
float computeInvasionProbability(AlienData data) {
    float baselineProbability = 0.05; // 5% baseline invasion chance
    float sightingFactor = data.sightings * 0.02; // Each sighting adds 2%
    float historicalFactor = data.historicalEvents * 0.1; // Each historical event adds 10%
    float environmentalFactor = data.environmentalChanges * 0.03; // Each change adds 3%

    float totalProbability = baselineProbability + sightingFactor + historicalFactor + environmentalFactor;

    // Ensure the probability does not exceed 1.0
    if (totalProbability > 1.0) {
        totalProbability = 1.0;
    }

    return totalProbability;
}

// Display the invasion chance to the user
void displayInvasionChance(float probability) {
    if (probability < 0) {
        printf("Calculating your chances...\n");
        return;
    }

    printf("\n\n*** Alien Invasion Probability Report ***\n");
    printf("Based on your input, the probability of an alien invasion is: %.2f%%\n", probability * 100);
}

// Simulate whether an invasion occurs based on calculated probability
void simulateInvasionAttempt(float probability) {
    srand(time(0)); // Seed for random generator
    float randomValue = (float)rand() / (float)RAND_MAX; // Generate random number between 0 and 1

    printf("Simulating invasion attempt...\n");
    if (randomValue < probability) {
        printf("ALERT! The aliens have invaded!\n");
    } else {
        printf("No invasion detected. All is safe for now!\n");
    }
}