//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Struct for a planet
struct Planet {
    char name[20];
    int distance;
    int resources;
    int alien_race;
};

// Generate a random planet
struct Planet generate_planet() {
    struct Planet p;
    char names[10][20] = {"Alderaan", "Tatooine", "Hoth", "Naboo", "Coruscant", "Endor", "Bespin", "Yavin", "Dagobah", "Kashyyyk"};
    strcpy(p.name, names[rand()%10]);
    p.distance = rand()%1000 + 1;
    p.resources = rand()%100 + 1;
    p.alien_race = rand()%5 + 1;
    return p;
}

// Determine the alien race
void determine_alien_race(int alien_race) {
    switch(alien_race) {
        case 1:
            printf("The planet's inhabitants are humanoids.\n");
            break;
        case 2:
            printf("The planet's inhabitants are insectoids.\n");
            break;
        case 3:
            printf("The planet's inhabitants are reptilians.\n");
            break;
        case 4:
            printf("The planet's inhabitants are avians.\n");
            break;
        case 5:
            printf("The planet's inhabitants are aquatic beings.\n");
            break;
        default:
            printf("Unknown alien race.\n");
            break;
    }
}

int main() {
    srand(time(NULL)); // Set the seed for randomization
    struct Planet current_planet = generate_planet(); // Start on a random planet
    int resources_collected = 0;

    printf("Welcome to your space adventure!\n");
    printf("Your first stop is planet %s.\n", current_planet.name);

    while(current_planet.distance <= 1000) { // Continue until a planet over 1000 light years away is reached
        printf("You are currently %d light years from your starting planet.\n", current_planet.distance);
        printf("Planet %s has %d resources to collect.\n", current_planet.name, current_planet.resources);
        determine_alien_race(current_planet.alien_race);

        int choice;
        printf("Do you want to collect resources (1) or leave the planet and move on to the next one (2)? ");
        scanf("%d", &choice);

        if(choice == 1) { // Collect resources
            resources_collected += current_planet.resources;
            printf("You collected %d resources from planet %s.\n", current_planet.resources, current_planet.name);
            current_planet = generate_planet(); // Move on to the next planet
        }
        else if(choice == 2) { // Leave planet
            printf("You left planet %s without collecting any resources.\n", current_planet.name);
            current_planet = generate_planet(); // Move on to the next planet
        }
        else { // Invalid choice
            printf("Invalid choice. Please try again.\n");
        }
    }

    printf("Congratulations on completing your space adventure!\n");
    printf("You collected a total of %d resources.\n", resources_collected);

    return 0;
}