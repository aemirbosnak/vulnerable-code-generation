//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DIMENSIONS 10
#define NUM_UNIVERSES 1000
#define NUM_SPECIES 1000
#define NUM_PLANETS 10
#define NUM_YEARS 100

struct species {
    char name[50];
    float intelligence;
    float aggression;
    float technology;
    float population;
};

struct planet {
    char name[50];
    float habitability;
    struct species *inhabitants;
};

struct universe {
    struct planet planets[NUM_PLANETS];
};

void generate_species(struct species *species) {
    srand(time(NULL));
    species->intelligence = rand() % 101;
    species->aggression = rand() % 101;
    species->technology = rand() % 101;
    species->population = rand() % 101;
}

void generate_planets(struct planet *planets) {
    srand(time(NULL));
    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i].habitability = rand() % 101;
        planets[i].inhabitants = NULL;
    }
}

void generate_universe(struct universe *universe) {
    srand(time(NULL));
    for (int i = 0; i < NUM_PLANETS; i++) {
        universe->planets[i].inhabitants = (struct species *) malloc(sizeof(struct species));
        generate_species(universe->planets[i].inhabitants);
    }
}

int main() {
    struct universe universes[NUM_UNIVERSES];
    for (int i = 0; i < NUM_UNIVERSES; i++) {
        generate_universe(&universes[i]);
    }

    int invasions = 0;
    for (int i = 0; i < NUM_UNIVERSES; i++) {
        for (int j = 0; j < NUM_PLANETS; j++) {
            if (universes[i].planets[j].inhabitants->intelligence >= 90 &&
                universes[i].planets[j].inhabitants->technology >= 90) {
                invasions++;
            }
        }
    }

    float invasion_probability = ((float) invasions / (NUM_UNIVERSES * NUM_PLANETS)) * 100;

    printf("The probability of an alien invasion is %.2f%%\n", invasion_probability);

    return 0;
}