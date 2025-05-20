//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIGHTINGS 1000
#define MAX_UNREST 100
#define MAX_REPORTS 100

typedef struct {
    int sightings;
    int unrestIndex;
    int scientificReports;
} AlienMetrics;

float calculateProbability(AlienMetrics metrics) {
    float probability = 0.0;
    
    // Normalize values to a scale of 0 to 1
    float sightingsFactor = (float) metrics.sightings / MAX_SIGHTINGS;
    float unrestFactor = (float) metrics.unrestIndex / MAX_UNREST;
    float reportsFactor = (float) metrics.scientificReports / MAX_REPORTS;

    // Simple formula for probability (can be adjusted)
    probability = (sightingsFactor * 0.5) + (unrestFactor * 0.3) + (reportsFactor * 0.2);

    // Adjusting probability to fit within a 0-100 scale
    return probability * 100;
}

void displayResults(float probability) {
    printf("\n--- Alien Invasion Probability Calculator ---\n");
    printf("Calculated Probability: %.2f%%\n", probability);
    printf("Interpretation:\n");
    if (probability == 0) {
        printf("No chance of invasion detected.\n");
    } else if (probability < 25) {
        printf("Low probability of invasion.\n");
    } else if (probability < 50) {
        printf("Moderate probability of invasion, stay alert!\n");
    } else if (probability < 75) {
        printf("High probability of invasion, prepare defensively!\n");
    } else {
        printf("Very high probability of invasion! Immediate action required!\n");
    }
    printf("-----------------------------------------------\n");
}

int main() {
    AlienMetrics metrics;
    char continueCalc;

    srand(time(NULL)); // Seed for randomness

    printf("Welcome to the Alien Invasion Probability Calculator!\n");

    do {
        // Input UFO sightings
        printf("Enter the number of UFO sightings (0 - %d): ", MAX_SIGHTINGS);
        scanf("%d", &metrics.sightings);
        if (metrics.sightings < 0 || metrics.sightings > MAX_SIGHTINGS) {
            printf("Please enter a valid number of sightings.\n");
            continue;
        }

        // Input global unrest index
        printf("Enter global unrest index (0 - %d): ", MAX_UNREST);
        scanf("%d", &metrics.unrestIndex);
        if (metrics.unrestIndex < 0 || metrics.unrestIndex > MAX_UNREST) {
            printf("Please enter a valid unrest index.\n");
            continue;
        }

        // Input scientific reports
        printf("Enter the number of scientific reports on extraterrestrial life (0 - %d): ", MAX_REPORTS);
        scanf("%d", &metrics.scientificReports);
        if (metrics.scientificReports < 0 || metrics.scientificReports > MAX_REPORTS) {
            printf("Please enter a valid number of reports.\n");
            continue;
        }

        // Calculate probability based on inputs
        float invasionProbability = calculateProbability(metrics);
        displayResults(invasionProbability);

        // Ask user if they want to perform another calculation
        printf("Do you want to calculate again? (y/n): ");
        scanf(" %c", &continueCalc);
    } while (continueCalc == 'y' || continueCalc == 'Y');

    printf("Thank you for using the Alien Invasion Probability Calculator!\n");
    return 0;
}