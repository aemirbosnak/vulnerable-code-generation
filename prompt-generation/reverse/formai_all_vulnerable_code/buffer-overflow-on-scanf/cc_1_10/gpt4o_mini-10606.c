//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100

typedef struct {
    char name[50];
    int population;
    float alien_activity; // Probability of alien invasion in percentage
} City;

void initializeCities(City cities[], int count);
void calculateInvasionProbability(City cities[], int count);
void displayResults(City cities[], int count);
void simulateAlienInvasion(float invasion_chance);

int main() {
    int totalCities;
    City cities[MAX_CITIES];

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the number of cities (max %d): ", MAX_CITIES);
    scanf("%d", &totalCities);

    while (totalCities <= 0 || totalCities > MAX_CITIES) {
        printf("Invalid number of cities. Please enter a number between 1 and %d: ", MAX_CITIES);
        scanf("%d", &totalCities);
    }

    initializeCities(cities, totalCities);
    calculateInvasionProbability(cities, totalCities);
    displayResults(cities, totalCities);

    return 0;
}

void initializeCities(City cities[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter the name of city %d: ", i + 1);
        scanf("%s", cities[i].name);
        printf("Enter the population of %s: ", cities[i].name);
        scanf("%d", &cities[i].population);
        cities[i].alien_activity = 0.0; // Initialize to 0 for this function
    }
}

void calculateInvasionProbability(City cities[], int count) {
    srand(time(NULL));

    for (int i = 0; i < count; i++) {
        // Using the population to define the base for alien activity probability
        cities[i].alien_activity = ((float)(rand() % 100) + (cities[i].population / 10000.0)) / 2.0;
        if (cities[i].alien_activity > 100.0) {
            cities[i].alien_activity = 100.0; // Maximum cap on probability
        }
    }
}

void displayResults(City cities[], int count) {
    printf("\n--- Alien Invasion Probability Report ---\n");
    for (int i = 0; i < count; i++) {
        printf("City: %s\n", cities[i].name);
        printf("Population: %d\n", cities[i].population);
        printf("Invasion Probability: %.2f%%\n", cities[i].alien_activity);
        simulateAlienInvasion(cities[i].alien_activity);
        printf("-----------------------------------------\n");
    }
}

void simulateAlienInvasion(float invasion_chance) {
    float random_num = ((float)rand() / RAND_MAX) * 100;
    if (random_num < invasion_chance) {
        printf("ALERT! An alien invasion has been detected in this city!\n");
    } else {
        printf("No invasion detected this time. All is calm.\n");
    }
}