//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.01
#define EARTH_CIRUMFERENCE 40075.16
#define EARTH_SURFACE_AREA 510.1e6
#define POPULATION 7.6e9
#define FIRST_CONTACT_YEAR 1947
#define SIMULATION_YEARS 75
#define ALIEN_TECH_LEVEL 9
#define EARTH_TECH_LEVEL 7
#define ALIEN_AGGRESSIVENESS 8
#define EARTH_MILITARY_STRENGTH 6
#define ABDUCTION_RATE 0.0001
#define DEATH_RATE 0.5
#define REPRODUCTION_RATE 0.01
#define INITIAL_POPULATION 1000

void alien_invasion(int tech_level, int aggressiveness, int population, double *death_rate, double *reproduction_rate) {
    int num_deaths = 0;
    int num_reproductions = 0;
    double invasion_score = 0;
    int i;
    srand(time(NULL));
    for (i = 0; i < population; i++) {
        if (rand() % 100 < *death_rate) {
            num_deaths++;
        } else if (rand() % 100 < *reproduction_rate) {
            num_reproductions++;
        }
    }
    invasion_score = ((double)num_reproductions / population) - ((double)num_deaths / population);
    invasion_score *= tech_level;
    invasion_score *= aggressiveness;
    printf("The aliens have a %.2f%% chance of successfully invading Earth.\n", invasion_score * 100);
}

int main() {
    double death_rate, reproduction_rate;
    int tech_level, aggressiveness, population;
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the alien's technology level (1-10): ");
    scanf("%d", &tech_level);
    printf("Please enter the alien's aggressiveness level (1-10): ");
    scanf("%d", &aggressiveness);
    printf("Please enter the initial population of aliens: ");
    scanf("%d", &population);
    death_rate = ABDUCTION_RATE;
    reproduction_rate = REPRODUCTION_RATE;
    alien_invasion(tech_level, aggressiveness, population, &death_rate, &reproduction_rate);
    return 0;
}