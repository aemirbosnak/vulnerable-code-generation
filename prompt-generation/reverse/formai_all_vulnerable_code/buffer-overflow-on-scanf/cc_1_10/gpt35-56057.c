//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define variables and structures
int player_health = 100;
int alien_health = 50;
int alien_attack = 10;

struct planet {
    char *name;
    int distance_from_earth;
    int has_resources;
} planets[5];

// Function declarations
void travel();
void fight();
void mine();
void stats();

// Main function
int main() {

    // Initialize random seed
    srand(time(NULL));

    // Initialize planets
    planets[0].name = "Mars";
    planets[0].distance_from_earth = 78000000;
    planets[0].has_resources = 1;

    planets[1].name = "Alpha Centauri";
    planets[1].distance_from_earth = 40000000000000;
    planets[1].has_resources = 0;

    planets[2].name = "Kepler-186f";
    planets[2].distance_from_earth = 49000000;
    planets[2].has_resources = 1;

    planets[3].name = "Proxima Centauri b";
    planets[3].distance_from_earth = 40000000000000;
    planets[3].has_resources = 0;

    planets[4].name = "Jupiter";
    planets[4].distance_from_earth = 550000000;
    planets[4].has_resources = 1;

    // Game loop
    while (player_health > 0) {
        printf("\nWhat would you like to do?\n");
        printf("1. Travel to a planet\n");
        printf("2. Fight an alien\n");
        printf("3. Mine for resources\n");
        printf("4. Check your stats\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                travel();
                break;
            case 2:
                fight();
                break;
            case 3:
                mine();
                break;
            case 4:
                stats();
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    printf("\nGame over. You have lost.\n");
    return 0;
}

// Function implementations
void travel() {
    printf("\nWhere would you like to go?\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s (%d km from Earth)\n", i+1, planets[i].name, planets[i].distance_from_earth);
    }
    int choice;
    scanf("%d", &choice);
    if (choice < 1 || choice > 5) {
        printf("Invalid choice. Try again.\n");
        return;
    }
    printf("You are now traveling to %s...\n", planets[choice-1].name);
    if (planets[choice-1].has_resources) {
        printf("You have arrived at %s. You have found some resources!\n", planets[choice-1].name);
    } else {
        printf("You have arrived at %s, but there are no resources to mine.\n", planets[choice-1].name);
    }
}

void fight() {
    printf("\nYou have encountered an alien!\n");
    while (alien_health > 0 && player_health > 0) {
        int player_attack = rand() % 20 + 1;
        int alien_damage = rand() % alien_attack + 1;
        alien_health -= player_attack;
        player_health -= alien_damage;
        printf("You attack for %d damage. The alien has %d health left.\n", player_attack, alien_health);
        if (alien_health <= 0) {
            printf("You have defeated the alien!\n");
        } else {
            printf("The alien attacks for %d damage. You have %d health left.\n", alien_damage, player_health);
        }
    }
}

void mine() {
    if (planets[0].has_resources) {
        printf("You spend some time mining on %s and collect some resources.\n", planets[0].name);
    } else {
        printf("There are no resources to mine on %s.\n", planets[0].name);
    }
}

void stats() {
    printf("\nPlayer Health: %d\n", player_health);
    printf("Alien Health: %d\n", alien_health);
    printf("Currently on %s\n", planets[0].name);
    if (planets[0].has_resources) {
        printf("This planet has resources to mine.\n");
    } else {
        printf("This planet has no resources to mine.\n");
    }
}