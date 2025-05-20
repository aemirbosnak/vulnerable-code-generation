//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NAME_LEN 30
#define MAX_ITEMS 5
#define MAP_SIZE 5

typedef struct {
    char name[MAX_NAME_LEN];
    int health;
    int attack;
    int defense;
} Player;

typedef struct {
    char name[MAX_NAME_LEN];
    int health;
    int attack;
    int defense;
} Enemy;

typedef struct {
    char items[MAX_ITEMS][MAX_NAME_LEN];
    int itemCount;
} Inventory;

void initializePlayer(Player *player) {
    printf("Enter your character's name: ");
    fgets(player->name, MAX_NAME_LEN, stdin);
    player->name[strcspn(player->name, "\n")] = 0; // Remove newline
    player->health = 100;
    player->attack = 20;
    player->defense = 5;
}

void initializeEnemy(Enemy *enemy) {
    const char *enemyNames[] = {"Goblin", "Orc", "Troll", "Bandit", "Wolf"};
    int randomIndex = rand() % 5;
    strcpy(enemy->name, enemyNames[randomIndex]);
    enemy->health = 50 + rand() % 50; // 50 to 100
    enemy->attack = 10 + rand() % 15; // 10 to 25
    enemy->defense = 2 + rand() % 5; // 2 to 6
}

void printPlayerStatus(Player player) {
    printf("\nPlayer: %s\nHealth: %d\n", player.name, player.health);
}

void printEnemyStatus(Enemy enemy) {
    printf("Enemy: %s\nHealth: %d\n", enemy.name, enemy.health);
}

void attack(Player *player, Enemy *enemy) {
    int damageDealt = player->attack - enemy->defense;
    if (damageDealt > 0) {
        enemy->health -= damageDealt;
        printf("%s attacks %s for %d damage!\n", player->name, enemy->name, damageDealt);
    } else {
        printf("%s's attack is too weak to damage %s!\n", player->name, enemy->name);
    }
}

void enemyAttack(Player *player, Enemy enemy) {
    int damageDealt = enemy.attack - player->defense;
    if (damageDealt > 0) {
        player->health -= damageDealt;
        printf("%s attacks %s for %d damage!\n", enemy.name, player->name, damageDealt);
    } else {
        printf("%s's attack is too weak to damage %s!\n", enemy.name, player->name);
    }
}

void combat(Player *player, Enemy *enemy) {
    while (player->health > 0 && enemy->health > 0) {
        printPlayerStatus(*player);
        printEnemyStatus(*enemy);
        attack(player, enemy);
        if (enemy->health > 0) {
            enemyAttack(player, *enemy);
        }
    }
    if (player->health <= 0) {
        printf("%s has been defeated!\n", player->name);
    } else {
        printf("%s has defeated %s!\n", player->name, enemy->name);
    }
}

void explore(Player *player) {
    int choice;
    printf("You are exploring the land...\n");
    printf("1. Search for enemies\n");
    printf("2. Check inventory\n");
    printf("3. Rest\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // Consume the newline left by scanf

    switch (choice) {
        case 1:
            {
                Enemy enemy;
                initializeEnemy(&enemy);
                printf("A wild %s appears!\n", enemy.name);
                combat(player, &enemy);
                break;
            }
        case 2:
            printf("You have no items in your inventory yet.\n");
            break;
        case 3:
            player->health += 10; // Regain health
            if (player->health > 100) player->health = 100;
            printf("%s rests and regains health.\n", player->name);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
}

int main() {
    srand(time(NULL));
    Player player;
    Inventory inventory = {{"Potion", "Antidote", "Elixir", "Bomb", "Shield"}, 5};

    initializePlayer(&player);
    while (player.health > 0) {
        explore(&player);
    }

    printf("Game Over!\n");
    return 0;
}