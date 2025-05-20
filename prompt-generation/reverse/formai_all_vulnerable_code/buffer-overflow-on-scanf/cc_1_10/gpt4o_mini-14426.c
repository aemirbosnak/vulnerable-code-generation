//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEARS 100
#define MAX_FOOTPRINTS 1000
#define MAX_PEOPLE 100

typedef struct {
    int year;
    float ufo_sightings;
    float natural_disasters;
    float technological_advancements;
    float military_expenditure;
} AlienData;

float calculateProbability(AlienData *data) {
    float probability = 0.0;
    
    // Calculate probability based on various factors
    probability += data->ufo_sightings * 0.4;  // Weight for UFO sightings
    probability += data->natural_disasters * 0.2; // Weight for natural disasters
    probability += data->technological_advancements * 0.3; // Weight for technology
    probability += data->military_expenditure * 0.1; // Weight for military innovations

    return probability > 100.0 ? 100.0 : probability; // Cap the probability at 100%
}

void printReport(AlienData *data, int years) {
    printf("\nAlien Invasion Probability Report\n");
    printf("----------------------------------\n");
    printf("Year\t UFO Sightings\t Natural Disasters\t Tech Advancements\t Military Expenditure\t Probability\n");
    printf("------------------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < years; i++) {
        float probability = calculateProbability(&data[i]);
        printf("%d\t %.2f\t\t %.2f\t\t\t %.2f\t\t\t %.2f\t\t\t %.2f%%\n", 
               data[i].year, 
               data[i].ufo_sightings, 
               data[i].natural_disasters, 
               data[i].technological_advancements,
               data[i].military_expenditure, 
               probability);
    }
}

void simulateAlienData(AlienData *data, int years) {
    srand(time(0)); // Seed for random number generation
    
    for (int i = 0; i < years; i++) {
        data[i].year = 2020 + i; // Start from year 2020
        data[i].ufo_sightings = (rand() % MAX_FOOTPRINTS) / 10.0; // UFO sightings from 0 to 100
        data[i].natural_disasters = (rand() % MAX_FOOTPRINTS) / 10.0; // Natural disasters from 0 to 100
        data[i].technological_advancements = (rand() % MAX_FOOTPRINTS) / 10.0; // Tech advancements from 0 to 100
        data[i].military_expenditure = (rand() % MAX_FOOTPRINTS) / 10.0; // Military spending from 0 to 100
    }
}

int main() {
    AlienData data[MAX_YEARS];
    
    int years;
    printf("Enter the number of years to simulate (1 to %d): ", MAX_YEARS);
    scanf("%d", &years);
    
    if (years < 1 || years > MAX_YEARS) {
        printf("Invalid number of years. Please enter a value between 1 and %d.\n", MAX_YEARS);
        return 1; // Exit with error
    }
    
    simulateAlienData(data, years);
    printReport(data, years);

    return 0; // Exit successfully
}