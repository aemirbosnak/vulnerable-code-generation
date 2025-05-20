//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CIVILIZATIONS 100
#define MAX_YEARS 1000
#define PROBABILITY_THRESHOLD 0.5

struct Civilization {
    char name[50];
    int technology_level;
    int aggression_level;
    int chance_of_invasion;
};

int main() {
    srand(time(NULL));

    struct Civilization civilizations[MAX_CIVILIZATIONS];
    int num_civilizations = 0;

    while (num_civilizations < MAX_CIVILIZATIONS) {
        printf("Enter the name of a civilization (or leave blank to stop): ");
        scanf("%s", civilizations[num_civilizations].name);

        if (strcmp(civilizations[num_civilizations].name, "") == 0) {
            break;
        }

        printf("Enter the technology level of civilization %s (1-10): ", civilizations[num_civilizations].name);
        scanf("%d", &civilizations[num_civilizations].technology_level);

        printf("Enter the aggression level of civilization %s (1-10): ", civilizations[num_civilizations].name);
        scanf("%d", &civilizations[num_civilizations].aggression_level);

        civilizations[num_civilizations].chance_of_invasion = (civilizations[num_civilizations].technology_level + civilizations[num_civilizations].aggression_level) / 20.0;
        num_civilizations++;
    }

    int num_years = 0;
    int num_invasions = 0;

    while (num_years < MAX_YEARS && num_invasions < num_civilizations) {
        for (int i = 0; i < num_civilizations; i++) {
            if (rand() % 100 < civilizations[i].chance_of_invasion) {
                num_invasions++;
            }
        }

        num_years++;
    }

    printf("The probability of an alien invasion within the next %d years is %.2f%%\n", MAX_YEARS, (float)num_invasions / MAX_YEARS * 100.0);

    return 0;
}