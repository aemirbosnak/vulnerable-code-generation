//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store information about planets
typedef struct Planet {
    char name[50];
    int distance;
    int resources;
} Planet;

// Function to generate a random number between min and max
int random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to print out details of a planet
void print_planet_info(Planet planet) {
    printf("Planet name: %s \n", planet.name);
    printf("Distance from Earth: %d light years\n", planet.distance);
    printf("Available resources: %d\n", planet.resources);
}

// Function to search for a planet by name
Planet search_for_planet(Planet planets[], int num_planets, char name[]) {
    int i;
    for (i = 0; i < num_planets; i++) {
        if (strcmp(planets[i].name, name) == 0) {
            return planets[i];
        }
    }
    // If planet not found, return a planet with zero resources
    Planet not_found;
    strcpy(not_found.name, "Not Found");
    not_found.distance = 0;
    not_found.resources = 0;
    return not_found;
}

int main() {
    int num_planets, i;
    printf("Welcome to the Space Adventure Program!\n\n");
    printf("How many planets would you like to explore? ");
    scanf("%d", &num_planets);

    // Create an array of planets
    Planet planets[num_planets];

    // Get user input to create each planet
    for (i = 0; i < num_planets; i++) {
        printf("Enter name of Planet %d: ", i+1);
        scanf("%s", planets[i].name);
        planets[i].distance = random_number(10, 100);
        planets[i].resources = random_number(100, 1000);
    }

    // Begin space exploration
    char search_name[50];
    while (1) {
        printf("\nEnter the name of the planet to explore (or type 'exit' to quit): ");
        scanf("%s", search_name);
        if (strcmp(search_name, "exit") == 0) {
            printf("\nThanks for exploring the universe with us!\n");
            break;
        }
        Planet search_result = search_for_planet(planets, num_planets, search_name);
        if (search_result.resources == 0) {
            printf("Sorry, we could not find a planet with that name.\n");
        } else {
            printf("\nCongratulations, we have found %s!\n", search_result.name);
            print_planet_info(search_result);
        }
    }
    return 0;
}