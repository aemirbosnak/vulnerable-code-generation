//GPT-4o-mini DATASET v1.0 Category: Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INVENTORY 5
#define MAX_NAME_LENGTH 50
#define MAX_DESC_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESC_LENGTH];
} Item;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int health;
    Item inventory[MAX_INVENTORY];
    int inventoryCount;
} Player;

void printWelcomeMessage() {
    printf("Welcome to the Mystic Forest!\n");
    printf("Venture forth, brave soul, and discover the secrets hidden within.\n\n");
}

void createPlayer(Player* player) {
    printf("Enter your character's name: ");
    fgets(player->name, MAX_NAME_LENGTH, stdin);
    player->name[strcspn(player->name, "\n")] = 0; // Remove newline character
    player->health = 100;
    player->inventoryCount = 0;
    printf("Character %s created with %d health.\n\n", player->name, player->health);
}

void displayInventory(Player* player) {
    printf("Inventory of %s:\n", player->name);
    if (player->inventoryCount == 0) {
        printf("  Your inventory is empty.\n");
    } else {
        for (int i = 0; i < player->inventoryCount; i++) {
            printf("  - %s: %s\n", player->inventory[i].name, player->inventory[i].description);
        }
    }
    printf("\n");
}

void addItemToInventory(Player* player, Item item) {
    if (player->inventoryCount < MAX_INVENTORY) {
        player->inventory[player->inventoryCount++] = item;
        printf("You have acquired: %s\n\n", item.name);
    } else {
        printf("Your inventory is full! Cannot add %s.\n\n", item.name);
    }
}

void encounterCreature(Player* player) {
    const char* creatures[] = {"a friendly squirrel", "a curious deer", "a wise owl"};
    const char* actions[] = {"greet it", "feed it", "watch it"};

    srand(time(NULL));
    int creatureIndex = rand() % 3;
    int actionIndex = rand() % 3;

    printf("You have encountered %s!\n", creatures[creatureIndex]);
    printf("What will you do? You can choose to:\n");
    for (int i = 0; i < 3; i++) {
        printf(" - %s\n", actions[i]);
    }

    char choice[20];
    printf("Enter your action: ");
    fgets(choice, sizeof(choice), stdin);
    choice[strcspn(choice, "\n")] = 0; // Remove newline character

    printf("You decided to %s the creature.\n\n", choice);
}

void findItem(Player* player) {
    const char* itemNames[] = {"Ancient Scroll", "Golden Acorn", "Healing Potion"};
    const char* itemDescriptions[] = {
        "A scroll that contains ancient wisdom.",
        "A shiny acorn that glimmers with magic.",
        "A potion that restores health."
    };

    srand(time(NULL));
    int itemIndex = rand() % 3;

    Item newItem;
    strcpy(newItem.name, itemNames[itemIndex]);
    strcpy(newItem.description, itemDescriptions[itemIndex]);
    addItemToInventory(player, newItem);
}

void displayStatus(Player* player) {
    printf("Status of %s:\n", player->name);
    printf("  Health: %d\n", player->health);
    displayInventory(player);
}

int main() {
    Player player;
    printWelcomeMessage();
    createPlayer(&player);

    while (player.health > 0) {
        printf("You stand at a fork in the path.\n");
        printf("1. Wander deeper into the forest\n");
        printf("2. Check your status\n");
        printf("3. Exit the game\n");
        printf("Choose your action (1-3): ");

        int choice;
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                encounterCreature(&player);
                findItem(&player);
                break;
            case 2:
                displayStatus(&player);
                break;
            case 3:
                printf("Exiting the game. Goodbye, brave adventurer!\n");
                return 0;
            default:
                printf("Invalid choice. Please choose between 1 and 3.\n");
                break;
        }
    }

    printf("You have fallen in battle. The forest mourns your passing...\n");
    return 0;
}