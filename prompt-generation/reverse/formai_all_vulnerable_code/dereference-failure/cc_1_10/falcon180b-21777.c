//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CIVILIZATIONS 1000000
#define NUM_YEARS 100000
#define TECH_LEVEL_THRESHOLD 10

typedef struct {
    int tech_level;
    int num_civilizations;
} Civilization;

Civilization* civilizations;

void initialize_civilizations() {
    civilizations = (Civilization*) malloc(NUM_CIVILIZATIONS * sizeof(Civilization));
    for (int i = 0; i < NUM_CIVILIZATIONS; i++) {
        civilizations[i].tech_level = rand() % 100;
        civilizations[i].num_civilizations = 1;
    }
}

int count_civilizations(int tech_level) {
    int count = 0;
    for (int i = 0; i < NUM_CIVILIZATIONS; i++) {
        if (civilizations[i].tech_level >= tech_level) {
            count++;
        }
    }
    return count;
}

int main() {
    srand(time(NULL));
    initialize_civilizations();

    for (int year = 0; year < NUM_YEARS; year++) {
        int num_civilizations = 0;
        for (int i = 0; i < NUM_CIVILIZATIONS; i++) {
            if (civilizations[i].tech_level >= TECH_LEVEL_THRESHOLD) {
                num_civilizations++;
            }
        }
        if (num_civilizations > 0) {
            printf("%d: %d civilizations have advanced technology\n", year, num_civilizations);
        } else {
            printf("%d: No civilizations have advanced technology\n", year);
        }
    }

    return 0;
}