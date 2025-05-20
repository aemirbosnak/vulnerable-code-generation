//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50

typedef struct {
    char name[ITEM_NAME_LENGTH];
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
} Warehouse;

// Function declarations
void initializeWarehouse(Warehouse* warehouse);
void addItem(Warehouse* warehouse);
void removeItem(Warehouse* warehouse);
void displayInventory(const Warehouse* warehouse);
void surpriseInventoryCheck(Warehouse* warehouse);

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    
    int choice;
    do {
        printf("\n=== Warehouse Management System ===\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Inventory\n");
        printf("4. Surprise Inventory Check\n");
        printf("5. Exit\n");
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addItem(&warehouse);
                break;
            case 2:
                removeItem(&warehouse);
                break;
            case 3:
                displayInventory(&warehouse);
                break;
            case 4:
                surpriseInventoryCheck(&warehouse);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 5);
    
    return 0;
}

void initializeWarehouse(Warehouse* warehouse) {
    warehouse->itemCount = 0;
    printf("Warehouse initialized!\n");
}

void addItem(Warehouse* warehouse) {
    if (warehouse->itemCount >= MAX_ITEMS) {
        printf("Warehouse is at full capacity! Cannot add more items.\n");
        return;
    }
    
    Item newItem;
    printf("Enter the item name: ");
    scanf("%s", newItem.name);
    printf("Enter the quantity: ");
    scanf("%d", &newItem.quantity);
    
    warehouse->items[warehouse->itemCount] = newItem;
    warehouse->itemCount++;
    printf("Item \"%s\" added with quantity %d!\n", newItem.name, newItem.quantity);
}

void removeItem(Warehouse* warehouse) {
    char itemName[ITEM_NAME_LENGTH];
    printf("Enter the item name to remove: ");
    scanf("%s", itemName);
    
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, itemName) == 0) {
            printf("Removing item \"%s\" from inventory.\n", itemName);
            warehouse->items[i] = warehouse->items[warehouse->itemCount - 1]; // Replace with last item
            warehouse->itemCount--;
            return;
        }
    }
    printf("Item \"%s\" not found in inventory!\n", itemName);
}

void displayInventory(const Warehouse* warehouse) {
    if (warehouse->itemCount == 0) {
        printf("The warehouse is empty!\n");
        return;
    }
    
    printf("\n=== Current Inventory ===\n");
    for (int i = 0; i < warehouse->itemCount; i++) {
        printf("Item: %s, Quantity: %d\n", warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

void surpriseInventoryCheck(Warehouse* warehouse) {
    if (warehouse->itemCount == 0) {
        printf("Surprise check! The warehouse is empty!\n");
        return;
    }
    
    int randomIndex = rand() % warehouse->itemCount; // Get a random index
    Item randomItem = warehouse->items[randomIndex];
    
    printf("Surprise! Found item \"%s\" with quantity %d!\n", randomItem.name, randomItem.quantity);
}