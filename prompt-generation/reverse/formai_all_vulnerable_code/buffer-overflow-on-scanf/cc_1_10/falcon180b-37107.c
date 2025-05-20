//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ALIEN_COUNT 1000
#define MAX_YEAR 10000
#define PROBABILITY_PER_YEAR 0.01
#define MIN_POPULATION 10000
#define MAX_POPULATION 1000000

struct Alien {
    int year;
    int population;
};

void generateAliens(struct Alien aliens[], int count) {
    for (int i = 0; i < count; i++) {
        aliens[i].year = rand() % MAX_YEAR;
        aliens[i].population = rand() % (MAX_POPULATION - MIN_POPULATION + 1) + MIN_POPULATION;
    }
}

int main() {
    srand(time(NULL));

    int year;
    printf("Enter the current year: ");
    scanf("%d", &year);

    struct Alien aliens[MAX_ALIEN_COUNT];
    int alienCount = 0;

    while (alienCount < MAX_ALIEN_COUNT) {
        if (year >= aliens[alienCount].year) {
            alienCount++;
        } else {
            generateAliens(aliens, MAX_ALIEN_COUNT);
        }
    }

    int invasionYear = -1;
    double totalPopulation = 0;

    for (int i = 0; i < alienCount; i++) {
        totalPopulation += aliens[i].population;

        if (aliens[i].year == year) {
            double probability = PROBABILITY_PER_YEAR * aliens[i].population;

            if (rand() % 100 < probability) {
                invasionYear = year;
                break;
            }
        }
    }

    if (invasionYear == -1) {
        printf("No alien invasion detected.\n");
    } else {
        printf("Alien invasion detected in the year %d.\n", invasionYear);
    }

    return 0;
}