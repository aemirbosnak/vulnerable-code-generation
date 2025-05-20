//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 20
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    int value;
} Item;

void printInventory(Item inventory[], int itemCount) {
    printf("\n----- Your Inventory -----\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%s: %d (Value: %d)\n", inventory[i].name, inventory[i].quantity, inventory[i].value);
    }
    printf("--------------------------\n");
}

void searchForResources(Item inventory[], int *itemCount) {
    const char *possibleItems[] = {"Water", "Canned Food", "Medkit", "Ammo", "Rags", "Scrap Metal", "Batteries"};
    int foundItem = rand() % 7; // Randomly choose an item to be found
    int foundQuantity = rand() % 5 + 1; // Between 1 to 5 items

    // Check if the item already exists in the inventory
    int exists = 0;
    for (int i = 0; i < *itemCount; i++) {
        if (strcmp(inventory[i].name, possibleItems[foundItem]) == 0) {
            inventory[i].quantity += foundQuantity;
            exists = 1;
            printf("You found %d of %s!\n", foundQuantity, possibleItems[foundItem]);
        }
    }

    // Add new item to the inventory if it does not exist
    if (!exists && *itemCount < MAX_ITEMS) {
        strcpy(inventory[*itemCount].name, possibleItems[foundItem]);
        inventory[*itemCount].quantity = foundQuantity;
        inventory[*itemCount].value = rand() % 20 + 1; // Random value between 1 to 20
        (*itemCount)++;
        printf("You found %d of %s!\n", foundQuantity, possibleItems[foundItem]);
    }
}

void trade(Item inventory[], int *itemCount) {
    char itemName[NAME_LENGTH];
    int tradeQuantity;
    
    printf("Enter the name of the item you want to trade: ");
    scanf("%s", itemName);
    printf("Enter the quantity you want to trade: ");
    scanf("%d", &tradeQuantity);

    // Search for item to trade
    for (int i = 0; i < *itemCount; i++) {
        if (strcmp(inventory[i].name, itemName) == 0 && inventory[i].quantity >= tradeQuantity) {
            inventory[i].quantity -= tradeQuantity;
            printf("You traded %d of %s!\n", tradeQuantity, itemName);
            return;
        }
    }
    printf("You do not have enough %s to trade!\n", itemName);
}

void displayMenu() {
    printf("\n--- Post-Apocalyptic Scavenger ---\n");
    printf("1. Search for resources\n");
    printf("2. Trade items\n");
    printf("3. View inventory\n");
    printf("4. Exit\n");
    printf("---------------------------------\n");
    printf("Choose an option: ");
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    Item inventory[MAX_ITEMS];
    int itemCount = 0;
    int choice;

    // Game loop
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                searchForResources(inventory, &itemCount);
                break;
            case 2:
                trade(inventory, &itemCount);
                break;
            case 3:
                printInventory(inventory, itemCount);
                break;
            case 4:
                printf("Exiting the game. Stay safe out there!\n");
                exit(0);
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }

    return 0;
}