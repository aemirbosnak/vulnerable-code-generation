//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 5

typedef struct {
    char name[30];
    int resources;
    int danger_level;
} Planet;

void initialize_planets(Planet planets[], int size);
void explore_planet(Planet planet);
void display_intro();
int random_resources();
int random_danger();

int main() {
    Planet planets[MAX_PLANETS];
    int choice;

    srand(time(NULL)); // Seed random number generator

    display_intro();
    initialize_planets(planets, MAX_PLANETS);

    while (1) {
        printf("\nAvailable planets to explore:\n");
        for (int i = 0; i < MAX_PLANETS; i++) {
            printf("%d. %s (Resources: %d, Danger Level: %d)\n", i + 1, planets[i].name, planets[i].resources, planets[i].danger_level);
        }
        printf("Enter the number of the planet you want to explore (0 to exit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Thank you for playing Space Adventure!\n");
            break;
        } else if (choice < 1 || choice > MAX_PLANETS) {
            printf("Invalid choice. Please try again.\n");
        } else {
            explore_planet(planets[choice - 1]);
        }
    }

    return 0;
}

void display_intro() {
    printf("**************************************************\n");
    printf("*           Welcome to Space Adventure!          *\n");
    printf("* Explore new planets, gather resources, and     *\n");
    printf("* survive the dangers of the universe!           *\n");
    printf("**************************************************\n");
}

void initialize_planets(Planet planets[], int size) {
    const char* names[] = {"Mars", "Venus", "Jupiter", "Saturn", "Mercury"};
    
    for (int i = 0; i < size; i++) {
        snprintf(planets[i].name, sizeof(planets[i].name), "%s", names[i]);
        planets[i].resources = random_resources();
        planets[i].danger_level = random_danger();
    }
}

void explore_planet(Planet planet) {
    printf("\nExploring %s...\n", planet.name);
    
    if (planet.danger_level < 3) {
        printf("The exploration was successful! You collected %d resources!\n", planet.resources);
    } else if (planet.danger_level < 6) {
        printf("You encountered aliens! You managed to escape with %d resources!\n", planet.resources / 2);
    } else {
        printf("It's too dangerous! You barely escaped without any resources!\n");
    }
}

int random_resources() {
    return rand() % 100 + 1; // Generates a random number between 1-100
}

int random_danger() {
    return rand() % 10 + 1; // Generates a danger level between 1-10
}