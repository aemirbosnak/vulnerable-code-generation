//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEARS 100
#define MAX_PROBABILITY 100.0
#define ALIEN_TYPES 5

typedef struct {
    char name[30];
    float invasionProbability; // Probability of invasion in a year
} AlienSpecies;

void initializeAlienSpecies(AlienSpecies aliens[], int count) {
    const char *names[ALIEN_TYPES] = {
        "Martians", "Venusians", "Zorgons", "Xenobites", "Galacticans"
    };
    
    for(int i = 0; i < count; i++) {
        snprintf(aliens[i].name, sizeof(aliens[i].name), "%s", names[i]);
        aliens[i].invasionProbability = ((float)(rand() % (int)(MAX_PROBABILITY * 100))) / 100.0;
    }
}

void simulateInvasion(AlienSpecies aliens[], int count, int years) {
    printf("\n--- Alien Invasion Simulation ---\n");
    for (int year = 1; year <= years; year++) {
        printf("Year %d:\n", year);
        for (int i = 0; i < count; i++) {
            float randomValue = (float)(rand() % 101) / 100.0; // Random value between 0 and 1
            if (randomValue < aliens[i].invasionProbability) {
                printf("   Invasion by %s!\n", aliens[i].name);
            } else {
                printf("   No invasion by %s.\n", aliens[i].name);
            }
        }
        printf("------------------------------\n");
    }
}

void reportProbabilities(AlienSpecies aliens[], int count) {
    printf("\n--- Alien Invasion Probabilities ---\n");
    for(int i = 0; i < count; i++) {
        printf("%s: %.2f%% chance of invasion annually.\n", 
               aliens[i].name, aliens[i].invasionProbability);
    }
}

int main() {
    srand(time(NULL));

    AlienSpecies aliens[ALIEN_TYPES];
    initializeAlienSpecies(aliens, ALIEN_TYPES);

    int years;
    printf("Enter number of years to simulate for alien invasions: ");
    scanf("%d", &years);
    
    if (years <= 0 || years > MAX_YEARS) {
        printf("Please enter a valid number of years (1 - %d).\n", MAX_YEARS);
        return EXIT_FAILURE;
    }

    reportProbabilities(aliens, ALIEN_TYPES);
    simulateInvasion(aliens, ALIEN_TYPES, years);

    printf("Simulation complete.\n");
    return EXIT_SUCCESS;
}