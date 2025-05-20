//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of planets
#define MAX_PLANETS 10

// Define the structure of a planet
typedef struct {
    char name[20];
    int distance;
    int resources;
    int danger;
} Planet;

// Define the main function
int main() {
    // Initialize the random seed
    srand(time(NULL));

    // Create an array of planets
    Planet planets[MAX_PLANETS];

    // Initialize the planets
    for (int i = 0; i < MAX_PLANETS; i++) {
        planets[i].distance = rand() % 100;
        planets[i].resources = rand() % 100;
        planets[i].danger = rand() % 100;
    }

    // Print the list of planets
    printf("List of Planets:\n");
    for (int i = 0; i < MAX_PLANETS; i++) {
        printf("%s - Distance: %d - Resources: %d - Danger: %d\n", planets[i].name, planets[i].distance, planets[i].resources, planets[i].danger);
    }

    // Ask the user which planet to visit
    int choice;
    printf("\nWhich planet would you like to visit? ");
    scanf("%d", &choice);

    // Visit the chosen planet
    printf("\nYou have chosen to visit %s.\n", planets[choice].name);
    if (planets[choice].distance > 50) {
        printf("It will take a while to get there...\n");
    } else {
        printf("You arrive at %s.\n", planets[choice].name);
        if (planets[choice].resources > 50) {
            printf("You find valuable resources on this planet!\n");
        } else {
            printf("There are no valuable resources on this planet.\n");
        }
        if (planets[choice].danger > 50) {
            printf("Beware! This planet is dangerous!\n");
        } else {
            printf("This planet is safe.\n");
        }
    }

    return 0;
}