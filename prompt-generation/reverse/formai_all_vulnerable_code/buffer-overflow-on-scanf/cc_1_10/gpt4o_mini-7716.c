//GPT-4o-mini DATASET v1.0 Category: Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INVENTORY 5
#define MAX_ENEMIES 3

typedef struct {
    char name[20];
    int health;
    int damage;
} Enemy;

typedef struct {
    char items[MAX_INVENTORY][20];
    int count;
} Inventory;

void startGame();
void displayStatus(int playerHealth, Inventory inventory);
void encounterEnemy(Enemy *enemy, int *playerHealth, Inventory *inventory);
void addItemToInventory(Inventory *inventory, const char *item);
void printInventory(Inventory inventory);
void generateRandomEnemy(Enemy *enemy);

int main() {
    srand(time(NULL)); // Seed for random number generation
    startGame();
    return 0;
}

void startGame() {
    int playerHealth = 100;
    Inventory inventory = {{0}, 0};
    char command[30];

    printf("Welcome to the Dungeon Adventure!\n");
    printf("You are a brave adventurer! Explore the dungeon, collect items, and fight enemies.\n");

    while (playerHealth > 0) {
        displayStatus(playerHealth, inventory);
        printf("What will you do? (explore / inventory / quit): ");
        scanf("%s", command);

        if (strcmp(command, "explore") == 0) {
            Enemy enemy;
            generateRandomEnemy(&enemy);
            encounterEnemy(&enemy, &playerHealth, &inventory);
        } else if (strcmp(command, "inventory") == 0) {
            printInventory(inventory);
        } else if (strcmp(command, "quit") == 0) {
            printf("Thanks for playing!\n");
            break;
        } else {
            printf("Invalid command! Try again.\n");
        }
    }

    if (playerHealth <= 0) {
        printf("You have perished in the dungeon. Game over!\n");
    }
}

void displayStatus(int playerHealth, Inventory inventory) {
    printf("\nPlayer Health: %d\n", playerHealth);
    printInventory(inventory);
}

void encounterEnemy(Enemy *enemy, int *playerHealth, Inventory *inventory) {
    printf("\nYou encountered a %s!\n", enemy->name);
    while (*playerHealth > 0 && enemy->health > 0) {
        char action[30];
        printf("Choose your action (attack / flee): ");
        scanf("%s", action);

        if (strcmp(action, "attack") == 0) {
            enemy->health -= 20; // Fixed damage
            printf("You attacked the %s! It has %d health left.\n", enemy->name, enemy->health);
            if (enemy->health > 0) {
                *playerHealth -= enemy->damage; // Enemy attacks back
                printf("The %s attacked you! Your health is now %d.\n", enemy->name, *playerHealth);
            }
        } else if (strcmp(action, "flee") == 0) {
            printf("You fled from the %s!\n", enemy->name);
            break;
        } else {
            printf("Invalid action!\n");
        }
    }

    if (enemy->health <= 0) {
        printf("You defeated the %s!\n", enemy->name);
        addItemToInventory(inventory, "Potion");
    }
}

void addItemToInventory(Inventory *inventory, const char *item) {
    if (inventory->count < MAX_INVENTORY) {
        strcpy(inventory->items[inventory->count], item);
        inventory->count++;
        printf("You found a %s and added it to your inventory!\n", item);
    } else {
        printf("Your inventory is full! You cannot carry more items.\n");
    }
}

void printInventory(Inventory inventory) {
    printf("\n=== Inventory ===\n");
    if (inventory.count == 0) {
        printf("Your inventory is empty.\n");
    } else {
        for (int i = 0; i < inventory.count; i++) {
            printf("%d: %s\n", i + 1, inventory.items[i]);
        }
    }
}

void generateRandomEnemy(Enemy *enemy) {
    const char *enemyNames[] = {"Goblin", "Troll", "Zombie"};
    int randomIndex = rand() % 3;
    strcpy(enemy->name, enemyNames[randomIndex]);
    enemy->health = 40 + rand() % 61; // Health between 40 and 100
    enemy->damage = 10 + rand() % 11;  // Damage between 10 and 20
}