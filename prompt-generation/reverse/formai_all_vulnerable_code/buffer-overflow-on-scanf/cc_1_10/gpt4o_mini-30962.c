//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 5
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int fuelCost;
    int healthCost;
} Planet;

typedef struct {
    int health;
    int fuel;
    int score;
} Player;

void initializePlanets(Planet planets[]) {
    strcpy(planets[0].name, "Zargon");
    planets[0].fuelCost = 10;
    planets[0].healthCost = 5;

    strcpy(planets[1].name, "Morpheus");
    planets[1].fuelCost = 15;
    planets[1].healthCost = 10;

    strcpy(planets[2].name, "Aether");
    planets[2].fuelCost = 20;
    planets[2].healthCost = 15;

    strcpy(planets[3].name, "Nebulette");
    planets[3].fuelCost = 12;
    planets[3].healthCost = 3;

    strcpy(planets[4].name, "Xandar");
    planets[4].fuelCost = 25;
    planets[4].healthCost = 20;
}

void printPlanets(Planet planets[]) {
    printf("Available Planets:\n");
    for(int i = 0; i < MAX_PLANETS; i++) {
        printf("%d: %s (Fuel Cost: %d, Health Cost: %d)\n", i + 1, planets[i].name, planets[i].fuelCost, planets[i].healthCost);
    }
}

int travelToPlanet(Player* player, Planet* planet) {
    if (player->fuel < planet->fuelCost) {
        printf("Not enough fuel to travel to %s!\n", planet->name);
        return 0;
    }
    if (player->health < planet->healthCost) {
        printf("Not enough health to sustain travel to %s!\n", planet->name);
        return 0;
    }

    player->fuel -= planet->fuelCost;
    player->health -= planet->healthCost;
    player->score += 10; // Increment score for a successful travel

    printf("Traveling to %s... Successful!\n", planet->name);
    printf("Current Status: Health: %d, Fuel: %d, Score: %d\n", player->health, player->fuel, player->score);
    return 1;
}

void displayStatus(Player player) {
    printf("Player Status - Health: %d, Fuel: %d, Score: %d\n", player.health, player.fuel, player.score);
}

void gameLoop() {
    Player player = {100, 50, 0}; // Initial player status
    Planet planets[MAX_PLANETS];
    
    initializePlanets(planets);

    while (player.health > 0 && player.fuel > 0) {
        printPlanets(planets);
        displayStatus(player);

        int choice;
        printf("Select a planet to travel to (1-%d) or enter 0 to quit: ", MAX_PLANETS);
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting game. Final score: %d\n", player.score);
            break;
        } else if (choice < 1 || choice > MAX_PLANETS) {
            printf("Invalid choice! Please select again.\n");
            continue;
        }

        travelToPlanet(&player, &planets[choice - 1]);
    }

    if (player.health <= 0) {
        printf("You have lost all your health. Game Over!\n");
    } else if (player.fuel <= 0) {
        printf("You have run out of fuel. Game Over!\n");
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator
    printf("Welcome to the Space Adventure!\n");
    gameLoop();
    return 0;
}