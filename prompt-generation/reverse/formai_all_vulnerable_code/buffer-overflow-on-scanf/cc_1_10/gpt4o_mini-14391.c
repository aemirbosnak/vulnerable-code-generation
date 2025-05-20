//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 10
#define MAX_PROBABILITY 100

struct Planet {
    char name[30];
    float invasionProbability; // from 0.0 to 100.0
};

// Function prototypes
void generatePlanets(struct Planet planets[], int count);
void calculateTotalProbability(struct Planet planets[], int count);
void displayPlanetData(struct Planet planets[], int count);

int main() {
    struct Planet planets[MAX_PLANETS];
    int planetCount;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("How many planets do you want to assess (max %d)? ", MAX_PLANETS);
    scanf("%d", &planetCount);

    if (planetCount < 1 || planetCount > MAX_PLANETS) {
        printf("Invalid number of planets! Please choose a number between 1 and %d.\n", MAX_PLANETS);
        return 1;
    }

    srand(time(NULL)); // Seed the random number generator
    generatePlanets(planets, planetCount);
    displayPlanetData(planets, planetCount);
    
    calculateTotalProbability(planets, planetCount);

    return 0;
}

void generatePlanets(struct Planet planets[], int count) {
    const char* planetNames[MAX_PLANETS] = {
        "Earth", "Mars", "Venus", "Jupiter", "Saturn", 
        "Uranus", "Neptune", "Pluto", "Mercury", "Exoplanet-X"
    };

    for (int i = 0; i < count; i++) {
        snprintf(planets[i].name, sizeof(planets[i].name), "%s", planetNames[i]);
        planets[i].invasionProbability = (float)(rand() % (MAX_PROBABILITY + 1)); // Random probability between 0 and 100
    }
}

void calculateTotalProbability(struct Planet planets[], int count) {
    float totalProbability = 0.0;

    for (int i = 0; i < count; i++) {
        totalProbability += planets[i].invasionProbability;
    }
    
    printf("\nThe total invasion probability across all assessed planets is: %.2f%%\n", totalProbability);
    
    float averageProbability = totalProbability / count;
    printf("The average invasion probability is: %.2f%%\n", averageProbability);

    if (averageProbability > 50) {
        printf("Warning: The average invasion probability is alarmingly high!\n");
    } else {
        printf("Status: Relax, the invasion probability is acceptable.\n");
    }
}

void displayPlanetData(struct Planet planets[], int count) {
    printf("\nPlanet Invasion Probability Report:\n");
    printf("===================================\n");
    printf("| %-20s | Probability |\n", "Planet Name");
    printf("===================================\n");
    
    for (int i = 0; i < count; i++) {
        printf("| %-20s | %.2f%%       |\n", planets[i].name, planets[i].invasionProbability);
    }
    
    printf("===================================\n");
}