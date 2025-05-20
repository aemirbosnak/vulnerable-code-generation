//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_ALIENS 1000000
#define MAX_CIVILIZATIONS 1000
#define MAX_DISTANCE 1000
#define MAX_YEARS 1000
#define MAX_PROBABILITY 1000

struct Alien {
    char name[20];
    int distance;
    int probability;
};

void generateAliens(struct Alien aliens[], int numAliens) {
    srand(time(NULL));
    for (int i = 0; i < numAliens; i++) {
        sprintf(aliens[i].name, "Alien %d", i + 1);
        aliens[i].distance = rand() % MAX_DISTANCE + 1;
        aliens[i].probability = rand() % MAX_PROBABILITY + 1;
    }
}

void printAliens(struct Alien aliens[], int numAliens) {
    for (int i = 0; i < numAliens; i++) {
        printf("Name: %s\nDistance: %d\nProbability: %d\n\n", aliens[i].name, aliens[i].distance, aliens[i].probability);
    }
}

void invasion(int numCivilizations, int numAliens, struct Alien aliens[], int numYears) {
    int totalInvasions = 0;
    for (int i = 0; i < numCivilizations; i++) {
        printf("Civilization %d:\n", i + 1);
        for (int j = 0; j < numAliens; j++) {
            int invasion = rand() % aliens[j].probability + 1;
            if (invasion == 1) {
                totalInvasions++;
                printf("Invasion by %s in year %d\n", aliens[j].name, i + 1);
            }
        }
    }
    printf("Total invasions: %d\n", totalInvasions);
}

int main() {
    int numCivilizations, numAliens, numYears;
    printf("Enter the number of civilizations: ");
    scanf("%d", &numCivilizations);
    printf("Enter the number of aliens: ");
    scanf("%d", &numAliens);
    printf("Enter the number of years: ");
    scanf("%d", &numYears);

    struct Alien aliens[MAX_ALIENS];
    generateAliens(aliens, numAliens);

    invasion(numCivilizations, numAliens, aliens, numYears);

    return 0;
}