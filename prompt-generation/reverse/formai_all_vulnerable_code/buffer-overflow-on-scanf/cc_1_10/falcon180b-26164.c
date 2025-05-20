//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 100
#define MAX_UNIVERSE_SIZE 1000
#define MAX_PLANETS 1000
#define MIN_PLANET_SIZE 1
#define MAX_PLANET_SIZE 10

typedef struct {
    int size;
    int has_life;
} Planet;

void generate_universe(Planet universe[], int size) {
    for (int i = 0; i < size; i++) {
        universe[i].size = rand() % (MAX_PLANET_SIZE - MIN_PLANET_SIZE + 1) + MIN_PLANET_SIZE;
        universe[i].has_life = rand() % 2;
    }
}

int count_life_planets(Planet universe[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (universe[i].has_life) {
            count++;
        }
    }
    return count;
}

int main() {
    srand(time(NULL));

    int universe_size;
    printf("Enter the size of the universe (1 to %d): ", MAX_UNIVERSE_SIZE);
    scanf("%d", &universe_size);

    while (universe_size < 1 || universe_size > MAX_UNIVERSE_SIZE) {
        printf("Invalid universe size. Please enter a number between 1 and %d: ", MAX_UNIVERSE_SIZE);
        scanf("%d", &universe_size);
    }

    Planet universe[universe_size];
    generate_universe(universe, universe_size);

    int attempts = 0;
    while (attempts < MAX_ATTEMPTS && count_life_planets(universe, universe_size) == 0) {
        attempts++;
        generate_universe(universe, universe_size);
    }

    if (count_life_planets(universe, universe_size) > 0) {
        printf("Alien invasion probability: %d%%\n", (attempts * 100) / MAX_ATTEMPTS);
    } else {
        printf("No life found in the universe.\n");
    }

    return 0;
}