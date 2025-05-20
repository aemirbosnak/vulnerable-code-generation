//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 5
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int resources;
    int monsters;
} Planet;

typedef struct {
    char playerName[MAX_NAME_LENGTH];
    int totalResources;
} Player;

void initializePlanets(Planet planets[]) {
    const char *planetNames[] = {"Zyphos", "Xeloria", "Rinfra", "Treasonus", "Galactron"};
    
    for (int i = 0; i < MAX_PLANETS; i++) {
        strcpy(planets[i].name, planetNames[i]);
        planets[i].resources = rand() % 100 + 1; // Random resources between 1 and 100
        planets[i].monsters = rand() % 10; // Random monsters between 0 and 9
    }
}

void displayPlanets(Planet planets[]) {
    printf("Available Planets:\n");
    for (int i = 0; i < MAX_PLANETS; i++) {
        printf("%d. %s - Resources: %d, Monsters: %d\n", 
            i + 1, planets[i].name, planets[i].resources, planets[i].monsters);
    }
}

void explorePlanet(Player *player, Planet *planet) {
    printf("Exploring %s...\n", planet->name);

    if (planet->monsters > 0) {
        printf("Warning! Monsters detected on %s!\n", planet->name);
        printf("You must defeat the monsters to collect resources!\n");
        
        int monsterEncounter = rand() % 2; // 0 = lose, 1 = win
        if (monsterEncounter == 0) {
            printf("You encountered monsters and lost the battle! Retreating...\n");
            return;
        } else {
            printf("You defeated the monsters!\n");
        }
    }
    
    // Collect resources
    player->totalResources += planet->resources;
    printf("You collected %d resources from %s!\n", planet->resources, planet->name);
    planet->resources = 0; // Resources depleted
}

int main() {
    srand(time(0)); // Seed for random number generation

    Player player;
    Planet planets[MAX_PLANETS];

    // Initialize player
    printf("Enter your explorer name: ");
    scanf("%s", player.playerName);
    player.totalResources = 0;

    // Initialize planets
    initializePlanets(planets);

    int choice;
    while (1) {
        displayPlanets(planets);
        printf("1. Explore a planet\n");
        printf("2. Check resources\n");
        printf("3. Exit game\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Which planet would you like to explore? (1-%d): ", MAX_PLANETS);
                int planetChoice;
                scanf("%d", &planetChoice);
                if (planetChoice < 1 || planetChoice > MAX_PLANETS) {
                    printf("Invalid choice! Please choose a valid planet.\n");
                } else {
                    explorePlanet(&player, &planets[planetChoice - 1]);
                }
                break;
            case 2:
                printf("Total Resources Collected: %d\n", player.totalResources);
                break;
            case 3:
                printf("Thank you for playing, %s! Safe travels in the galaxy!\n", player.playerName);
                exit(0);
            default:
                printf("Invalid option! Please choose again.\n");
        }
    }
    return 0;
}