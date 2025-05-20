//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CITIES 100
#define NUM_DAYS 365
#define INVASION_RATE 0.001
#define CITY_POPULATION 1000000

int main() {
    int num_invasions = 0;
    int days_without_invasion = 0;
    int current_day = 0;
    int city_index = 0;
    int invaded_city_index = 0;
    int population_left = 0;
    int choice;

    srand(time(NULL));

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("This program will simulate an alien invasion on %d cities over the course of %d days.\n", NUM_CITIES, NUM_DAYS);
    printf("Please enter your choice:\n");
    printf("1. Start simulation\n");
    printf("2. Exit\n");

    scanf("%d", &choice);

    if (choice == 1) {
        for (current_day = 0; current_day < NUM_DAYS; current_day++) {
            invaded_city_index = rand() % NUM_CITIES;

            while (population_left > 0) {
                city_index = rand() % NUM_CITIES;
                if (city_index!= invaded_city_index) {
                    population_left -= CITY_POPULATION;
                }
            }

            printf("On day %d, the aliens invaded city %d and reduced the population to %d.\n", current_day+1, invaded_city_index+1, population_left);

            if (population_left == 0) {
                num_invasions++;
                days_without_invasion = 0;
            } else {
                days_without_invasion++;
            }
        }

        printf("\nThe simulation has ended.\n");
        printf("There were %d invasions over the course of %d days.\n", num_invasions, NUM_DAYS);
    } else {
        printf("Exiting program...\n");
    }

    return 0;
}