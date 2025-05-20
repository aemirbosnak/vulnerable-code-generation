//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 100

typedef struct {
    char name[50];
    int population;
    int defense_system;
    int resources;
} Planet;

void generate_planets(Planet planets[], int num_planets) {
    for (int i = 0; i < num_planets; i++) {
        planets[i].population = rand() % 1000000;
        planets[i].defense_system = rand() % 100;
        planets[i].resources = rand() % 100;

        sprintf(planets[i].name, "Planet %d", i + 1);
    }
}

int main() {
    srand(time(NULL));

    int num_planets;
    printf("Enter the number of planets: ");
    scanf("%d", &num_planets);

    if (num_planets > MAX_PLANETS || num_planets <= 0) {
        printf("Invalid number of planets.\n");
        return 1;
    }

    Planet planets[num_planets];
    generate_planets(planets, num_planets);

    int total_population = 0;
    int total_defense_system = 0;
    int total_resources = 0;

    for (int i = 0; i < num_planets; i++) {
        total_population += planets[i].population;
        total_defense_system += planets[i].defense_system;
        total_resources += planets[i].resources;
    }

    double avg_population = (double)total_population / num_planets;
    double avg_defense_system = (double)total_defense_system / num_planets;
    double avg_resources = (double)total_resources / num_planets;

    printf("Average population: %.2f\n", avg_population);
    printf("Average defense system: %.2f\n", avg_defense_system);
    printf("Average resources: %.2f\n", avg_resources);

    return 0;
}