//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 5
#define MAX_RESOURCES 100
#define MAX_ENCOUNTERS 10

typedef struct {
    char name[20];
    int resources;
    int danger_level;
} Planet;

typedef struct {
    char name[20];
    int health;
} Player;

void initialize_planets(Planet planets[MAX_PLANETS]) {
    const char *planet_names[MAX_PLANETS] = {"Zarathos", "Quorax", "Xylon", "Elysium", "Nebulon"};
    
    for (int i = 0; i < MAX_PLANETS; i++) {
        snprintf(planets[i].name, sizeof(planets[i].name), "%s", planet_names[i]);
        planets[i].resources = rand() % MAX_RESOURCES;  // Random resources between 0 and 99
        planets[i].danger_level = rand() % 10;  // Random danger level
    }
}

void display_planet_info(Planet planet) {
    printf("Planet: %s\n", planet.name);
    printf("Resources Available: %d\n", planet.resources);
    printf("Danger Level: %d\n", planet.danger_level);
}

int explore_planet(Player *player, Planet *planet) {
    printf("Exploring %s...\n", planet->name);
    if (planet->danger_level > 5) {
        // Dangerous encounter
        printf("Warning! Danger level too high! You might face a challenge!\n");
        if (rand() % 2 == 0) {
            printf("You encountered a hostile alien! You lost 20 health!\n");
            player->health -= 20;
        } else {
            printf("You successfully avoided danger!\n");
        }
    } else {
        // Safe exploration
        printf("You gather %d resources from %s.\n", planet->resources, planet->name);
        player->health += planet->resources / 5; // Small health boost
    }
    
    return player->health > 0; // Return if player is still alive
}

void display_player_status(Player player) {
    printf("\nPlayer Status:\n");
    printf("Name: %s\n", player.name);
    printf("Health: %d\n", player.health);
}

int main() {
    srand(time(NULL));  // Seed the random number generator

    Player player;
    snprintf(player.name, sizeof(player.name), "Captain Nova");
    player.health = 100;

    Planet planets[MAX_PLANETS];
    initialize_planets(planets);

    printf("Welcome to the Space Adventure!\n");
    while (player.health > 0) {
        printf("\nChoose a planet to explore:\n");
        for (int i = 0; i < MAX_PLANETS; i++) {
            printf("%d. %s (Danger Level: %d)\n", i + 1, planets[i].name, planets[i].danger_level);
        }
        printf("Enter the number of the planet (1-%d) or 0 to exit: ", MAX_PLANETS);
        
        int choice;
        scanf("%d", &choice);
        
        if (choice == 0) {
            printf("Exiting the game. Safe travels, Captain Nova.\n");
            break;
        } else if (choice < 1 || choice > MAX_PLANETS) {
            printf("Invalid choice, please try again.\n");
            continue;
        }

        Planet selected_planet = planets[choice - 1];
        display_planet_info(selected_planet);
        
        if (!explore_planet(&player, &selected_planet)) {
            printf("You have perished in your adventures. Game Over.\n");
            break;
        }

        display_player_status(player);
    }

    printf("Thank you for playing Space Adventure!\n");
    return 0;
}