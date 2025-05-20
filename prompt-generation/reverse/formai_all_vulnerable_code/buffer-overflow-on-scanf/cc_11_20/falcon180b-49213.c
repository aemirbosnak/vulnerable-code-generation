//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CIVILIZATIONS 1000
#define MAX_YEARS 1000

struct Civilization {
    int discovered;
    int technology_level;
    int aggression_level;
};

int main() {
    srand(time(NULL));

    int num_civilizations;
    printf("Enter the number of civilizations: ");
    scanf("%d", &num_civilizations);

    struct Civilization civilizations[MAX_CIVILIZATIONS];

    for (int i = 0; i < num_civilizations; i++) {
        civilizations[i].discovered = 0;
        civilizations[i].technology_level = rand() % 10 + 1;
        civilizations[i].aggression_level = rand() % 10 + 1;
    }

    int num_years;
    printf("Enter the number of years to simulate: ");
    scanf("%d", &num_years);

    int num_discoveries = 0;
    int num_invasions = 0;

    for (int year = 0; year < num_years; year++) {
        // Simulate a year of interactions between civilizations
        for (int i = 0; i < num_civilizations; i++) {
            if (civilizations[i].discovered == 0) {
                // This civilization has not been discovered yet
                int num_neighbors = 0;
                for (int j = 0; j < num_civilizations; j++) {
                    if (civilizations[j].discovered == 1 && rand() % 2 == 0) {
                        // This civilization discovers the undiscovered civilization
                        civilizations[i].discovered = 1;
                        civilizations[j].discovered = 1;
                        num_discoveries++;
                    }
                }
            } else {
                // This civilization has been discovered
                for (int j = 0; j < num_civilizations; j++) {
                    if (civilizations[j].discovered == 1 && civilizations[j].technology_level >= civilizations[i].technology_level && civilizations[j].aggression_level >= civilizations[i].aggression_level) {
                        // This civilization invades the weaker civilization
                        civilizations[i].discovered = 0;
                        num_invasions++;
                    }
                }
            }
        }
    }

    printf("Number of discoveries: %d\n", num_discoveries);
    printf("Number of invasions: %d\n", num_invasions);

    return 0;
}