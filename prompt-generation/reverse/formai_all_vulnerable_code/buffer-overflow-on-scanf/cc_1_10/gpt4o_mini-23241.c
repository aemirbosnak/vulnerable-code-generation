//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_SIGHTINGS 1000

typedef struct {
    char name[50];
    int sightings;
    double probability;
} City;

void initializeCities(City cities[], int numCities) {
    for (int i = 0; i < numCities; i++) {
        sprintf(cities[i].name, "City_%d", i + 1);
        cities[i].sightings = rand() % MAX_SIGHTINGS;
        cities[i].probability = 0.0;
    }
}

void calculateProbabilities(City cities[], int numCities) {
    int totalSightings = 0;
    
    for (int i = 0; i < numCities; i++) {
        totalSightings += cities[i].sightings;
    }

    for (int i = 0; i < numCities; i++) {
        if (totalSightings > 0) {
            cities[i].probability = (double)cities[i].sightings / totalSightings * 100;
        }
    }
}

void displayResults(City cities[], int numCities) {
    printf("City Name\tSightings\tProbability (%%)\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < numCities; i++) {
        printf("%s\t\t%d\t\t%.2f\n", cities[i].name, cities[i].sightings, cities[i].probability);
    }
}

void sortCitiesByProbability(City cities[], int numCities) {
    for (int i = 0; i < numCities - 1; i++) {
        for (int j = 0; j < numCities - i - 1; j++) {
            if (cities[j].probability < cities[j + 1].probability) {
                City temp = cities[j];
                cities[j] = cities[j + 1];
                cities[j + 1] = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int numCities;
    printf("Enter the number of cities (max %d): ", MAX_CITIES);
    scanf("%d", &numCities);

    if (numCities <= 0 || numCities > MAX_CITIES) {
        printf("Invalid number of cities. Please enter a number between 1 and %d.\n", MAX_CITIES);
        return 1;
    }

    City cities[MAX_CITIES];
    initializeCities(cities, numCities);
    calculateProbabilities(cities, numCities);
    sortCitiesByProbability(cities, numCities);
    displayResults(cities, numCities);

    return 0;
}