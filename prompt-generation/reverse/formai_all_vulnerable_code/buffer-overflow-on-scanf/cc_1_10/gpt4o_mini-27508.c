//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 5
#define MAX_ACTIONS 3
#define MAX_MESSAGE_LENGTH 100

const char *planet_names[MAX_PLANETS] = {"Zorath", "Xeloria", "Vortan", "Drakos", "Thalium"};
const char *actions[MAX_ACTIONS] = {"Explore", "Trade", "Rest"};

typedef struct {
    char name[50];
    int resources;
    int health;
} Player;

typedef struct {
    char name[50];
    int resources;
} Planet;

void initialize_player(Player *player) {
    printf("Enter your space captain name: ");
    fgets(player->name, sizeof(player->name), stdin);
    player->name[strcspn(player->name, "\n")] = 0; // Remove newline
    player->resources = 100;
    player->health = 100;
    printf("Welcome, Captain %s! Prepare for your adventure!\n", player->name);
}

void initialize_planets(Planet *planets) {
    for (int i = 0; i < MAX_PLANETS; i++) {
        strcpy(planets[i].name, planet_names[i]);
        planets[i].resources = rand() % 100 + 50; // Random resources between 50 and 150
    }
}

void display_status(Player player) {
    printf("\n=== Player Status ===\n");
    printf("Name: %s\n", player.name);
    printf("Resources: %d\n", player.resources);
    printf("Health: %d\n", player.health);
    printf("======================\n");
}

void display_planets(Planet *planets) {
    printf("\n=== Available Planets ===\n");
    for (int i = 0; i < MAX_PLANETS; i++) {
        printf("%d. %s (Resources: %d)\n", i + 1, planets[i].name, planets[i].resources);
    }
    printf("=========================\n");
}

void explore_planet(Player *player, Planet *planet) {
    int found_resources = rand() % 50 + 25; // Random find between 25 to 75 resources
    player->resources += found_resources;
    printf("You explored %s and found %d resources!\n", planet->name, found_resources);
}

void trade_with_planet(Player *player, Planet *planet) {
    if (player->resources >= 30) {
        player->resources -= 30; // Cost of trading
        printf("You traded with %s and gained 20 resources!\n", planet->name);
        player->resources += 20;
    } else {
        printf("Not enough resources to trade with %s.\n", planet->name);
    }
}

void rest_on_planet(Player *player) {
    if(player->health < 100) {
        player->health += 10; // Rest restores health
        if (player->health > 100) player->health = 100; // Cap health at 100
        printf("You rested on the planet and regained health!\n");
    } else {
        printf("You are already at full health!\n");
    }
}

void perform_action(Player *player, Planet *planet) {
    int action_choice;
    printf("Choose an action:\n");
    for (int i = 0; i < MAX_ACTIONS; i++) {
        printf("%d. %s\n", i + 1, actions[i]);
    }
    printf("Enter the number of your action: ");
    scanf("%d", &action_choice);

    switch (action_choice) {
        case 1:
            explore_planet(player, planet);
            break;
        case 2:
            trade_with_planet(player, planet);
            break;
        case 3:
            rest_on_planet(player);
            break;
        default:
            printf("Invalid action!\n");
            break;
    }
}

int main() {
    srand(time(0)); // Seed for randomness
    Player player;
    Planet planets[MAX_PLANETS];

    initialize_player(&player);
    initialize_planets(planets);

    while (player.health > 0) {
        display_status(player);
        display_planets(planets);

        int planet_choice;
        printf("Choose a planet to visit (1-%d): ", MAX_PLANETS);
        scanf("%d", &planet_choice);
        
        if (planet_choice < 1 || planet_choice > MAX_PLANETS) {
            printf("Invalid planet choice. Please select again.\n");
            continue;
        }

        perform_action(&player, &planets[planet_choice - 1]);
        
        // To simulate health reduction or game-over conditions
        if (player.resources <= 0) {
            printf("You've run out of resources! Game Over.\n");
            break;
        }
    }

    printf("Thank you for playing, Captain %s!\n", player.name);
    return 0;
}