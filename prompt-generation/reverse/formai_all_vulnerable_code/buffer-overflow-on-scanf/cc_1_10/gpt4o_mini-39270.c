//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 10
#define BUFFER_SIZE 256

typedef struct {
    char name[BUFFER_SIZE];
    int distance; // in light years
    int resources; // resources available on the planet
} Planet;

void greet_player() {
    printf("Welcome, brave space explorer!\n");
    printf("Your mission is to explore the galaxy and discover new planets!\n");
    printf("May the stars light your path!\n\n");
}

void list_planets(Planet planets[], int count) {
    printf("Here are the planets you can explore:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - Distance: %d light years, Resources: %d\n", i + 1, planets[i].name, planets[i].distance, planets[i].resources);
    }
}

void explore_planet(Planet planet) {
    printf("You have traveled to %s.\n", planet.name);
    if (planet.resources > 0) {
        printf("This planet has %d resources available for you to collect!\n", planet.resources);
        planet.resources = 0; // Resources collected
        printf("You've successfully collected resources from %s!\n", planet.name);
    } else {
        printf("Oh no! You found no resources on %s.\n", planet.name);
    }
}

void discover_planets(Planet planets[], int *count) {
    srand(time(NULL));
    char *planet_names[] = {"Zorgon", "Xalax", "Ferros", "Ygdrassil", "Elysium"};
    
    for (int i = 0; i < MAX_PLANETS; i++) {
        strcpy(planets[i].name, planet_names[rand() % 5]);
        planets[i].distance = rand() % 50 + 1; // 1 to 50 light years
        planets[i].resources = rand() % 100; // 0 to 99 resources
    }
    
    *count = MAX_PLANETS; // Set the total planet count
}

int main() {
    Planet planets[MAX_PLANETS]; 
    int planet_count;

    greet_player();
    discover_planets(planets, &planet_count);
    
    while (1) {
        list_planets(planets, planet_count);
        printf("Choose a planet to explore (1-%d) or 0 to exit: ", planet_count);
        
        int choice;
        scanf("%d", &choice);
        
        if (choice == 0) {
            printf("Thank you for exploring the galaxy. Until next time, space traveler!\n");
            break;
        } else if (choice > 0 && choice <= planet_count) {
            explore_planet(planets[choice - 1]);
        } else {
            printf("Invalid choice. Please choose a valid planet number.\n");
        }
        
        printf("\n");
    }

    return 0;
}