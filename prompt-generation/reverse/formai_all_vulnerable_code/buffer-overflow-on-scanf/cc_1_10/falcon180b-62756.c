//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 1000
#define MAX_ALIENS 1000

struct planet {
    char name[20];
    int population;
    int defense_system;
};

struct alien {
    char name[20];
    int technology_level;
    int invasion_success_rate;
};

int main() {
    srand(time(NULL));

    struct planet planets[MAX_PLANETS];
    int num_planets;
    printf("Enter the number of planets: ");
    scanf("%d", &num_planets);

    for (int i = 0; i < num_planets; i++) {
        planets[i].population = rand() % 10000 + 1;
        planets[i].defense_system = rand() % 100;
        printf("Enter the name of planet %d: ", i+1);
        scanf("%s", planets[i].name);
    }

    struct alien aliens[MAX_ALIENS];
    int num_aliens;
    printf("Enter the number of aliens: ");
    scanf("%d", &num_aliens);

    for (int i = 0; i < num_aliens; i++) {
        aliens[i].technology_level = rand() % 100;
        aliens[i].invasion_success_rate = rand() % 100;
        printf("Enter the name of alien %d: ", i+1);
        scanf("%s", aliens[i].name);
    }

    int num_invasions = 0;
    for (int i = 0; i < num_aliens; i++) {
        for (int j = 0; j < num_planets; j++) {
            if (aliens[i].technology_level >= planets[j].defense_system) {
                if (rand() % 100 <= aliens[i].invasion_success_rate) {
                    printf("%s has successfully invaded %s!\n", aliens[i].name, planets[j].name);
                    num_invasions++;
                } else {
                    printf("%s has failed to invade %s.\n", aliens[i].name, planets[j].name);
                }
            } else {
                printf("%s has failed to invade %s.\n", aliens[i].name, planets[j].name);
            }
        }
    }

    printf("Out of %d invasions, %d were successful.\n", num_aliens * num_planets, num_invasions);

    return 0;
}