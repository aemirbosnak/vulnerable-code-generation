//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ZONES 10
#define MAX_POPULATION 10000

typedef struct {
    int zoneID;
    int population;
    float alienArrivalRate; // probability of alien arrival in a zone
} Zone;

void initializeZones(Zone zones[]) {
    srand(time(0)); // Seed the random number generator
    for (int i = 0; i < NUM_ZONES; i++) {
        zones[i].zoneID = i + 1;
        zones[i].population = rand() % MAX_POPULATION + 1; // Random population between 1 and MAX_POPULATION
        zones[i].alienArrivalRate = ((float)rand() / RAND_MAX); // Random float between 0 and 1
    }
}

void simulateAlienInvasion(Zone zones[], float invasionThreshold) {
    for (int i = 0; i < NUM_ZONES; i++) {
        float invasionProbability = zones[i].alienArrivalRate * (zones[i].population / (float)MAX_POPULATION);
        if (invasionProbability >= invasionThreshold) {
            printf("Zone %d has an alien invasion likelihood of %.2f, INVADED!\n", 
                   zones[i].zoneID, invasionProbability);
        } else {
            printf("Zone %d has an alien invasion likelihood of %.2f, SAFE.\n", 
                   zones[i].zoneID, invasionProbability);
        }
    }
}

void displayZoneInfo(Zone zones[]) {
    printf("\nZone Information:\n");
    printf("ZoneID\tPopulation\tAlien Arrival Rate\n");
    for (int i = 0; i < NUM_ZONES; i++) {
        printf("%d\t%d\t\t%.2f\n", 
               zones[i].zoneID, zones[i].population, zones[i].alienArrivalRate);
    }
}

int main() {
    Zone zones[NUM_ZONES];
    float invasionThreshold;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Enter the invasion probability threshold (0.0 to 1.0): ");
    scanf("%f", &invasionThreshold);
    
    while (invasionThreshold < 0.0 || invasionThreshold > 1.0) {
        printf("Invalid input. Please enter a value between 0.0 and 1.0: ");
        scanf("%f", &invasionThreshold);
    }

    initializeZones(zones);
    displayZoneInfo(zones);
    
    printf("\nSimulating alien invasions...\n");
    simulateAlienInvasion(zones, invasionThreshold);
    
    printf("\nSimulation complete.\n");
    return 0;
}