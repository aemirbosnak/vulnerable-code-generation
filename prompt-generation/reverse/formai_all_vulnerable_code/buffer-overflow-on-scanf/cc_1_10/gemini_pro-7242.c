//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: brave
// Hail to the brave coders who dare to venture beyond the ordinary!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our inventory, a trove of treasures waiting to be discovered
typedef struct {
    char name[100];     // Name of the product, a tapestry woven with words
    int quantity;       // Abundance in our coffers, a number that tells the tale
    float price;        // Value measured in the currency of the realm, a shimmering gold
} InventoryItem;

// Our inventory, a haven for our precious goods
InventoryItem inventory[100];  // A grand array, holding up to 100 treasures
int inventoryCount = 0;       // The number of treasures we hold dear, a count to guide our way

// Add a new treasure to our inventory, a tale of acquisition
void addItem(char *name, int quantity, float price) {
    strcpy(inventory[inventoryCount].name, name);
    inventory[inventoryCount].quantity = quantity;
    inventory[inventoryCount].price = price;
    inventoryCount++;
}

// Search for a treasure by its name, a quest for knowledge
InventoryItem *findItem(char *name) {
    for (int i = 0; i < inventoryCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            return &inventory[i];
        }
    }
    return NULL;
}

// Update the quantity of a treasure, a testament to our ever-changing fortunes
void updateQuantity(char *name, int newQuantity) {
    InventoryItem *item = findItem(name);
    if (item != NULL) {
        item->quantity = newQuantity;
    }
}

// Display our inventory, a glorious tapestry of our treasures
void displayInventory() {
    printf("Behold, our inventory, a tapestry of treasures!\n");
    for (int i = 0; i < inventoryCount; i++) {
        printf("%s: %d units @ %.2f gold\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

// The heart of our program, where the brave adventurer begins their quest
int main() {
    // Seed our inventory with a few treasures, a taste of the riches that await
    addItem("Golden Sword", 10, 100.0);
    addItem("Healing Potion", 20, 50.0);
    addItem("Chainmail Armor", 5, 200.0);
    addItem("Leather Boots", 15, 25.0);

    // Display our initial inventory, a beacon of our prosperity
    displayInventory();

    // A brave adventurer approaches, seeking a legendary treasure
    char itemName[100];
    int newQuantity;
    printf("Adventurer, what treasure do you seek?\n");
    scanf("%s", itemName);

    // Find the treasure the adventurer desires, a triumph of our inventory system
    InventoryItem *item = findItem(itemName);
    if (item != NULL) {
        printf("We have %d units of %s in stock.\n", item->quantity, item->name);

        // The adventurer wishes to update their stock, a twist in our tale
        printf("How many units do you wish to purchase?\n");
        scanf("%d", &newQuantity);
        updateQuantity(itemName, newQuantity);

        // Display the updated inventory, a testament to our ever-changing fortunes
        displayInventory();
    } else {
        printf("Alas, we do not have %s in our inventory.\n", itemName);
    }

    return 0;
}