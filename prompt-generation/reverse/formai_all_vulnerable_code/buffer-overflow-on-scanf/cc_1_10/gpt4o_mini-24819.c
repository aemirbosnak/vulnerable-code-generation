//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Warehouse;

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->count = 0;
}

void addItem(Warehouse *warehouse, int id, const char *name, int quantity) {
    if (warehouse->count < MAX_ITEMS) {
        warehouse->items[warehouse->count].id = id;
        strncpy(warehouse->items[warehouse->count].name, name, NAME_LENGTH);
        warehouse->items[warehouse->count].quantity = quantity;
        warehouse->count++;
        printf("Item '%s' added successfully.\n", name);
    } else {
        printf("Warehouse is full! Cannot add more items.\n");
    }
}

void removeItem(Warehouse *warehouse, int id) {
    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->count--;
            printf("Item with ID %d removed successfully.\n", id);
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void updateItemQuantity(Warehouse *warehouse, int id, int quantity) {
    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            warehouse->items[i].quantity = quantity;
            printf("Quantity of item '%s' updated to %d.\n", warehouse->items[i].name, quantity);
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void displayItems(const Warehouse *warehouse) {
    if (warehouse->count == 0) {
        printf("Warehouse is empty.\n");
        return;
    }
    
    printf("Items in Warehouse:\n");
    printf("ID\tName\t\tQuantity\n");
    printf("---------------------------------\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("%d\t%-15s\t%d\n", warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

void searchItem(const Warehouse *warehouse, int id) {
    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            printf("Item found: ID %d, Name: %s, Quantity: %d\n", warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity);
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);

    int choice, id, quantity;
    char name[NAME_LENGTH];

    do {
        printf("\n--- Warehouse Management System ---\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Update Item Quantity\n");
        printf("4. Display All Items\n");
        printf("5. Search Item\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Item ID: ");
                scanf("%d", &id);
                printf("Enter Item Name: ");
                scanf("%s", name);
                printf("Enter Item Quantity: ");
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
                printf("Enter New Quantity: ");
                scanf("%d", &quantity);
                updateItemQuantity(&warehouse, id, quantity);
                break;
            case 4:
                displayItems(&warehouse);
                break;
            case 5:
                printf("Enter Item ID to Search: ");
                scanf("%d", &id);
                searchItem(&warehouse, id);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}