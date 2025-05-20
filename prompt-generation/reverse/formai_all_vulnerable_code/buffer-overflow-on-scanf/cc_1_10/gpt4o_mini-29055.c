//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ACTIONS 5
#define MAX_NAME_LENGTH 50
#define MAX_ENEMY_TYPES 3

typedef struct {
    char name[MAX_NAME_LENGTH];
    int health;
    int resources;
} Player;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int strength;
} Enemy;

void initPlayer(Player *player);
void displayStatus(Player player);
void encounterEnemy(Player *player, Enemy enemy);
void collectResources(Player *player);
void explore(Player *player);
void displayIntro();

int main() {
    Player player;
    Enemy enemies[MAX_ENEMY_TYPES] = {
        {"Space Raider", 20},
        {"Galactic Beast", 30},
        {"Asteroid Worm", 15}
    };

    srand(time(NULL));
    displayIntro();
    initPlayer(&player);

    int choice;
    while (player.health > 0) {
        printf("\nChoose an action:\n1. Explore\n2. Collect Resources\n3. View Status\n4. Quit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                explore(&player);
                break;
            case 2:
                collectResources(&player);
                break;
            case 3:
                displayStatus(player);
                break;
            case 4:
                printf("Quitting the game. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    printf("You have been defeated! Game Over.\n");
    return 0;
}

void displayIntro() {
    printf("Welcome to the Space Adventure Game!\n");
    printf("As a brave space explorer, you will encounter many challenges and adventures.\n");
    printf("Survive the vastness of space by managing your health and resources. Good luck!\n");
}

void initPlayer(Player *player) {
    printf("Enter your player name: ");
    scanf("%s", player->name);
    player->health = 100;
    player->resources = 0;
    printf("Welcome, %s! Your journey begins with %d health and %d resources.\n", player->name, player->health, player->resources);
}

void displayStatus(Player player) {
    printf("\n--- Player Status ---\n");
    printf("Name: %s\n", player.name);
    printf("Health: %d\n", player.health);
    printf("Resources: %d\n", player.resources);
    printf("---------------------\n");
}

void encounterEnemy(Player *player, Enemy enemy) {
    printf("You have encountered a %s with strength %d!\n", enemy.name, enemy.strength);

    while (player->health > 0 && enemy.strength > 0) {
        printf("Fight! Your health: %d, Enemy strength: %d\n", player->health, enemy.strength);
        printf("You attack!\n");
        enemy.strength -= 10;

        if (enemy.strength > 0) {
            printf("The enemy attacks you back!\n");
            player->health -= enemy.strength / 2; // Enemy attacks back
        }
    }

    if (player->health <= 0) {
        printf("You have been defeated by the %s!\n", enemy.name);
    } else {
        printf("You have defeated the %s!\n", enemy.name);
    }
}

void collectResources(Player *player) {
    int resources_collected = rand() % 20 + 1; // Collect between 1 and 20 resources
    player->resources += resources_collected;
    printf("You have collected %d resources!\n", resources_collected);
}

void explore(Player *player) {
    printf("You are exploring the vastness of space...\n");

    int encounter_chance = rand() % 100;
    if (encounter_chance < 50) {
        printf("It's a peaceful area. You gather some stardust and ancient artifacts.\n");
        collectResources(player);
    } else {
        int enemy_index = rand() % MAX_ENEMY_TYPES;
        encounterEnemy(player, (Enemy){"Space Raider", 20 + enemy_index * 10});
    }
}