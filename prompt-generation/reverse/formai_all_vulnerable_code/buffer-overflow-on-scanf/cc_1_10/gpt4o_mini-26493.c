//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 5
#define MAX_ENEMIES 3
#define MAX_PLAYER_HEALTH 100

typedef struct {
    char name[20];
    int dangerLevel;
    int resources;
} Planet;

typedef struct {
    char name[20];
    int attackPower;
    int health;
} Enemy;

typedef struct {
    char name[20];
    int health;
    int resources;
} Player;

void initializePlanets(Planet planets[]) {
    const char *names[MAX_PLANETS] = {"Zargon", "Trelon", "Mirkon", "Hectos", "Walyx"};
    for (int i = 0; i < MAX_PLANETS; i++) {
        strcpy(planets[i].name, names[i]);
        planets[i].dangerLevel = rand() % 10 + 1; // Danger level 1 to 10
        planets[i].resources = rand() % 100 + 1; // Resources 1 to 100
    }
}

void initializeEnemies(Enemy enemies[]) {
    const char *names[MAX_ENEMIES] = {"Space Pirate", "Alien Beast", "Warp Raider"};
    for (int i = 0; i < MAX_ENEMIES; i++) {
        strcpy(enemies[i].name, names[i]);
        enemies[i].attackPower = rand() % 20 + 1; // Attack power 1 to 20
        enemies[i].health = rand() % 100 + 20;   // Health 20 to 100
    }
}

void displayPlanets(Planet planets[]) {
    printf("Available Planets:\n");
    for (int i = 0; i < MAX_PLANETS; i++) {
        printf("Planet: %s | Danger Level: %d | Resources: %d\n", planets[i].name, planets[i].dangerLevel, planets[i].resources);
    }
}

void displayEnemies(Enemy enemies[]) {
    printf("Enemies Encountered:\n");
    for (int i = 0; i < MAX_ENEMIES; i++) {
        printf("Enemy: %s | Attack Power: %d | Health: %d\n", enemies[i].name, enemies[i].attackPower, enemies[i].health);
    }
}

void attackEnemy(Player *player, Enemy *enemy) {
    printf("%s attacks %s!\n", player->name, enemy->name);
    enemy->health -= 10; // Player attack reduces enemy health
    if (enemy->health < 0) {
        enemy->health = 0;
    }
    printf("%s's health: %d\n", enemy->name, enemy->health);
}

void enemyAttack(Player *player, Enemy *enemy) {
    printf("%s attacks %s!\n", enemy->name, player->name);
    player->health -= enemy->attackPower; // Enemy attack reduces player health
    if (player->health < 0) {
        player->health = 0;
    }
    printf("%s's health: %d\n", player->name, player->health);
}

int main() {
    srand(time(NULL));
    
    Planet planets[MAX_PLANETS];
    initializePlanets(planets);
    
    Player player = {"Captain Zark", MAX_PLAYER_HEALTH, 0};
    
    displayPlanets(planets);
    
    printf("\nChoose a planet (0-%d): ", MAX_PLANETS - 1);
    int choice;
    scanf("%d", &choice);
    
    if (choice < 0 || choice >= MAX_PLANETS) {
        printf("Invalid choice! Exiting...\n");
        return 1;
    }
    
    printf("\nYou have chosen to explore %s!\n", planets[choice].name);
    player.resources += planets[choice].resources;

    Enemy enemies[MAX_ENEMIES];
    initializeEnemies(enemies);
    displayEnemies(enemies);
    
    for (int i = 0; i < MAX_ENEMIES; i++) {
        while (player.health > 0 && enemies[i].health > 0) {
            attackEnemy(&player, &enemies[i]);
            if (enemies[i].health > 0) {
                enemyAttack(&player, &enemies[i]);
            }
        }
        if (player.health <= 0) {
            printf("\n%s has been defeated by %s!\n", player.name, enemies[i].name);
            break;
        } else {
            printf("%s has defeated %s!\n", player.name, enemies[i].name);
        }
    }
    
    if (player.health > 0) {
        printf("\n%s completed the adventure with remaining health: %d and resources collected: %d\n", player.name, player.health, player.resources);
    }
    
    return 0;
}