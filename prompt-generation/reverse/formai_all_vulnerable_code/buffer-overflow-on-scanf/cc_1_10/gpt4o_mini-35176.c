//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INVENTORY 5

typedef struct {
    char name[50];
    int health;
    int stamina;
    int magic;
} Player;

typedef struct {
    char name[50];
    int dangerLevel;
} Monster;

typedef struct {
    char name[50];
    char description[250];
} Item;

Player player;
Monster monsters[] = {
    {"Goblin", 30},
    {"Wraith", 50},
    {"Dragon", 100},
};

Item inventory[MAX_INVENTORY];
int inventoryCount = 0;

void initializePlayer() {
    printf("Enter your character name: ");
    scanf("%s", player.name);
    player.health = 100;
    player.stamina = 50;
    player.magic = 25;
}

void addItemToInventory(Item item) {
    if(inventoryCount < MAX_INVENTORY) {
        inventory[inventoryCount] = item;
        inventoryCount++;
        printf("You have picked up: %s\n", item.name);
    } else {
        printf("Inventory full! Cannot pick up: %s\n", item.name);
    }
}

void showInventory() {
    printf("Your inventory:\n");
    for(int i = 0; i < inventoryCount; i++) {
        printf("%d. %s - %s\n", i + 1, inventory[i].name, inventory[i].description);
    }
}

void encounterMonster() {
    int monsterIndex = rand() % (sizeof(monsters) / sizeof(Monster));
    printf("Oh no! A wild %s appeared! Danger Level: %d\n", monsters[monsterIndex].name, monsters[monsterIndex].dangerLevel);

    while(player.health > 0 && monsters[monsterIndex].dangerLevel > 0) {
        printf("Choose an action: (A)ttack, (R)un, (I)nventory: ");
        char action;
        scanf(" %c", &action);

        if(action == 'A' || action == 'a') {
            int damageDealt = rand() % 20 + 1;
            monsters[monsterIndex].dangerLevel -= damageDealt;
            printf("You attack the %s for %d damage!\n", monsters[monsterIndex].name, damageDealt);
            if(monsters[monsterIndex].dangerLevel <= 0) {
                printf("You have defeated the %s!\n", monsters[monsterIndex].name);
                return;
            }
            int damageReceived = rand() % 15 + 1;
            player.health -= damageReceived;
            printf("The %s attacks back! You take %d damage. Your health: %d\n", monsters[monsterIndex].name, damageReceived, player.health);
        } else if(action == 'R' || action == 'r') {
            int escapeChance = rand() % 2;  // simple 50% chance to escape
            if(escapeChance) {
                printf("You successfully escaped from the %s!\n", monsters[monsterIndex].name);
                return;
            } else {
                int damageReceived = rand() % 15 + 1;
                player.health -= damageReceived;
                printf("Failed to escape! You take %d damage. Your health: %d\n", damageReceived, player.health);
            }
        } else if(action == 'I' || action == 'i') {
            showInventory();
        } else {
            printf("Invalid action!\n");
        }
    }
    
    if(player.health <= 0) {
        printf("You have been defeated...\n");
        exit(0);
    }
}

void findItem() {
    Item foundItem;
    strcpy(foundItem.name, "Healing Potion");
    strcpy(foundItem.description, "Restores 20 health points.");
    
    printf("You found a %s! It's a %s\n", foundItem.name, foundItem.description);
    addItemToInventory(foundItem);
}

int main() {
    srand(time(NULL));
    initializePlayer();

    while(1) {
        printf("\nWhat would you like to do? (E)xplore, (Q)uit: ");
        char choice;
        scanf(" %c", &choice);

        if(choice == 'E' || choice == 'e') {
            int explorationEvent = rand() % 3; // 0 - item, 1 - monster, 2 - nothing
            if(explorationEvent == 0) {
                findItem();
            } else if(explorationEvent == 1) {
                encounterMonster();
            } else {
                printf("You explore the area, but find nothing of interest...\n");
            }
        } else if(choice == 'Q' || choice == 'q') {
            printf("Thank you for playing! Goodbye, brave adventurer %s.\n", player.name);
            break;
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}