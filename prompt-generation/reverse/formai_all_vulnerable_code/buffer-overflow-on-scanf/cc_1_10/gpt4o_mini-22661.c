//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: shocked
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
    printf("Warehouse Initialized! Ready to store items!\n");
}

void addItem(Warehouse *warehouse) {
    if (warehouse->count >= MAX_ITEMS) {
        printf("Shock! Warehouse is full! Cannot add more items.\n");
        return;
    }
    
    Item newItem;
    printf("Adding new item... Enter ID: ");
    scanf("%d", &newItem.id);
    printf("Enter Name: ");
    scanf("%s", newItem.name);
    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity);

    warehouse->items[warehouse->count] = newItem;
    warehouse->count++;
    printf("Item Added! ID: %d, Name: %s, Quantity: %d\n", newItem.id, newItem.name, newItem.quantity);
}

void displayItems(Warehouse *warehouse) {
    if (warehouse->count == 0) {
        printf("No items in warehouse! It's a shocker!\n");
        return;
    }
    
    printf("\n=== Items in Warehouse ===\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("ID: %d, Name: %s, Quantity: %d\n", warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

void updateItem(Warehouse *warehouse) {
    int id;
    printf("Enter the ID of the item to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            printf("Updating Item... Current Name: %s, Current Quantity: %d\n", warehouse->items[i].name, warehouse->items[i].quantity);
            printf("Enter new Name: ");
            scanf("%s", warehouse->items[i].name);
            printf("Enter new Quantity: ");
            scanf("%d", &warehouse->items[i].quantity);
            printf("Item Updated! ID: %d, New Name: %s, New Quantity: %d\n", id, warehouse->items[i].name, warehouse->items[i].quantity);
            return;
        }
    }
    
    printf("Item with ID %d not found! What a shock!\n", id);
}

void removeItem(Warehouse *warehouse) {
    int id;
    printf("Enter the ID of the item to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            printf("Removing Item... ID: %d, Name: %s, Quantity: %d\n", warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity);
            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->count--;
            printf("Item Removed! What a relief!\n");
            return;
        }
    }

    printf("Item with ID %d not found! Still shocking!\n", id);
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    int choice;

    while (1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Update Item\n");
        printf("4. Remove Item\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(&warehouse);
                break;
            case 2:
                displayItems(&warehouse);
                break;
            case 3:
                updateItem(&warehouse);
                break;
            case 4:
                removeItem(&warehouse);
                break;
            case 5:
                printf("Exiting... This is the end! Shock almost over!\n");
                exit(0);
            default:
                printf("Invalid option! Shocked by your choice!\n");
        }
    }

    return 0;
}