//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLANETS 5
#define MAX_RESOURCES 3
#define MAX_ENCOUNTERS 5

typedef struct {
    char name[30];
    int resources;
} Planet;

typedef struct {
    char name[30];
    int difficulty;
} Encounter;

Planet planets[MAX_PLANETS];
Encounter encounters[MAX_ENCOUNTERS];

void initialize_game() {
    // Initialize planets
    strcpy(planets[0].name, "Triton");
    planets[0].resources = 100;
    
    strcpy(planets[1].name, "Jupiter");
    planets[1].resources = 80;
    
    strcpy(planets[2].name, "Mars");
    planets[2].resources = 60;
    
    strcpy(planets[3].name, "Venus");
    planets[3].resources = 40;
    
    strcpy(planets[4].name, "Saturn");
    planets[4].resources = 70;

    // Initialize encounters
    strcpy(encounters[0].name, "Space Pirates");
    encounters[0].difficulty = 3;
    
    strcpy(encounters[1].name, "Meteor Shower");
    encounters[1].difficulty = 2;
    
    strcpy(encounters[2].name, "Alien Diplomacy");
    encounters[2].difficulty = 4;
    
    strcpy(encounters[3].name, "Black Hole");
    encounters[3].difficulty = 5;
    
    strcpy(encounters[4].name, "Shooting Stars");
    encounters[4].difficulty = 1;
}

int random_encounter() {
    return rand() % MAX_ENCOUNTERS;
}

void display_planets() {
    printf("Available Planets:\n");
    for (int i = 0; i < MAX_PLANETS; i++) {
        printf("%d. %s - Resources: %d\n", i + 1, planets[i].name, planets[i].resources);
    }
}

void explore_planet(int planet_index) {
    int encounter = random_encounter();
    printf("You have arrived at %s.\n", planets[planet_index].name);
    printf("You encounter: %s (Difficulty: %d)\n", encounters[encounter].name, encounters[encounter].difficulty);
    
    int outcome = rand() % 10; // Random outcome for encounters
    if (outcome < encounters[encounter].difficulty) {
        printf("You failed to overcome the encounter and lost resources!\n");
        planets[planet_index].resources -= 10;
    } else {
        printf("You successfully navigated the encounter and collected resources!\n");
        planets[planet_index].resources += 20;
    }
    
    printf("Updated resources on %s: %d\n", planets[planet_index].name, planets[planet_index].resources);
}

int main() {
    srand(time(NULL));
    initialize_game();
    
    int choice = 0;
    
    while (1) {
        display_planets();
        printf("Choose a planet to explore (1-%d) or 0 to quit: ", MAX_PLANETS);
        scanf("%d", &choice);
        
        if (choice == 0) {
            printf("Thank you for playing! Goodbye!\n");
            break;
        } else if (choice < 1 || choice > MAX_PLANETS) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }
        
        explore_planet(choice - 1);
    }
    
    return 0;
}