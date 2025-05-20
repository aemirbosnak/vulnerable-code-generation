//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIGHTINGS 100

typedef struct {
    int year;
    int sightings;
} UFO_Sighting;

UFO_Sighting sightings[MAX_SIGHTINGS];
int sighting_count = 0;

void inputSightings() {
    printf("Enter number of UFO sightings: ");
    scanf("%d", &sighting_count);
    
    if(sighting_count > MAX_SIGHTINGS) {
        printf("Maximum sightings accepted is %d. Setting to maximum.\n", MAX_SIGHTINGS);
        sighting_count = MAX_SIGHTINGS;
    }
    
    for(int i = 0; i < sighting_count; i++) {
        printf("Enter year and number of sightings for record %d: ", i + 1);
        scanf("%d %d", &sightings[i].year, &sightings[i].sightings);
    }
}

float calculateProbability(int global_population) {
    int total_sightings = 0;
    
    for(int i = 0; i < sighting_count; i++) {
        total_sightings += sightings[i].sightings;
    }

    if (global_population <= 0) {
        printf("Global population must be greater than 0!\n");
        return 0;
    }
    
    return (float)total_sightings /(float)global_population * 100.0; // Returns the probability in percentage
}

void displayResults(float probability) {
    printf("--------------------------------------------------\n");
    printf("Calculated Probability of Alien Invasion: %.2f%%\n", probability);
    if (probability > 50) {
        printf("Warning: High risk of Alien Invasion!\n");
    } else {
        printf("Low risk of Alien Invasion. Enjoy your life!\n");
    }
    printf("--------------------------------------------------\n");
}

int main() {
    int global_population;
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the global population: ");
    scanf("%d", &global_population);
    
    inputSightings();
    
    float probability = calculateProbability(global_population);
    
    displayResults(probability);
    
    return 0;
}