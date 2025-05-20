//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 5
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int damage;
    int healing;
} Item;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int health;
    Item inventory[MAX_ITEMS];
    int itemCount;
} Player;

void initPlayer(Player *player, const char *name) {
    strcpy(player->name, name);
    player->health = 100;
    player->itemCount = 0;
}

void addItemToInventory(Player *player, Item item) {
    if (player->itemCount < MAX_ITEMS) {
        player->inventory[player->itemCount++] = item;
        printf("You have acquired: %s\n", item.name);
    } else {
        printf("Your inventory is full! You cannot carry more items.\n");
    }
}

void displayInventory(Player *player) {
    printf("=== Inventory of %s ===\n", player->name);
    if (player->itemCount == 0) {
        printf("Your inventory is empty.\n");
        return;
    }
    for (int i = 0; i < player->itemCount; i++) {
        printf("Item %d: %s - Damage: %d, Healing: %d\n",
               i + 1, player->inventory[i].name,
               player->inventory[i].damage,
               player->inventory[i].healing);
    }
}

void encounter(Player *player) {
    // Simple encounter with a monster
    printf("A wild monster appears!\n");
    int monsterHealth = 50;
    int monsterDamage = 10;
    int action;
    
    while (monsterHealth > 0 && player->health > 0) {
        printf("Your health: %d | Monster health: %d\n", player->health, monsterHealth);
        printf("Choose an action: \n");
        printf("1. Attack\n");
        printf("2. Use Item\n");
        printf("3. Flee\n");
        printf("Enter your choice: ");
        scanf("%d", &action);

        switch (action) {
            case 1: // Attack
                printf("You attack the monster!\n");
                monsterHealth -= 20; // Fixed damage for simplicity
                if (monsterHealth > 0) {
                    printf("The monster retaliates!\n");
                    player->health -= monsterDamage;
                }
                break;

            case 2: // Use Item
                displayInventory(player);
                int itemIndex;
                printf("Choose an item to use (1-%d): ", player->itemCount);
                scanf("%d", &itemIndex);
                if (itemIndex < 1 || itemIndex > player->itemCount) {
                    printf("Invalid choice!\n");
                    break;
                }
                itemIndex--; // Adjust for 0-based index
                player->health += player->inventory[itemIndex].healing;
                printf("You used %s. Your health is now %d!\n",
                       player->inventory[itemIndex].name, player->health);
                break;

            case 3: // Flee
                printf("You fled from the battle!\n");
                return;

            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    if (player->health <= 0) {
        printf("You have been defeated!\n");
        exit(0);
    } else {
        printf("You defeated the monster!\n");
    }
}

void gameMenu(Player *player) {
    int choice;
    while (1) {
        printf("=== Adventure Menu ===\n");
        printf("1. Explore\n");
        printf("2. View Inventory\n");
        printf("3. Exit Game\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                encounter(player);
                break;
            case 2:
                displayInventory(player);
                break;
            case 3:
                printf("Exiting game. Farewell, %s!\n", player->name);
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    Player player;
    
    char name[MAX_NAME_LENGTH];
    printf("Enter your character's name: ");
    scanf("%s", name);
    
    initPlayer(&player, name);
    printf("Welcome to the Adventure, %s!\n", player.name);

    // Sample Items
    Item sword = {"Sword", 20, 0};
    Item healingPotion = {"Healing Potion", 0, 30};

    addItemToInventory(&player, sword);
    addItemToInventory(&player, healingPotion);
    
    gameMenu(&player);
    
    return 0;
}