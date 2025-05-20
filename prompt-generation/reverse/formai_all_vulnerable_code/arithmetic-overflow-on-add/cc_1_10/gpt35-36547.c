//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void printIntro();
void generatePlanets(int, int*);
void displayPlanets(int, int*);
void calculateStatistics(int, int*, int*);

int main() {
    int numPlanets, *planetSizes, *planetDistances;
    
    // Print introduction
    printIntro();
    
    // Generate planets with random sizes (between 1 and 1000) and distances (between 1 and 10000)
    srand(time(0)); // Seed random number generator
    printf("Enter the number of planets to explore: ");
    scanf("%d", &numPlanets);
    planetSizes = (int*) malloc(numPlanets * sizeof(int));
    planetDistances = (int*) malloc(numPlanets * sizeof(int));
    generatePlanets(numPlanets, planetSizes);
    generatePlanets(numPlanets, planetDistances);
    
    // Display the generated planets
    printf("\nGenerated planets:\n");
    displayPlanets(numPlanets, planetSizes);
    displayPlanets(numPlanets, planetDistances);
    
    // Calculate and display statistics about the planets
    calculateStatistics(numPlanets, planetSizes, planetDistances);
    
    // Free allocated memory
    free(planetSizes);
    free(planetDistances);
    
    return 0;
}

void printIntro() {
    printf("Welcome to the Procedural Space Adventure Program!\n\n");
}

void generatePlanets(int numPlanets, int *planetArray) {
    for (int i=0; i<numPlanets; i++) {
        planetArray[i] = rand() % 1000 + 1;
    }
}

void displayPlanets(int numPlanets, int *planetArray) {
    for (int i=0; i<numPlanets; i++) {
        printf("%d ", planetArray[i]);
    }
    printf("\n");
}

void calculateStatistics(int numPlanets, int *sizes, int *distances) {
    // Calculate total size and average size of all planets
    int totalSize = 0;
    float avgSize;
    for (int i=0; i<numPlanets; i++) {
        totalSize += sizes[i];
    }
    avgSize = (float) totalSize / (float) numPlanets;
    
    // Calculate furthest planet and distance from origin
    int furthestPlanet;
    int distanceFromOrigin = 0;
    for (int i=0; i<numPlanets; i++) {
        if (distances[i] > distanceFromOrigin) {
            distanceFromOrigin = distances[i];
            furthestPlanet = i;
        }
    }
    
    // Print statistics
    printf("\nStatistics:\n");
    printf("Total size of all planets: %d\n", totalSize);
    printf("Average size of all planets: %.2f\n", avgSize);
    printf("Distance from origin of furthest planet (%d): %d\n", furthestPlanet+1, distances[furthestPlanet]);
}