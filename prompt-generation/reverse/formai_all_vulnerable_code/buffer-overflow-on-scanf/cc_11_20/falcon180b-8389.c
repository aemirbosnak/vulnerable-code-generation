//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISTANCE 1000000
#define MAX_POPULATION 1000000
#define MAX_TIME 1000000
#define MAX_YEARS 1000000
#define MAX_TECH_LEVEL 1000000

int main() {
    int distance, population, time, years, tech_level;
    int earth_population = 7500000000;
    int earth_tech_level = 7;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");

    printf("Please enter the following parameters:\n");
    printf("1. Distance from Earth (in light years): ");
    scanf("%d", &distance);

    printf("2. Population of alien planet (in millions): ");
    scanf("%d", &population);

    printf("3. Time since alien civilization started (in years): ");
    scanf("%d", &time);

    printf("4. Years until alien civilization reaches Earth (if traveling at light speed): ");
    scanf("%d", &years);

    printf("5. Technology level of alien civilization (1-10): ");
    scanf("%d", &tech_level);

    if (distance > MAX_DISTANCE || population > MAX_POPULATION || time > MAX_TIME || years > MAX_YEARS || tech_level > MAX_TECH_LEVEL) {
        printf("Invalid input. Please try again.\n");
        return 1;
    }

    int invasion_probability = 0;

    if (population > earth_population) {
        invasion_probability += 1;
    }

    if (tech_level > earth_tech_level) {
        invasion_probability += 2;
    }

    if (years < 100) {
        invasion_probability += 3;
    } else if (years < 1000) {
        invasion_probability += 2;
    } else if (years < 10000) {
        invasion_probability += 1;
    }

    if (distance < 10) {
        invasion_probability -= 3;
    } else if (distance < 100) {
        invasion_probability -= 2;
    } else if (distance < 1000) {
        invasion_probability -= 1;
    }

    invasion_probability = invasion_probability * (rand() % 100) / 100;

    printf("The probability of an alien invasion is %.2f%%\n", invasion_probability);

    return 0;
}