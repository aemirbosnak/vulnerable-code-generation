//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Warehouse;

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->count = 0;
}

void addItem(Warehouse *warehouse) {
    if (warehouse->count >= MAX_ITEMS) {
        printf("Warehouse Full! Cannot add more items.\n");
        return;
    }

    Item newItem;
    newItem.id = warehouse->count + 1; // Automatically assign an ID
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);

    warehouse->items[warehouse->count] = newItem;
    warehouse->count++;
    printf("Item added: ID=%d, Name=%s, Quantity=%d\n", newItem.id, newItem.name, newItem.quantity);
}

void removeItem(Warehouse *warehouse) {
    int itemId;
    printf("Enter item ID to remove: ");
    scanf("%d", &itemId);

    if (itemId < 1 || itemId > warehouse->count) {
        printf("Invalid item ID!\n");
        return;
    }

    for (int i = itemId - 1; i < warehouse->count - 1; i++) {
        warehouse->items[i] = warehouse->items[i + 1];
    }
    warehouse->count--;
    printf("Item with ID %d removed successfully.\n", itemId);
}

void displayItems(const Warehouse *warehouse) {
    if (warehouse->count == 0) {
        printf("Warehouse is empty.\n");
        return;
    }

    printf("Warehouse Items:\n");
    printf("ID\tName\t\tQuantity\n");
    printf("-----------------------------------\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("%d\t%s\t\t%d\n", warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

void updateItemQuantity(Warehouse *warehouse) {
    int itemId, newQuantity;
    printf("Enter item ID to update: ");
    scanf("%d", &itemId);

    if (itemId < 1 || itemId > warehouse->count) {
        printf("Invalid item ID!\n");
        return;
    }

    printf("Enter new quantity for item %s (ID=%d): ", warehouse->items[itemId - 1].name, itemId);
    scanf("%d", &newQuantity);
    warehouse->items[itemId - 1].quantity = newQuantity;
    printf("Quantity updated successfully for item ID %d.\n", itemId);
}

void saveWarehouseState(const Warehouse *warehouse) {
    FILE *file = fopen("warehouse.dat", "wb");
    if (file == NULL) {
        printf("Unable to save warehouse data.\n");
        return;
    }
    fwrite(warehouse, sizeof(Warehouse), 1, file);
    fclose(file);
    printf("Warehouse data saved successfully.\n");
}

void loadWarehouseState(Warehouse *warehouse) {
    FILE *file = fopen("warehouse.dat", "rb");
    if (file == NULL) {
        printf("No saved warehouse data found.\n");
        return;
    }
    fread(warehouse, sizeof(Warehouse), 1, file);
    fclose(file);
    printf("Warehouse data loaded successfully. Items loaded: %d\n", warehouse->count);
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    loadWarehouseState(&warehouse);

    int choice;
    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Items\n");
        printf("4. Update Item Quantity\n");
        printf("5. Save Warehouse Data\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(&warehouse);
                break;
            case 2:
                removeItem(&warehouse);
                break;
            case 3:
                displayItems(&warehouse);
                break;
            case 4:
                updateItemQuantity(&warehouse);
                break;
            case 5:
                saveWarehouseState(&warehouse);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}