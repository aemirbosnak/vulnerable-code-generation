//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CIVILIZATIONS 1000
#define MAX_PLANETS 100
#define MAX_YEARS 10000

struct Civilization {
    char name[50];
    int technology_level;
    int aggression_level;
    int number_of_planets;
};

struct Planet {
    char name[50];
    int resources;
    int defense_level;
};

int main() {
    srand(time(NULL));

    int num_civilizations = rand() % MAX_CIVILIZATIONS + 1;
    int num_planets = rand() % MAX_PLANETS + 1;

    struct Civilization civilizations[MAX_CIVILIZATIONS];
    struct Planet planets[MAX_PLANETS];

    for (int i = 0; i < num_civilizations; i++) {
        civilizations[i].technology_level = rand() % 10 + 1;
        civilizations[i].aggression_level = rand() % 10 + 1;
        civilizations[i].number_of_planets = rand() % 10 + 1;

        for (int j = 0; j < civilizations[i].number_of_planets; j++) {
            planets[i * num_planets + j].resources = rand() % 10 + 1;
            planets[i * num_planets + j].defense_level = rand() % 10 + 1;
        }
    }

    int num_years = rand() % MAX_YEARS + 1;

    for (int year = 0; year < num_years; year++) {
        for (int i = 0; i < num_civilizations; i++) {
            for (int j = 0; j < civilizations[i].number_of_planets; j++) {
                planets[i * num_planets + j].resources += civilizations[i].technology_level * planets[i * num_planets + j].defense_level;
            }
        }
    }

    for (int i = 0; i < num_civilizations; i++) {
        printf("Civilization %s has a %d%% chance of invading Earth in the next %d years.\n", civilizations[i].name, (civilizations[i].aggression_level * civilizations[i].technology_level) / 10, num_years);
    }

    return 0;
}