//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TRIES 1000
#define NUM_FACTORS 10
#define MIN_POPULATION 1000
#define MAX_POPULATION 1000000
#define MIN_TECH_LEVEL 1
#define MAX_TECH_LEVEL 10
#define MIN_DISTANCE 1
#define MAX_DISTANCE 100
#define MIN_YEARS 1
#define MAX_YEARS 100

struct planet {
    int population;
    int tech_level;
    double distance;
};

int main() {
    srand(time(NULL));

    int num_planets = rand() % (MAX_POPULATION - MIN_POPULATION + 1) + MIN_POPULATION;
    struct planet *planets = malloc(sizeof(struct planet) * num_planets);

    for (int i = 0; i < num_planets; i++) {
        planets[i].population = rand() % (MAX_POPULATION - MIN_POPULATION + 1) + MIN_POPULATION;
        planets[i].tech_level = rand() % (MAX_TECH_LEVEL - MIN_TECH_LEVEL + 1) + MIN_TECH_LEVEL;
        planets[i].distance = rand() % (MAX_DISTANCE - MIN_DISTANCE + 1) + MIN_DISTANCE;
    }

    int num_tries = 0;
    int num_invasions = 0;

    while (num_tries < MAX_TRIES) {
        num_tries++;

        for (int i = 0; i < num_planets; i++) {
            for (int j = i + 1; j < num_planets; j++) {
                double distance = planets[i].distance + planets[j].distance;

                if (distance <= (double)num_planets * planets[i].tech_level) {
                    num_invasions++;
                }
            }
        }

        if (num_invasions == 0) {
            printf("No alien invasions detected after %d years.\n", num_tries);
            break;
        } else {
            num_invasions = 0;
        }
    }

    free(planets);

    return 0;
}