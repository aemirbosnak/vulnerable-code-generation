//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIGHTINGS 100

typedef struct {
    int sightingId;
    double distanceFromEarth; // in light-years
    int duration; // in days of observation
    double environmentalFactor; // 0 - 1 range for environmental conditions favoring invasion
} Sighting;

typedef struct {
    Sighting observations[MAX_SIGHTINGS];
    int count;
} SightingData;

void addSighting(SightingData *data, int id, double distance, int duration, double envFactor) {
    if (data->count < MAX_SIGHTINGS) {
        data->observations[data->count].sightingId = id;
        data->observations[data->count].distanceFromEarth = distance;
        data->observations[data->count].duration = duration;
        data->observations[data->count].environmentalFactor = envFactor;
        data->count++;
    } else {
        printf("Maximum number of sightings reached!\n");
    }
}

double calculateProbability(SightingData *data) {
    double totalProbability = 0.0;
    
    for (int i = 0; i < data->count; i++) {
        Sighting *sight = &data->observations[i];
        double sightingProbability = (1.0 / sight->distanceFromEarth) * 
                                     (sight->duration / 30.0) * 
                                     sight->environmentalFactor;
        totalProbability += sightingProbability;
    }
    
    return totalProbability / data->count; // Average probability
}

void displaySightings(SightingData *data) {
    printf("\nSightings Information:\n");
    for (int i = 0; i < data->count; i++) {
        printf("Sighting #%d: Distance - %.2f light-years, Duration - %d days, Environmental Factor - %.2f\n",
               data->observations[i].sightingId,
               data->observations[i].distanceFromEarth,
               data->observations[i].duration,
               data->observations[i].environmentalFactor);
    }
}

int main() {
    SightingData sightings = {.count = 0};
    char choice;
   
    printf("Welcome to the Alien Invasion Probability Calculator!\n");

    while (1) {
        int id, duration;
        double distance, envFactor;

        printf("Enter Sighting ID (integer): ");
        scanf("%d", &id);
        
        printf("Enter Distance from Earth (in light-years): ");
        scanf("%lf", &distance);
        if (distance <= 0) {
            printf("Error: Distance must be a positive value.\n");
            continue;
        }

        printf("Enter Observation Duration (in days): ");
        scanf("%d", &duration);
        if (duration <= 0) {
            printf("Error: Duration must be a positive integer.\n");
            continue;
        }

        printf("Enter Environmental Factor (0 to 1): ");
        scanf("%lf", &envFactor);
        if (envFactor < 0 || envFactor > 1) {
            printf("Error: Environmental Factor must be between 0 and 1.\n");
            continue;
        }

        addSighting(&sightings, id, distance, duration, envFactor);
        printf("Sighting added successfully!\n");

        printf("Would you like to add another sighting? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    displaySightings(&sightings);
    
    if (sightings.count > 0) {
        double probability = calculateProbability(&sightings);
        printf("Estimated probability of an alien invasion: %.2f%%\n", probability * 100);
    } else {
        printf("No sightings recorded!\n");
    }

    return 0;
}