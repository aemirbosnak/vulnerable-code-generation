//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_CITIES 10
#define BASE_PROBABILITY 0.1

typedef struct {
    char cityName[50];
    float alienReports;
    int humanPopulation;
} City;

typedef struct {
    City cities[MAX_CITIES];
    int totalCities;
} AlienInvasionData;

void initializeCities(AlienInvasionData *data) {
    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

    data->totalCities = MAX_CITIES;
    for (int i = 0; i < data->totalCities; i++) {
        printf("Enter the name of city %d: ", i + 1);
        scanf("%s", data->cities[i].cityName);
        printf("Enter the human population in %s: ", data->cities[i].cityName);
        scanf("%d", &data->cities[i].humanPopulation);
        data->cities[i].alienReports = 0.0; // Initialize alien reports
    }

    printf("\nAll cities have been initialized!\n");
}

float calculateProbability(float baseProb, float alienReports, int humanPopulation) {
    float adjustedProb = baseProb + (alienReports / (float)humanPopulation);
    return (adjustedProb > 1.0) ? 1.0 : adjustedProb; // Cap at 1.0
}

void simulateAlienReports(AlienInvasionData *data) {
    srand(time(NULL));  // Seed for random number generation
    for (int i = 0; i < data->totalCities; i++) {
        data->cities[i].alienReports = (float)(rand() % 100) / 100;
    }
}

void displayProbabilities(AlienInvasionData *data) {
    printf("\nInvasion Probability Report:\n");
    printf("---------------------------------------------------\n");
    printf("| City Name           | Alien Reports | Probability  |\n");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < data->totalCities; i++) {
        float probability = calculateProbability(BASE_PROBABILITY, data->cities[i].alienReports, data->cities[i].humanPopulation);
        printf("| %-20s | %-14.2f | %-12.2f |\n", data->cities[i].cityName, 
               data->cities[i].alienReports, probability);
    }
    printf("---------------------------------------------------\n");
}

void runInvasionSimulation(AlienInvasionData *data) {
    printf("\nSimulating alien reports...\n");
    simulateAlienReports(data);
    displayProbabilities(data);
}

void analyzeResults(AlienInvasionData *data) {
    int highRiskCount = 0;
    for (int i = 0; i < data->totalCities; i++) {
        float probability = calculateProbability(BASE_PROBABILITY, data->cities[i].alienReports, data->cities[i].humanPopulation);
        if (probability > 0.5) {
            printf("WARNING: High Invasion Risk detected in %s with a probability of %.2f!\n",
                   data->cities[i].cityName, probability);
            highRiskCount++;
        }
    }
    if (highRiskCount == 0) {
        printf("No cities are currently under high invasion risk.\n");
    }
}

int main() {
    AlienInvasionData data;
    initializeCities(&data);
    runInvasionSimulation(&data);
    analyzeResults(&data);

    return 0;
}