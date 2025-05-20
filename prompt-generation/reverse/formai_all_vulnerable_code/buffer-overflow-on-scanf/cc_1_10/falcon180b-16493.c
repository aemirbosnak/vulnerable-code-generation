//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CIVILIZATIONS 1000
#define MAX_YEARS 100
#define PROBABILITY_THRESHOLD 0.5

struct Civilization {
    int id;
    int technology_level;
    float probability_of_invasion;
};

void generateCivilizations(struct Civilization civilizations[], int numCivilizations) {
    srand(time(NULL));
    for (int i = 0; i < numCivilizations; i++) {
        civilizations[i].id = i + 1;
        civilizations[i].technology_level = rand() % 10 + 1;
        civilizations[i].probability_of_invasion = (float) civilizations[i].technology_level / 10;
    }
}

int main() {
    int numCivilizations;
    printf("Enter the number of civilizations to simulate (up to %d): ", MAX_CIVILIZATIONS);
    scanf("%d", &numCivilizations);

    if (numCivilizations <= 0 || numCivilizations > MAX_CIVILIZATIONS) {
        printf("Invalid number of civilizations.\n");
        return 1;
    }

    struct Civilization civilizations[numCivilizations];
    generateCivilizations(civilizations, numCivilizations);

    int numYears;
    printf("Enter the number of years to simulate (up to %d): ", MAX_YEARS);
    scanf("%d", &numYears);

    if (numYears <= 0 || numYears > MAX_YEARS) {
        printf("Invalid number of years.\n");
        return 1;
    }

    int numInvasions = 0;
    for (int year = 1; year <= numYears; year++) {
        printf("Year %d:\n", year);
        for (int i = 0; i < numCivilizations; i++) {
            if (civilizations[i].probability_of_invasion >= PROBABILITY_THRESHOLD) {
                numInvasions++;
                printf("Civilization %d invades!\n", civilizations[i].id);
            }
        }
    }

    printf("Total number of invasions over %d years: %d\n", numYears, numInvasions);

    return 0;
}