//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Structure to hold environmental factors
typedef struct {
    int climateChangeImpact;
    int technologicalAdvancement;
    int mediaInfluence;
} EnvironmentalFactors;

// Structure to hold invasion probability data
typedef struct {
    int ufoSightings;
    int activeCivilizations;
    EnvironmentalFactors factors;
    float invasionProbability;
} AlienInvasionData;

// Function to calculate invasion probability
float calculateInvasionProbability(AlienInvasionData *data) {
    // Simplified calculation for demonstration
    float baseProbability = (float)data->ufoSightings / (data->activeCivilizations + 1);
    // Weighting based on environmental factors (altered for simplicity)
    float factorWeight = (data->factors.climateChangeImpact + 
                          data->factors.technologicalAdvancement + 
                          data->factors.mediaInfluence) / 3.0f;

    data->invasionProbability = baseProbability * (1 + factorWeight / 10);
    return data->invasionProbability;
}

// Function to dynamically allocate AlienInvasionData structure
AlienInvasionData* createInvasionData() {
    AlienInvasionData *data = (AlienInvasionData *)malloc(sizeof(AlienInvasionData));
    if (!data) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    return data;
}

// Function to free the dynamically allocated memory
void freeInvasionData(AlienInvasionData *data) {
    free(data);
}

// Main function
int main() {
    // Pointer to hold invasion data
    AlienInvasionData *invasionData = createInvasionData();

    // User inputs
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    
    printf("Enter the number of UFO sightings: ");
    scanf("%d", &invasionData->ufoSightings);
    
    printf("Enter the number of active extraterrestrial civilizations: ");
    scanf("%d", &invasionData->activeCivilizations);
    
    printf("Rate the impact of climate change on a scale from 1 to 10: ");
    scanf("%d", &invasionData->factors.climateChangeImpact);
    
    printf("Rate the impact of technological advancement on a scale from 1 to 10: ");
    scanf("%d", &invasionData->factors.technologicalAdvancement);
    
    printf("Rate the influence of media coverage on a scale from 1 to 10: ");
    scanf("%d", &invasionData->factors.mediaInfluence);
    
    // Calculate invasion probability
    float probability = calculateInvasionProbability(invasionData);
    
    // Display the results
    printf("\n--- Invasion Probability Report ---\n");
    printf("UFO Sightings: %d\n", invasionData->ufoSightings);
    printf("Active Civilizations: %d\n", invasionData->activeCivilizations);
    printf("Climate Change Impact: %d\n", invasionData->factors.climateChangeImpact);
    printf("Technological Advancement Impact: %d\n", invasionData->factors.technologicalAdvancement);
    printf("Media Influence Impact: %d\n", invasionData->factors.mediaInfluence);
    printf("Estimated Alien Invasion Probability: %.2f%%\n", probability * 100);
    
    // Free dynamically allocated memory
    freeInvasionData(invasionData);
    
    return 0;
}