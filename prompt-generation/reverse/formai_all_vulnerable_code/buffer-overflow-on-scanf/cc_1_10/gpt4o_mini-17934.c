//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
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

void addItem(Warehouse *warehouse, const char *name, int quantity) {
    if (warehouse->count < MAX_ITEMS) {
        strcpy(warehouse->items[warehouse->count].name, name);
        warehouse->items[warehouse->count].quantity = quantity;
        warehouse->count++;
        printf("Added: %s, Quantity: %d\n", name, quantity);
    } else {
        printf("Warehouse is full, cannot add more items.\n");
    }
}

void removeItem(Warehouse *warehouse, const char *name) {
    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            printf("Removed: %s, Quantity: %d\n", warehouse->items[i].name, warehouse->items[i].quantity);
            warehouse->items[i] = warehouse->items[warehouse->count - 1];
            warehouse->count--;
            return;
        }
    }
    printf("Item %s not found in warehouse.\n", name);
}

void listItems(const Warehouse *warehouse) {
    if (warehouse->count == 0) {
        printf("The warehouse is empty.\n");
        return;
    }
    printf("Items in Warehouse:\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("Item: %s, Quantity: %d\n", warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

void menu() {
    printf("\nWarehouse Management System\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. List Items\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    
    int choice;
    char name[NAME_LENGTH];
    int quantity;

    while (1) {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                addItem(&warehouse, name, quantity);
                break;
            case 2:
                printf("Enter item name to remove: ");
                scanf("%s", name);
                removeItem(&warehouse, name);
                break;
            case 3:
                listItems(&warehouse);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}