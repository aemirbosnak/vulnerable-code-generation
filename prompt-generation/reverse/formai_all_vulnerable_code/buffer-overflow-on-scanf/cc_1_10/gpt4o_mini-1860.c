//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GALAXIES 1000
#define MAX_YEARS 100
#define CONFIDENCE_THRESHOLD 0.65

typedef struct {
    char name[30];
    double probability; // Probability of invasion
} Galaxy;

void initializeGalaxies(Galaxy galaxies[], int count);
void displayGalaxies(Galaxy galaxies[], int count);
double calculateAverageProbability(Galaxy galaxies[], int count);
void predictInvasion(Galaxy galaxies[], int count);
void simulateYears(Galaxy galaxies[], int count, int years);
void printExitMessage();

int main() {
    int galaxyCount = 0;
    int years = 0;
    Galaxy galaxies[MAX_GALAXIES];

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Enter the number of galaxies (max %d): ", MAX_GALAXIES);
    scanf("%d", &galaxyCount);

    if (galaxyCount > MAX_GALAXIES) {
        printf("Exceeded maximum number of galaxies!\n");
        return 1;
    }

    initializeGalaxies(galaxies, galaxyCount);
    displayGalaxies(galaxies, galaxyCount);

    printf("Enter the number of years to simulate: ");
    scanf("%d", &years);
    if (years > MAX_YEARS) {
        printf("Exceeded maximum simulation years!\n");
        return 1;
    }

    simulateYears(galaxies, galaxyCount, years);
    predictInvasion(galaxies, galaxyCount);
    
    printExitMessage();
    return 0;
}

void initializeGalaxies(Galaxy galaxies[], int count) {
    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        sprintf(galaxies[i].name, "Galaxy %d", i + 1);
        galaxies[i].probability = (rand() % 100) / 100.0; // Random probability between 0 and 1
    }
}

void displayGalaxies(Galaxy galaxies[], int count) {
    printf("\n--- Galaxy Invasion Probabilities ---\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %.2f\n", galaxies[i].name, galaxies[i].probability);
    }
    printf("-------------------------------------\n");
}

double calculateAverageProbability(Galaxy galaxies[], int count) {
    double totalProbability = 0.0;
    for (int i = 0; i < count; i++) {
        totalProbability += galaxies[i].probability;
    }
    return totalProbability / count;
}

void predictInvasion(Galaxy galaxies[], int count) {
    double averageProbability = calculateAverageProbability(galaxies, count);
    printf("\nAverage Invasion Probability: %.2f\n", averageProbability);

    if (averageProbability > CONFIDENCE_THRESHOLD) {
        printf("Warning: High probability of alien invasion! Prepare defenses!\n");
    } else {
        printf("No immediate threat of invasion. Stay vigilant.\n");
    }
}

void simulateYears(Galaxy galaxies[], int count, int years) {
    for (int i = 0; i < years; i++) {
        for (int j = 0; j < count; j++) {
            galaxies[j].probability += ((rand() % 10) - 5) / 100.0; // Change probability slightly
            if (galaxies[j].probability < 0) galaxies[j].probability = 0; // ensure non-negative
            if (galaxies[j].probability > 1) galaxies[j].probability = 1; // ensure max probability
        }
        printf("\n--- After Year %d ---\n", i + 1);
        displayGalaxies(galaxies, count);
    }
}

void printExitMessage() {
    printf("Thank you for using the Alien Invasion Probability Calculator. Stay safe!\n");
}