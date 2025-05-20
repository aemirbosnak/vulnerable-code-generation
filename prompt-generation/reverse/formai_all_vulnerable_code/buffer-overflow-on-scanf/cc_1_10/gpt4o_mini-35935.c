//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ITEMS 5
#define MAX_ENEMIES 3
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int health;
    int attack;
    int defense;
} Character;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int attack;
} Item;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int health;
    int attack;
} Enemy;

void initializePlayer(Character *player) {
    strcpy(player->name, "Hero");
    player->health = 100;
    player->attack = 20;
    player->defense = 5;
}

void initializeEnemy(Enemy *enemy) {
    const char *enemyNames[MAX_ENEMIES] = {"Goblin", "Troll", "Witch"};
    int enemyIndex = rand() % MAX_ENEMIES;
    strcpy(enemy->name, enemyNames[enemyIndex]);
    enemy->health = 30 + (rand() % 21); // Health between 30 and 50
    enemy->attack = 5 + (rand() % 11); // Attack between 5 and 15
}

void showStatus(Character *player) {
    printf("\n%s's Health: %d\n", player->name, player->health);
}

void encounterEnemy(Character *player) {
    Enemy enemy;
    initializeEnemy(&enemy);
    printf("\nYou encountered a %s!\n", enemy.name);

    while (enemy.health > 0 && player->health > 0) {
        printf("1. Attack\n2. Defend\nChoose an action: ");
        int action;
        scanf("%d", &action);

        if (action == 1) {
            printf("You attack the %s!\n", enemy.name);
            enemy.health -= player->attack;
            printf("The %s has %d health left.\n", enemy.name, enemy.health);
            if (enemy.health > 0) {
                player->health -= enemy.attack;
                printf("The %s attacks you! You have %d health left.\n", enemy.name, player->health);
            }
        } else if (action == 2) {
            printf("You defend yourself!\n");
            player->health -= (enemy.attack - player->defense);
            if (player->health < 0) player->health = 0;
            printf("You have %d health left.\n", player->health);
        } else {
            printf("Invalid action! Try again.\n");
        }
    }

    if (player->health <= 0) {
        printf("You have been defeated by the %s! Game Over.\n", enemy.name);
        exit(0);
    } else {
        printf("You defeated the %s!\n", enemy.name);
    }
}

void exploreForest(Character *player) {
    int choice;
    do {
        printf("\nYou are in a mystical forest. What would you like to do?\n");
        printf("1. Explore deeper into the forest\n");
        printf("2. Look for items\n");
        printf("3. Check status\n");
        printf("4. Exit game\n");
        printf("Choose an action: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            encounterEnemy(player);
            break;
        case 2:
            printf("You searched for items but found nothing useful.\n");
            break;
        case 3:
            showStatus(player);
            break;
        case 4:
            printf("Thank you for playing!\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
}

int main() {
    srand(time(NULL));
    Character player;
    initializePlayer(&player);
    printf("Welcome to the Quest for the Lost Artifact!\n");
    exploreForest(&player);
    return 0;
}