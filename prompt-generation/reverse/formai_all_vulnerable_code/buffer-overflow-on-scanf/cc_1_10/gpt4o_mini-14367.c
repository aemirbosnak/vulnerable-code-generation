//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: future-proof
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
    int itemCount;
} Warehouse;

void initializeWarehouse(Warehouse* warehouse) {
    warehouse->itemCount = 0;
}

void addItem(Warehouse* warehouse, int id, const char* name, int quantity) {
    if (warehouse->itemCount >= MAX_ITEMS) {
        printf("Warehouse is full. Cannot add more items.\n");
        return;
    }
    warehouse->items[warehouse->itemCount].id = id;
    strncpy(warehouse->items[warehouse->itemCount].name, name, sizeof(warehouse->items[warehouse->itemCount].name) - 1);
    warehouse->items[warehouse->itemCount].quantity = quantity;
    warehouse->itemCount++;
    printf("Added Item: %s (ID: %d, Quantity: %d)\n", name, id, quantity);
}

void removeItem(Warehouse* warehouse, int id) {
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (warehouse->items[i].id == id) {
            printf("Removing Item: %s (ID: %d)\n", warehouse->items[i].name, id);
            warehouse->items[i] = warehouse->items[warehouse->itemCount - 1]; // Move last item into this spot
            warehouse->itemCount--;
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void updateItemQuantity(Warehouse* warehouse, int id, int quantity) {
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (warehouse->items[i].id == id) {
            warehouse->items[i].quantity += quantity;
            printf("Updated Item: %s (ID: %d, New Quantity: %d)\n", warehouse->items[i].name, id, warehouse->items[i].quantity);
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void displayItems(const Warehouse* warehouse) {
    if (warehouse->itemCount == 0) {
        printf("Warehouse is empty.\n");
        return;
    }
    printf("Items in Warehouse:\n");
    printf("ID\tName\t\tQuantity\n");
    for (int i = 0; i < warehouse->itemCount; i++) {
        printf("%d\t%-15s\t%d\n", warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);

    int choice, id, quantity;
    char name[50];

    while (1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Update Item Quantity\n");
        printf("4. Display All Items\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Item ID: ");
                scanf("%d", &id);
                printf("Enter Item Name: ");
                scanf("%s", name);
                printf("Enter Quantity: ");
                scanf("%d", &quantity);
                addItem(&warehouse, id, name, quantity);
                break;
            case 2:
                printf("Enter Item ID to Remove: ");
                scanf("%d", &id);
                removeItem(&warehouse, id);
                break;
            case 3:
                printf("Enter Item ID to Update: ");
                scanf("%d", &id);
                printf("Enter New Quantity (positive to add, negative to subtract): ");
                scanf("%d", &quantity);
                updateItemQuantity(&warehouse, id, quantity);
                break;
            case 4:
                displayItems(&warehouse);
                break;
            case 5:
                printf("Exiting Warehouse Management System.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}