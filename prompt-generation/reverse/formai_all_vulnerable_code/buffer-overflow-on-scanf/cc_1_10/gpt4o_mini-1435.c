//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    printf("The warehouse is as empty as the mind of a thief with no cunning.\n");
}

void addItem(Warehouse *warehouse, int id, const char *name, int quantity) {
    if (warehouse->count >= MAX_ITEMS) {
        printf("Alas! The warehouse is overflowing with unwelcome goods.\n");
        return;
    }
    warehouse->items[warehouse->count].id = id;
    strncpy(warehouse->items[warehouse->count].name, name, sizeof(warehouse->items[warehouse->count].name) - 1);
    warehouse->items[warehouse->count].quantity = quantity;
    warehouse->count++;
    printf("A new item, '%s', has been cunningly added to the inventory.\n", name);
}

void removeItem(Warehouse *warehouse, int id) {
    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            printf("The deceiving item '%s' has been removed from the stock!\n", warehouse->items[i].name);
            warehouse->items[i] = warehouse->items[warehouse->count - 1];
            warehouse->count--;
            return;
        }
    }
    printf("No item found with the id: %d. Perhaps it vanished like a shadow.\n", id);
}

void displayItems(Warehouse *warehouse) {
    if (warehouse->count == 0) {
        printf("The warehouse, much like an empty mind, holds nothing of interest.\n");
        return;
    }
    printf("Items in the Warehouse:\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("ID: %d, Name: %s, Quantity: %d\n", warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

void searchItem(Warehouse *warehouse, const char *name) {
    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            printf("Found! %s - Quantity: %d\n", warehouse->items[i].name, warehouse->items[i].quantity);
            return;
        }
    }
    printf("The elusive item '%s' escapes our grasp!\n", name);
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);

    int choice, id, quantity;
    char name[50];
    
    while (1) {
        printf("\nSherlock's Warehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Items\n");
        printf("4. Search Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item ID: ");
                scanf("%d", &id);
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter item quantity: ");
                scanf("%d", &quantity);
                addItem(&warehouse, id, name, quantity);
                break;
            
            case 2:
                printf("Enter item ID to remove: ");
                scanf("%d", &id);
                removeItem(&warehouse, id);
                break;

            case 3:
                displayItems(&warehouse);
                break;

            case 4:
                printf("Enter item name to search: ");
                scanf("%s", name);
                searchItem(&warehouse, name);
                break;
            
            case 5:
                printf("Exiting the realm of inventory management. Farewell!\n");
                exit(0);
                break;

            default:
                printf("Ah! A most perplexing choice. Try again, my dear Watson.\n");
        }
    }
    
    return 0;
}