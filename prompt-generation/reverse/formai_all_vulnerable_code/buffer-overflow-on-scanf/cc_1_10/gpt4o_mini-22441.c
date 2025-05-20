//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 5
#define MAX_ITEMS 3

typedef struct {
    char name[20];
    int hasTreasure;
} Planet;

typedef struct {
    char name[20];
    int count;
} Item;

void initializePlanets(Planet planets[]) {
    char *planetNames[MAX_PLANETS] = {"Mars", "Jupiter", "Venus", "Saturn", "Neptune"};
    
    for (int i = 0; i < MAX_PLANETS; i++) {
        snprintf(planets[i].name, sizeof(planets[i].name), "%s", planetNames[i]);
        planets[i].hasTreasure = rand() % 2; // Randomly give treasure or not
    }
}

void initializeItems(Item items[]) {
    char *itemNames[MAX_ITEMS] = {"Space Ore", "Alien Artifact", "Stellar Map"};
    
    for (int i = 0; i < MAX_ITEMS; i++) {
        snprintf(items[i].name, sizeof(items[i].name), "%s", itemNames[i]);
        items[i].count = 0; // Initialize item count to 0
    }
}

void displayPlanets(Planet planets[]) {
    printf("Available Planets:\n");
    for (int i = 0; i < MAX_PLANETS; i++) {
        printf("%d. %s\n", i + 1, planets[i].name);
    }
}

void visitPlanet(Planet planets[], Item items[]) {
    int choice;
    printf("Choose a planet to visit (1-%d): ", MAX_PLANETS);
    scanf("%d", &choice);
    
    if (choice < 1 || choice > MAX_PLANETS) {
        printf("Invalid choice! Returning to planet selection.\n\n");
        return;
    }
    
    Planet currentPlanet = planets[choice - 1];
    printf("\nYou have arrived at %s!\n", currentPlanet.name);
    
    if (currentPlanet.hasTreasure) {
        int itemIndex = rand() % MAX_ITEMS;
        items[itemIndex].count++;
        printf("You found a %s!\n", items[itemIndex].name);
    } else {
        printf("Unfortunately, there were no treasures on this planet.\n");
    }
}

void displayItems(Item items[]) {
    printf("\nYour Inventory:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("%s: %d\n", items[i].name, items[i].count);
    }
}

void randomEvent() {
    int event = rand() % 3; // Three possible events
    if (event == 0) {
        printf("You encountered a friendly alien!\n");
    } else if (event == 1) {
        printf("A meteor shower is happening, brace for impact!\n");
    } else {
        printf("You found some space debris to collect!\n");
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    Planet planets[MAX_PLANETS];
    Item items[MAX_ITEMS];
    initializePlanets(planets);
    initializeItems(items);
    
    int playing = 1;
    
    printf("Welcome to the Space Adventure Game!\n");
    
    while (playing) {
        displayPlanets(planets);
        visitPlanet(planets, items);
        displayItems(items);
        
        printf("\nDo you want to continue your adventure? (1 for Yes, 0 for No): ");
        scanf("%d", &playing);
        
        if (playing) {
            randomEvent(); // Trigger a random event if continuing
        }
    }
    
    printf("Thank you for playing! Safe travels, adventurer!\n");
    return 0;
}