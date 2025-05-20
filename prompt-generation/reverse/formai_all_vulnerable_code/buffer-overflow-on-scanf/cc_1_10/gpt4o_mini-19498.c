//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPECIES 10

typedef struct {
    char name[30];
    float attackProbability;
    float stealthLevel;
} AlienSpecies;

void initializeAliens(AlienSpecies aliens[], int count) {
    const char *speciesNames[MAX_SPECIES] = {
        "Zorgonians", "Glibnorp", "Thargons", 
        "Vexxonians", "Quintarians", "Blorbs", 
        "Nimblocks", "Slarvans", "Xentarians", 
        "Trogdor"
    };

    srand(time(NULL)); // Seed for randomness

    for (int i = 0; i < count; i++) {
        snprintf(aliens[i].name, sizeof(aliens[i].name), "%s", speciesNames[i]);
        aliens[i].attackProbability = rand() % 100 / 100.0; // 0.0 to 1.0
        aliens[i].stealthLevel = rand() % 100 / 100.0; // 0.0 to 1.0
    }
}

void calculateInvasionProbability(AlienSpecies aliens[], int count) {
    float totalProbability = 0.0;

    printf("\nAlien Invasion Probability Report:\n");
    printf("===================================\n");
    for (int i = 0; i < count; i++) {
        float invasionChance = (aliens[i].attackProbability + aliens[i].stealthLevel) / 2;
        totalProbability += invasionChance;
        printf("Species: %s | Attack Probability: %.2f | Stealth Level: %.2f | Invasion Probability: %.2f\n", 
                aliens[i].name, 
                aliens[i].attackProbability, 
                aliens[i].stealthLevel, 
                invasionChance);
    }

    float averageProbability = totalProbability / count;
    printf("===================================\n");
    printf("Average Invasion Probability: %.2f\n", averageProbability);
}

void takeUserInput(int *speciesCount) {
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the number of alien species to analyze (max %d): ", MAX_SPECIES);
    scanf("%d", speciesCount);
    
    while (*speciesCount < 1 || *speciesCount > MAX_SPECIES) {
        printf("Invalid input! Please enter a number between 1 and %d: ", MAX_SPECIES);
        scanf("%d", speciesCount);
    }
}

int main() {
    int speciesCount;
    AlienSpecies aliens[MAX_SPECIES];

    takeUserInput(&speciesCount);
    initializeAliens(aliens, speciesCount);
    calculateInvasionProbability(aliens, speciesCount);

    printf("Thank you for using the Alien Invasion Probability Calculator!\n");
    printf("Stay vigilant and keep your eyes on the sky! 🚀👽\n");

    return 0;
}