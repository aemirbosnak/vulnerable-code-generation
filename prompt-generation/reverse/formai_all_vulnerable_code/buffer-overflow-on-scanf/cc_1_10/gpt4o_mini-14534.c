//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 10
#define MAX_DESC_LEN 256

// Define the items and their types
typedef struct {
    char name[MAX_DESC_LEN];
    int value;
    int isTreasure;
} Item;

// Define the player's structure
typedef struct {
    char name[MAX_DESC_LEN];
    int health;
    Item inventory[MAX_ITEMS];
    int inventoryCount;
} Player;

// Function prototypes
void printWelcome();
void printMenu();
void exploreCave(Player *player);
void collectTreasure(Player *player);
void encounterMonster(Player *player);
void printInventory(Player *player);
void clearBuffer();

int main() {
    Player player;
    player.health = 100;
    player.inventoryCount = 0;

    printWelcome();
    
    // Get player's name
    printf("Enter your character's name: ");
    fgets(player.name, MAX_DESC_LEN, stdin);
    player.name[strcspn(player.name, "\n")] = 0;  // Remove newline character
    
    // Start game loop
    while (player.health > 0) {
        printMenu();
        char choice[10];
        scanf("%s", choice);
        clearBuffer(); // Clear any extra input characters

        if (strcmp(choice, "1") == 0) {
            exploreCave(&player);
        } else if (strcmp(choice, "2") == 0) {
            printInventory(&player);
        } else if (strcmp(choice, "3") == 0) {
            printf("Goodbye, %s! Thanks for playing!\n", player.name);
            break;
        } else {
            printf("Invalid option, please try again.\n");
        }
    }

    if (player.health <= 0) {
        printf("You have succumbed to your wounds. Game Over!\n");
    }

    return 0;
}

void printWelcome() {
    printf("Welcome to The Mysterious Cave Adventure!\n");
    printf("You will explore the cave to find treasures and face monsters.\n");
    printf("Try to survive and collect as much treasure as possible!\n\n");
}

void printMenu() {
    printf("What would you like to do?\n");
    printf("1. Explore the cave\n");
    printf("2. Check inventory\n");
    printf("3. Exit game\n");
    printf("Enter your choice: ");
}

void exploreCave(Player *player) {
    srand(time(NULL));
    int event = rand() % 2;  // Randomly decide if there's treasure (0) or a monster (1)

    if (event == 0) {
        collectTreasure(player);
    } else {
        encounterMonster(player);
    }
}

void collectTreasure(Player *player) {
    if (player->inventoryCount >= MAX_ITEMS) {
        printf("Your inventory is full! You cannot collect more treasure.\n");
        return;
    }

    Item treasure;
    snprintf(treasure.name, MAX_DESC_LEN, "Gold Coin %d", player->inventoryCount + 1);
    treasure.value = rand() % 100 + 1; // Value between 1 and 100
    treasure.isTreasure = 1;

    player->inventory[player->inventoryCount] = treasure;
    player->inventoryCount++;

    printf("Congratulations! You found a %s worth %d coins!\n", treasure.name, treasure.value);
}

void encounterMonster(Player *player) {
    printf("Oh no! A monster has appeared!\n");
    printf("You have two options:\n");
    printf("1. Fight the monster\n");
    printf("2. Run away\n");
    
    char choice[10];
    scanf("%s", choice);
    clearBuffer();

    if (strcmp(choice, "1") == 0) {
        int damage = rand() % 20 + 5;  // Monster deals damage between 5 and 25
        player->health -= damage;
        printf("You fought bravely but suffered %d damage!\n", damage);
        printf("Your current health is: %d\n", player->health);
    } else if (strcmp(choice, "2") == 0) {
        printf("You ran away and escaped the monster!\n");
    } else {
        printf("Invalid option! The monster attacks you anyway!\n");
        int damage = rand() % 20 + 5;
        player->health -= damage;
        printf("You suffered %d damage while trying to escape!\n", damage);
        printf("Your current health is: %d\n", player->health);
    }
}

void printInventory(Player *player) {
    if (player->inventoryCount == 0) {
        printf("Your inventory is empty.\n");
        return;
    }

    printf("You have the following items in your inventory:\n");
    for (int i = 0; i < player->inventoryCount; i++) {
        printf("%d. %s (Value: %d coins)\n", i + 1, player->inventory[i].name, player->inventory[i].value);
    }
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}