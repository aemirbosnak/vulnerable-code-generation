//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX_PLANETS 100
#define MAX_DAYS 30

typedef struct {
    char name[30];
    double distance; // Distance from Earth in light-years
    double size;     // Size relative to Earth
    double probability;
} Planet;

void initializePlanets(Planet *planets, int count);
void calculateProbabilities(Planet *planets, int count);
double averageProbability(Planet *planets, int count);
void displayPlanetInformation(Planet *planets, int count);
void displayProbabilities(Planet *planets, int count);
void saveResultsToFile(Planet *planets, int count);

int main() {
    srand(time(NULL));
    
    int planetCount;
    
    printf("Enter the number of planets to consider (1 - %d): ", MAX_PLANETS);
    scanf("%d", &planetCount);
    
    if (planetCount < 1 || planetCount > MAX_PLANETS) {
        printf("Invalid number of planets. Please run the program again.\n");
        return 1;
    }

    Planet planets[MAX_PLANETS];
    initializePlanets(planets, planetCount);
    
    calculateProbabilities(planets, planetCount);
    
    printf("\n--- Planet Information ---\n");
    displayPlanetInformation(planets, planetCount);
    
    printf("\n--- Alien Invasion Probabilities ---\n");
    displayProbabilities(planets, planetCount);
    
    printf("\nAverage Probability of Alien Invasion: %.2f%%\n", averageProbability(planets, planetCount));
    
    saveResultsToFile(planets, planetCount);
    
    return 0;
}

void initializePlanets(Planet *planets, int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter the name of planet %d: ", i + 1);
        scanf("%s", planets[i].name);
        
        printf("Enter the distance from Earth in light-years for %s: ", planets[i].name);
        scanf("%lf", &planets[i].distance);
        
        printf("Enter the size relative to Earth for %s: ", planets[i].name);
        scanf("%lf", &planets[i].size);
        
        planets[i].probability = 0.0; // Initialize probability to 0
    }
}

void calculateProbabilities(Planet *planets, int count) {
    for (int i = 0; i < count; i++) {
        // Probability is inversely proportional to distance and proportional to size
        planets[i].probability = (1 / planets[i].distance) * planets[i].size * 100;
        
        // Limit maximum probability to 100%
        if (planets[i].probability > 100) {
            planets[i].probability = 100;
        }
    }
}

double averageProbability(Planet *planets, int count) {
    double totalProbability = 0.0;
    
    for (int i = 0; i < count; i++) {
        totalProbability += planets[i].probability;
    }
    
    return totalProbability / count;
}

void displayPlanetInformation(Planet *planets, int count) {
    for (int i = 0; i < count; i++) {
        printf("Planet Name: %s, Distance: %.2f light-years, Size: %.2f Earths\n", 
               planets[i].name, planets[i].distance, planets[i].size);
    }
}

void displayProbabilities(Planet *planets, int count) {
    for (int i = 0; i < count; i++) {
        printf("Probability of Alien Invasion on %s: %.2f%%\n", 
               planets[i].name, planets[i].probability);
    }
}

void saveResultsToFile(Planet *planets, int count) {
    FILE *file = fopen("alien_invasion_probabilities.txt", "w");
    
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "Planet Name: %s, Distance: %.2f light-years, Size: %.2f Earths, Probability: %.2f%%\n", 
                planets[i].name, planets[i].distance, planets[i].size, planets[i].probability);
    }

    fclose(file);
    printf("Results saved to alien_invasion_probabilities.txt\n");
}