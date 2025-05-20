//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ITEMS 10
#define NAME_SIZE 20

typedef struct {
    char name[NAME_SIZE];
    int power;
    int health;
} Player;

typedef struct {
    char name[NAME_SIZE];
    int power;
} Item;

void initializePlayer(Player *player) {
    printf("Enter your character name: ");
    scanf("%s", player->name);
    player->power = 10;
    player->health = 100;
}

void initializeItems(Item items[], int itemCount) {
    const char *names[] = {"Sword", "Shield", "Magic Wand", "Potion", "Bow", "Dagger", "Armor", "Ring", "Amulet", "Staff"};
    
    for (int i = 0; i < itemCount; i++) {
        strcpy(items[i].name, names[i]);
        items[i].power = rand() % 20 + 1; // Random power between 1 and 20
    }
}

void displayItems(Item items[], int itemCount) {
    printf("Available Items:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s (Power: %d)\n", i + 1, items[i].name, items[i].power);
    }
}

void attack(Player *player, Player *enemy, Item equippedItem) {
    printf("%s attacks %s with %s!\n", player->name, enemy->name, equippedItem.name);
    enemy->health -= (player->power + equippedItem.power);
    printf("%s's health is now %d.\n", enemy->name, enemy->health);
}

void enemyAttack(Player *player, Player *enemy) {
    printf("%s attacks %s!\n", enemy->name, player->name);
    player->health -= enemy->power;
    printf("%s's health is now %d.\n", player->name, player->health);
}

int main() {
    srand(time(NULL));
    Player player, enemy;
    Item items[MAX_ITEMS];
    int playerChoice;

    // Initialize players
    initializePlayer(&player);
    strcpy(enemy.name, "Goblin");
    enemy.power = 8;
    enemy.health = 50;

    // Initialize items
    initializeItems(items, MAX_ITEMS);

    printf("\nWelcome to the Adventure Game!\n");
    printf("Your goal is to defeat the enemy and enhance your power through items!\n");

    while (player.health > 0 && enemy.health > 0) {
        // Display player and enemy status
        printf("\n--- Status ---\n");
        printf("%s - Health: %d | Power: %d\n", player.name, player.health, player.power);
        printf("%s - Health: %d | Power: %d\n", enemy.name, enemy.health, enemy.power);

        // Display available items
        displayItems(items, MAX_ITEMS);

        // Ask player to choose an item or attack
        printf("Choose an item to equip (1-%d) or 0 to attack: ", MAX_ITEMS);
        scanf("%d", &playerChoice);

        Item equippedItem = { .power = 0 };
        if (playerChoice >= 1 && playerChoice <= MAX_ITEMS) {
            equippedItem = items[playerChoice - 1];
            printf("You equipped %s.\n", equippedItem.name);
        } else if (playerChoice == 0) {
            equippedItem.power = 0; // No item used for attack
            printf("No item equipped.\n");
        } else {
            printf("Invalid choice! Try again.\n");
            continue; // Skip attack if invalid choice
        }

        // Player attacks enemy
        attack(&player, &enemy, equippedItem);

        // Check if enemy is defeated
        if (enemy.health <= 0) {
            printf("You defeated the %s!\n", enemy.name);
            break; // End of the game
        }

        // Enemy attacks back
        enemyAttack(&player, &enemy);

        // Check if player is defeated
        if (player.health <= 0) {
            printf("You have been defeated by the %s! Game Over.\n", enemy.name);
            break;
        }
    }
    
    printf("Thank you for playing!\n");
    return 0;
}