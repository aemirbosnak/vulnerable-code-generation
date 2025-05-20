//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLANETS 10
#define MAX_CHAR 100

typedef struct {
    char name[MAX_CHAR];
    int distance; // distance in light years
    int resources; // resource points
    int is_visited; // visited status
} Planet;

void initialize_planets(Planet planets[], int count) {
    const char *names[] = {"Zyphor", "Altarus", "Nirvona", "Elysium", "Draconis", "Vortexia", "Erebos", "Triton", "Helios", "Orion"};
    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        strcpy(planets[i].name, names[i]);
        planets[i].distance = rand() % 100 + 1; // distances between 1 to 100 light years
        planets[i].resources = rand() % 500 + 1; // resource points between 1 to 500
        planets[i].is_visited = 0; // initialized as not visited
    }
}

void display_planets(Planet planets[], int count) {
    printf("Available Planets:\n");
    for (int i = 0; i < count; i++) {
        printf("Planet: %s | Distance: %d light years | Resources: %d | ", 
               planets[i].name, planets[i].distance, planets[i].resources);
        printf("%s\n", planets[i].is_visited ? "Visited" : "Not Visited");
    }
}

void visit_planet(Planet *planet) {
    if (planet->is_visited) {
        printf("You have already visited %s.\n", planet->name);
    } else {
        printf("Traveling to %s...\n", planet->name);
        planet->is_visited = 1;
        printf("You have discovered %d resources on %s!\n", planet->resources, planet->name);
    }
}

void space_adventure() {
    Planet planets[MAX_PLANETS];
    int count = MAX_PLANETS;
    int choice;
    initialize_planets(planets, count);

    while (1) {
        display_planets(planets, count);
        
        printf("Choose a planet to visit (1-%d) or 0 to exit: ", count);
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Ending your space adventure. Safe travels!\n");
            break;
        } else if (choice >= 1 && choice <= count) {
            visit_planet(&planets[choice - 1]);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    }
}

int main() {
    printf("******* Galactic Exploration Program *******\n");
    space_adventure();
    return 0;
}