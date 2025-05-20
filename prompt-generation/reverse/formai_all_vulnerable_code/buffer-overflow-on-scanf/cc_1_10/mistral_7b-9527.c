//MISTRAL-7B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define NUM_PLANETS 10
#define NUM_ALIENS 100
#define PROB_OF_INVASION 0.05

typedef struct {
    char name[20];
    int population;
} Planet;

typedef struct {
    int id;
    int health;
} Alien;

void generate_aliens(Alien **aliens, int num_aliens) {
    *aliens = malloc(num_aliens * sizeof(Alien));
    for (int i = 0; i < num_aliens; i++) {
        (*aliens + i)->id = i + 1;
        (*aliens + i)->health = rand() % 10 + 1;
    }
}

void calculate_invasion_probability(Planet *planets, Alien *aliens, int num_planets, int num_aliens) {
    int invasion_count = 0;
    double invasion_probability = PROB_OF_INVASION;
    for (int i = 0; i < num_planets; i++) {
        int planet_defense = planets[i].population / num_aliens;
        double defense_probability = 1.0 - pow(invasion_probability, planet_defense);
        if (rand() % RAND_MAX < RAND_MAX * defense_probability) {
            invasion_count++;
        }
    }
    printf("Invasion probability: %.2f%%\n", invasion_probability * 100);
    printf("Number of planets invaded: %d\n", invasion_count);
}

int main() {
    srand(time(NULL));

    Planet planets[NUM_PLANETS];
    for (int i = 0; i < NUM_PLANETS; i++) {
        scanf("%s", planets[i].name);
        planets[i].population = rand() % 1000 + 1000;
        printf("Planet %s has a population of %d.\n", planets[i].name, planets[i].population);
    }

    Alien *aliens = NULL;
    int num_aliens = NUM_PLANETS * NUM_ALIENS;
    generate_aliens(&aliens, num_aliens);

    calculate_invasion_probability(planets, aliens, NUM_PLANETS, num_aliens);

    free(aliens);

    return 0;
}