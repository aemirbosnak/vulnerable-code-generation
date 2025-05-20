//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    int max_quantity;
} Item;

Item inventory[MAX_ITEMS];
int itemCount = 0;

// Function to add an item to the inventory
void addItem(char *name, int quantity, int max_quantity) {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory is full! Cannot add more items.\n");
        return;
    }

    strcpy(inventory[itemCount].name, name);
    inventory[itemCount].quantity = quantity;
    inventory[itemCount].max_quantity = max_quantity;
    itemCount++;
    printf("Added %s (Quantity: %d, Max Quantity: %d) to the inventory.\n", name, quantity, max_quantity);
}

// Function to display the inventory
void displayInventory() {
    printf("\n===== Inventory =====\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%s - Quantity: %d / %d\n", inventory[i].name, inventory[i].quantity, inventory[i].max_quantity);
    }
    printf("=====================\n");
}

// Function to simulate scavenging for items
void scavengerHunt() {
    srand(time(NULL));
    char* itemList[5] = {"Nutrient Pack", "Water Bottle", "Scrap Metal", "First Aid Kit", "Power Cell"};
    int scavengedItem = rand() % 5;
    int quantity = rand() % 5 + 1; // Random quantity between 1 and 5

    printf("You found %d %s!\n", quantity, itemList[scavengedItem]);
    addItem(itemList[scavengedItem], quantity, 10); // Max quantity set to 10
}

// Function to use an item from the inventory
void useItem(char *name) {
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            if (inventory[i].quantity > 0) {
                inventory[i].quantity--;
                printf("Used 1 %s. Remaining: %d\n", name, inventory[i].quantity);
            } else {
                printf("No more %s left!\n", name);
            }
            return;
        }
    }
    printf("%s is not in the inventory!\n", name);
}

// Function to craft an item
void craftItem() {
    // Example crafting: 2 Nutrient Packs + 1 Water Bottle = 1 First Aid Kit
    int nutrientCount = 0;
    int waterCount = 0;

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, "Nutrient Pack") == 0) {
            nutrientCount = inventory[i].quantity;
        }
        if (strcmp(inventory[i].name, "Water Bottle") == 0) {
            waterCount = inventory[i].quantity;
        }
    }

    if (nutrientCount >= 2 && waterCount >= 1) {
        useItem("Nutrient Pack");
        useItem("Nutrient Pack");
        useItem("Water Bottle");
        addItem("First Aid Kit", 1, 5);
        printf("Crafted 1 First Aid Kit!\n");
    } else {
        printf("Not enough materials to craft a First Aid Kit.\n");
    }
}

// Main game loop
void gameLoop() {
    int choice;
    while (1) {
        printf("\nPost-Apocalyptic Scavenger Simulator\n");
        printf("1: Scavenge for Items\n");
        printf("2: Display Inventory\n");
        printf("3: Use Item\n");
        printf("4: Craft Item\n");
        printf("5: Exit\n");
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scavengerHunt();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                {
                    char itemName[MAX_NAME_LENGTH];
                    printf("Enter the name of the item to use: ");
                    scanf(" %[^\n]%*c", itemName); // Read string with spaces
                    useItem(itemName);
                }
                break;
            case 4:
                craftItem();
                break;
            case 5:
                printf("Exiting the game. Stay safe out there!\n");
                exit(0);
            default:
                printf("Invalid option! Please choose again.\n");
        }
    }
}

int main() {
    printf("Welcome to the Post-Apocalyptic World!\n");
    gameLoop();
    return 0;
}