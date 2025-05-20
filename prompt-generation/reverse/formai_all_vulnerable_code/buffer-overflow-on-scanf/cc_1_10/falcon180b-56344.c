//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ALIENS 1000
#define MAX_CITIES 100
#define MAX_DEFENSES 10
#define MIN_POPULATION 1000
#define MAX_POPULATION 1000000
#define MIN_TECHNOLOGY 1
#define MAX_TECHNOLOGY 10
#define MIN_WEAPON_POWER 1
#define MAX_WEAPON_POWER 100

typedef struct alien {
    int population;
    int technology;
    int weapon_power;
} Alien;

typedef struct city {
    int population;
    int defenses;
} City;

void generate_aliens(Alien aliens[], int num_aliens) {
    for (int i = 0; i < num_aliens; i++) {
        aliens[i].population = rand() % (MAX_POPULATION - MIN_POPULATION + 1) + MIN_POPULATION;
        aliens[i].technology = rand() % (MAX_TECHNOLOGY - MIN_TECHNOLOGY + 1) + MIN_TECHNOLOGY;
        aliens[i].weapon_power = rand() % (MAX_WEAPON_POWER - MIN_WEAPON_POWER + 1) + MIN_WEAPON_POWER;
    }
}

void generate_cities(City cities[], int num_cities) {
    for (int i = 0; i < num_cities; i++) {
        cities[i].population = rand() % (MAX_POPULATION - MIN_POPULATION + 1) + MIN_POPULATION;
        cities[i].defenses = rand() % (MAX_DEFENSES - 1) + 1; // At least 1 defense
    }
}

int main() {
    srand(time(NULL));

    int num_aliens, num_cities;
    printf("Enter the number of aliens: ");
    scanf("%d", &num_aliens);
    printf("Enter the number of cities: ");
    scanf("%d", &num_cities);

    Alien aliens[MAX_ALIENS];
    City cities[MAX_CITIES];

    generate_aliens(aliens, num_aliens);
    generate_cities(cities, num_cities);

    int num_invaded_cities = 0;
    for (int i = 0; i < num_aliens; i++) {
        for (int j = 0; j < num_cities; j++) {
            if (aliens[i].population >= cities[j].population &&
                aliens[i].weapon_power >= cities[j].defenses) {
                num_invaded_cities++;
                break;
            }
        }
    }

    double probability = ((double) num_invaded_cities / num_aliens) * 100.0;
    printf("The probability of alien invasion is %.2f%%\n", probability);

    return 0;
}