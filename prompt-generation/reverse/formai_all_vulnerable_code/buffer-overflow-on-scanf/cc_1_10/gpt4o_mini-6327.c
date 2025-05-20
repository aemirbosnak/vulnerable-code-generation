//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEALTH 100
#define MAX_ITEMS 5

typedef struct {
    char name[20];
    int health;
    int attack;
} Character;

typedef struct {
    char name[20];
    int health;
    int attack;
    int exp;
} Monster;

typedef struct {
    char name[20];
    int value;
} Item;

void displayCharacter(Character player) {
    printf("Player: %s\n", player.name);
    printf("Health: %d/%d\n", player.health, MAX_HEALTH);
    printf("Attack: %d\n", player.attack);
}

void displayMonster(Monster monster) {
    printf("Monster: %s\n", monster.name);
    printf("Health: %d\n", monster.health);
    printf("Attack: %d\n", monster.attack);
}

void battle(Character *player, Monster *monster) {
    printf("\n=== Battle Start ===\n");
    while (player->health > 0 && monster->health > 0) {
        monster->health -= player->attack;
        printf("%s attacks %s for %d damage!\n", player->name, monster->name, player->attack);
        
        if (monster->health <= 0) {
            printf("%s defeated %s!\n", player->name, monster->name);
            player->health += 20; // Heal 20 for winning
            printf("You gain 20 health!\n");
            return;
        }

        player->health -= monster->attack;
        printf("%s attacks %s for %d damage!\n", monster->name, player->name, monster->attack);
        printf("%s health: %d\n", player->name, player->health);
        
        if (player->health <= 0) {
            printf("You were defeated by %s...\n", monster->name);
            return;
        }
    }
}

void collectItem(Character player, Item items[], int *itemCount) {
    if (*itemCount < MAX_ITEMS) {
        Item item;
        snprintf(item.name, sizeof(item.name), "Potion %d", *itemCount + 1);
        item.value = 20; // Heal Value
        items[*itemCount] = item;
        (*itemCount)++;
        printf("You collected a %s!\n", item.name);
    } else {
        printf("Your inventory is full!\n");
    }
}

void showInventory(Item items[], int itemCount) {
    printf("\n=== Inventory ===\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s (Heal: %d)\n", i + 1, items[i].name, items[i].value);
    }
}

int main() {
    Character player;
    Monster monster;
    Item items[MAX_ITEMS];
    int itemCount = 0;
    int choice;

    // Initialize player
    printf("Enter your character name: ");
    scanf("%s", player.name);
    player.health = MAX_HEALTH;
    player.attack = 10;

    // Initialize random seed
    srand(time(NULL));

    // Initialize monster
    snprintf(monster.name, sizeof(monster.name), "Goblin");
    monster.health = 50;
    monster.attack = 5;

    while (1) {
        printf("\n=== Welcome to Mystical Adventure ===\n");
        displayCharacter(player);
        displayMonster(monster);
        printf("\n1. Fight Monster\n2. Collect Item\n3. Show Inventory\n4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                battle(&player, &monster);
                if (monster.health <= 0) {
                    printf("\nYou have defeated the monster!\n");
                    // Respawn monster with new health
                    monster.health = 50 + rand() % 50;
                    monster.attack = 5 + rand() % 5;
                }
                break;
            case 2:
                collectItem(player, items, &itemCount);
                break;
            case 3:
                showInventory(items, itemCount);
                break;
            case 4:
                printf("Thank you for playing!\n");
                return 0;
            default:
                printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}