//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CITIES 100
#define MAX_EVENTS 100

typedef struct {
    double alienTechnologyDiscoveryChance;
    int resourceExtractionEfficiency;
} City;

typedef struct {
    double eventImpactFactor;
    char eventDescription[100];
} Event;

typedef struct {
    City cities[MAX_CITIES];
    Event events[MAX_EVENTS];
    int cityCount;
    int eventCount;
} SimulationData;

void initializeCities(SimulationData *simData) {
    for (int i = 0; i < simData->cityCount; i++) {
        simData->cities[i].alienTechnologyDiscoveryChance = ((double)rand() / RAND_MAX);
        simData->cities[i].resourceExtractionEfficiency = rand() % 80 + 20; // Between 20-100
    }
}

void initializeEvents(SimulationData *simData) {
    for (int i = 0; i < simData->eventCount; i++) {
        simData->events[i].eventImpactFactor = ((double)rand() / RAND_MAX);
        snprintf(simData->events[i].eventDescription, sizeof(simData->events[i].eventDescription), 
                 "Event %d: Possible environmental shift.", i + 1);
    }
}

double calculateAlienInvasionProbability(SimulationData *simData) {
    double totalProbability = 0.0;

    for (int i = 0; i < simData->cityCount; i++) {
        double cityProbability = simData->cities[i].alienTechnologyDiscoveryChance *
                                 (simData->cities[i].resourceExtractionEfficiency / 100.0);
        totalProbability += cityProbability;
    }
    totalProbability /= simData->cityCount;

    // Adjust based on events
    for (int j = 0; j < simData->eventCount; j++) {
        double eventAdjustment = simData->events[j].eventImpactFactor * (1.0 - totalProbability);
        totalProbability += eventAdjustment;
    }
    
    // Cap the probability to 1.0
    if (totalProbability > 1.0) totalProbability = 1.0;

    return totalProbability;
}

void displayResult(double probability) {
    printf("Probability of Alien Invasion: %.2f%%\n", probability * 100);
}

void setupSimulation(SimulationData *simData) {
    printf("Enter number of cities (max %d): ", MAX_CITIES);
    scanf("%d", &simData->cityCount);
    if (simData->cityCount <= 0 || simData->cityCount > MAX_CITIES) {
        printf("Invalid number of cities. Setting to 1.\n");
        simData->cityCount = 1;
    }

    printf("Enter number of events (max %d): ", MAX_EVENTS);
    scanf("%d", &simData->eventCount);
    if (simData->eventCount <= 0 || simData->eventCount > MAX_EVENTS) {
        printf("Invalid number of events. Setting to 1.\n");
        simData->eventCount = 1;
    }

    initializeCities(simData);
    initializeEvents(simData);
}

int main() {
    srand(time(NULL));

    SimulationData simData;
    simData.cityCount = 0;
    simData.eventCount = 0;

    setupSimulation(&simData);
    
    double invasionProbability = calculateAlienInvasionProbability(&simData);
    displayResult(invasionProbability);

    return 0;
}