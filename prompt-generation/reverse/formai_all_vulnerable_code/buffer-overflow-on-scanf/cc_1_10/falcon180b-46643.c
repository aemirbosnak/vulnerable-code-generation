//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PLANET_COUNT 10
#define PLANET_NAME_LENGTH 20

typedef struct {
    char name[PLANET_NAME_LENGTH];
    int population;
    int resources;
} Planet;

void generate_planets(Planet planets[]) {
    for (int i = 0; i < PLANET_COUNT; i++) {
        sprintf(planets[i].name, "Planet %d", i + 1);
        planets[i].population = rand() % 1000;
        planets[i].resources = rand() % 1000;
    }
}

void print_planet(const Planet *planet) {
    printf("Name: %s\n", planet->name);
    printf("Population: %d\n", planet->population);
    printf("Resources: %d\n\n", planet->resources);
}

int main() {
    srand(time(NULL));

    Planet planets[PLANET_COUNT];
    generate_planets(planets);

    int player_planet_index;
    do {
        printf("Welcome to the galaxy!\n");
        for (int i = 0; i < PLANET_COUNT; i++) {
            print_planet(&planets[i]);
        }
        printf("Choose your starting planet:\n");
        for (int i = 0; i < PLANET_COUNT; i++) {
            printf("%d. %s\n", i + 1, planets[i].name);
        }
        scanf("%d", &player_planet_index);
    } while (player_planet_index < 1 || player_planet_index > PLANET_COUNT);

    printf("You have chosen %s as your starting planet.\n", planets[player_planet_index - 1].name);

    return 0;
}