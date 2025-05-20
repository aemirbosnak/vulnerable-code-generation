//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    char planet_names[9][20] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"};
    int planet_distances[9] = {36, 67, 93, 140, 483, 886, 1782, 2794, 3670};
    int planet_population[9] = {0, 0, 7900, 0, 0, 0, 0, 0, 0};
    int current_planet = 2;
    int fuel = 1000;
    char input[10];

    printf("Welcome to the Space Adventure Program!\n");
    printf("You are currently on planet Earth, which is %d million miles away from the sun.\n", planet_distances[2]);
    printf("The year is 2050, and you have been chosen to embark on a mission to explore the solar system.\n");
    printf("Your mission is to visit as many planets as you can and gather as much data as possible.\n");
    printf("You have a spaceship with %d units of fuel, and each trip to a planet consumes 100 units of fuel.\n", fuel);

    while (1) {
        printf("You are now on planet %s.\n", planet_names[current_planet]);
        printf("This planet is %d million miles away from the sun and has a population of %d.\n", planet_distances[current_planet], planet_population[current_planet]);

        if (planet_population[current_planet] == 0) {
            int new_population = rand() % 1000000;
            printf("There is no data available on the population of this planet, but your instruments indicate that there are approximately %d inhabitants.\n", new_population);
            planet_population[current_planet] = new_population;
        }

        printf("Enter the number of the planet you want to visit (1-9), or enter q to quit: ");
        fgets(input, 10, stdin);
        fflush(stdin);

        if (input[0] == 'q') {
            break;
        }

        int target_planet = atoi(input);
        if (target_planet < 1 || target_planet > 9 || target_planet == current_planet) {
            printf("Invalid choice.\n");
        } else {
            fuel -= 100;
            if (fuel <= 0) {
                printf("Your spaceship is out of fuel. Mission failed.\n");
                return 0;
            } else {
                printf("You have travelled from planet %s to planet %s.\n", planet_names[current_planet], planet_names[target_planet]);
                current_planet = target_planet;
            }
        }
    }

    printf("Thanks for playing the Space Adventure Program!\n");
    return 0;
}